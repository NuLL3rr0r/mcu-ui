#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_print.hpp"
#define VERSION "3.0.3"
#define UNICODE "utf-8"
#define GET_ENUM_STRING(n)  #n

using namespace rapidxml;
using namespace std;

namespace InterProcessCommunication {

class Command;
enum CommandType
{
    CommandType_Request,
    CommandType_Response
};

}

typedef pair<string,string> SS;
typedef pair<int,string> intStr;


class InterProcessCommunication::Command
{
public:
    Command(string command_name , InterProcessCommunication::CommandType commandType = CommandType_Request);
    Command();
private:
    xml_document<> _doc;
    xml_node<>* _root;
    xml_node<>* _argument;
    xml_node<>* _result;
    string _command_name;
    string _m_sender_name;
    InterProcessCommunication::CommandType m_commandType;
    std::map<string,string>  _properties;
public:

    virtual bool    SetSenderName(string sender);
    virtual string GetSenderName();


    virtual bool    AddArgument(string name, string value);
    virtual void    SetArgument(string name, string value, int position = 0, bool create_is_not_exist = true);
    virtual string  GetArgument(string name, int position = 0);
    virtual vector<intStr> GetArgumentAsArray(string name);
    virtual bool    RemoveArgument(string name, int position = 0);
    virtual bool SetAttribute(
        xml_document<>& doc,
        xml_node<>* node,
        const string& attributeName,
        const string& attributeValue,
        bool create_is_not_exist);
    virtual void    AddResult(string name, string value);
    virtual void    SetResult(string name, string value, int position = 0, bool create_is_not_exist = true);
    virtual string  GetResult(string name, int position = 0);
    virtual vector<intStr>  GetResultAsArray(string name);
    virtual bool    RemoveResult(string name, int position = 0);
    virtual bool    SetCommandName(string command_name);
    virtual bool    SetCommandType(InterProcessCommunication::CommandType commandType);
    virtual xml_node<>* FindNode(string name, string parent_name, int position=0);
    virtual string GetString();
    virtual string GetCommandName();
    InterProcessCommunication::CommandType GetCommandType();
    static Command*    Parse(string input_xml);
    static vector<SS> GetAllResult(string input_xml);
    static vector<SS> GetAllArgument(string input_xml);
    static string     GetCommandName(string input_xml);
    static InterProcessCommunication::CommandType GetCommandType(string input_xml);
};

#endif // COMMAND_H
