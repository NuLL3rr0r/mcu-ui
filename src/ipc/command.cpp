#include "command.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstring>
#include <utility>
//#include "../Utility/utility.h"

using namespace std;
using namespace rapidxml;
using namespace InterProcessCommunication;


Command::Command(string commaned_name , CommandType commandType) :
    _command_name(commaned_name),
    m_commandType(commandType)
{
	_root = _doc.allocate_node(node_element, "Command");
	_argument = _doc.allocate_node(node_element, "Argument");
	_result = _doc.allocate_node(node_element, "Result");
	xml_node<>* decl = _doc.allocate_node(node_declaration);
	decl->append_attribute(_doc.allocate_attribute("version", "1.0"));
	decl->append_attribute(_doc.allocate_attribute("encoding", UNICODE));
	_root->append_attribute(_doc.allocate_attribute("Name", _command_name.c_str()));
    _root->append_attribute(_doc.allocate_attribute("Type", GET_ENUM_STRING(m_commandType)));
	_doc.append_node(decl);
	_doc.append_node(_root);
	_root->append_node(_argument);
	_root->append_node(_result);
}

Command::Command()
{

	xml_node<>* decl = _doc.allocate_node(node_declaration);
	decl->append_attribute(_doc.allocate_attribute("version", "1.0"));
	decl->append_attribute(_doc.allocate_attribute("encoding", UNICODE));
	_doc.append_node(decl);

}


bool    Command::SetSenderName(string sender)
{
    try
    {
        _m_sender_name = sender;
        xml_node<> *node = _doc.first_node("Command");
        node->append_attribute(_doc.allocate_attribute("UID", _m_sender_name.c_str()));
        return true;
    }
    catch(...)
    {
        return false;
    }
}

string Command::GetSenderName()
{
    xml_node<> *node = _doc.first_node("Command");
    _m_sender_name =  node->first_attribute("UID")->value();
    return _m_sender_name;
}


bool Command::AddArgument(string name, string value)
{
	xml_node<> * property = _doc.allocate_node(node_element, "Property");

	char* rapidAttributeName = _doc.allocate_string("Name");
	char* rapidAttributeValue = _doc.allocate_string(name.c_str());
	xml_attribute<> * attr = _doc.allocate_attribute(rapidAttributeName, rapidAttributeValue);
	property->append_attribute(attr);
	char* rapidAttributeNameA = _doc.allocate_string("Value");
	char* rapidAttributeValueA = _doc.allocate_string(value.c_str());
	xml_attribute<> * attrA = _doc.allocate_attribute(rapidAttributeNameA, rapidAttributeValueA);
	property->append_attribute(attrA);
	_argument->append_node(property);

	return true;
}

void Command::SetArgument(string name, string value, int position, bool create_is_not_exist)
{
    xml_node<>* node = FindNode(name, "Argument", position);
	char* rapidAttributeValue = _doc.allocate_string(value.c_str());
	if(node)
	{
		xml_attribute<>* attr = node->first_attribute("Value");
		attr->value(rapidAttributeValue);
	}
}


bool Command::SetAttribute(
    xml_document<>& doc, xml_node<>* node,
    const string& attributeName, const string& attributeValue, bool create_is_not_exist)
{
	char* rapidAttributeValue = doc.allocate_string(attributeValue.c_str());
	xml_attribute<>* attr = node->first_attribute(attributeName.c_str());
	if (attr != 0) {
		attr->value(rapidAttributeValue);
		return true;
	} else if(create_is_not_exist) {
		char* rapidAttributeName = doc.allocate_string(attributeName.c_str());
		attr = doc.allocate_attribute(rapidAttributeName, rapidAttributeValue);
		node->append_attribute(attr);
		return true;
	}
	return false;
}


string Command::GetArgument(string name, int position)
{
    xml_node<>* node = FindNode(name, "Argument", position);
	if(node)
	{
		xml_attribute<>* attr = node->first_attribute("Value");
		return attr->value();
	}
	else return "";
}


vector<intStr> Command::GetArgumentAsArray(string name)
{
    vector<intStr> result;
    string parent_name = "Argument";
    xml_node<> *node = _root->first_node(parent_name.c_str());
    xml_node<> *child = node->first_node();
    int pos = 0 ;
    for(; child; child = child->next_sibling())
    {
        xml_attribute<>* attr = child->first_attribute("Name");
        if(attr && string(attr->value())==name)
        {
            xml_attribute<>* attrB = child->first_attribute("Value");
            result.push_back(make_pair(pos, attrB->value()));
        }
        pos++;
    }
    return result;
}

vector<intStr> Command::GetResultAsArray(string name)
{
    vector<intStr> result;
    string parent_name = "Result";
    xml_node<> *node = _root->first_node(parent_name.c_str());
    xml_node<> *child = node->first_node();
    int pos = 0;
    for(; child; child = child->next_sibling())
    {
        xml_attribute<>* attr = child->first_attribute("Name");
        if(attr && string(attr->value())==name)
        {
            xml_attribute<>* attrB = child->first_attribute("Value");
            result.push_back(make_pair(pos, attrB->value()));
        }
        pos++;
    }
    return result;
}

bool Command::RemoveArgument(string name, int position)
{

	xml_node<> *node = _doc.first_node("Argument");
    xml_node<> *child = FindNode(name, "Argument", position);
	if(child)
	{
		node->remove_node(child);
		return true;
	}
	else
		return false;
}

xml_node<>* Command::FindNode(string name, string parent_name, int position)
{
	xml_node<> *node = _root->first_node(parent_name.c_str());
	xml_node<> *child = node->first_node();
    int pos = 0 ;
	for(; child; child = child->next_sibling())
	{
		xml_attribute<>* attr = child->first_attribute("Name");
		if(attr && string(attr->value())==name)
		{
            if(pos == position)
                return child;
            else
                pos++;
		}
	}
	return NULL;
}

string Command::GetString()
{
	string ss;
	rapidxml::print(std::back_inserter(ss),_doc,0);
        ss += '\0';
	return ss;
}


string Command::GetCommandName()
{
	xml_node<> *node = _doc.first_node("Command");
	return node->first_attribute("Name")->value();
}


CommandType Command::GetCommandType()
{
    xml_node<> *node = _doc.first_node("Command");
    string str =  node->first_attribute("Type")->value();
    if(str.find(GET_ENUM_STRING(CommandType_Request)) != string::npos)
    {
        return CommandType_Request;
    }
    else return CommandType_Response;
}



void Command::AddResult(string name, string value)
{
	xml_node<> * property = _doc.allocate_node(node_element, "Property");
	char* rapidAttributeName = _doc.allocate_string("Name");
	char* rapidAttributeValue = _doc.allocate_string(name.c_str());
	xml_attribute<> * attr = _doc.allocate_attribute(rapidAttributeName, rapidAttributeValue);
	property->append_attribute(attr);
	char* rapidAttributeNameA = _doc.allocate_string("Value");
	char* rapidAttributeValueA = _doc.allocate_string(value.c_str());
	xml_attribute<> * attrA = _doc.allocate_attribute(rapidAttributeNameA, rapidAttributeValueA);
	property->append_attribute(attrA);
	_result->append_node(property);
}

void Command::SetResult(string name, string value, int position, bool create_is_not_exist)
{

    xml_node<>* node = FindNode(name, "Result", position);
	char* rapidAttributeValue = _doc.allocate_string(value.c_str());
	if(node)
	{
		xml_attribute<>* attr = node->first_attribute("Value");
		attr->value(rapidAttributeValue);
	}
}




string Command::GetResult(string name, int position)
{
    xml_node<>* node = FindNode(name,"Result", position);
	if(node)
	{
		xml_attribute<>* attr = node->first_attribute("Value");
		return attr->value();
	}
	else return "";
}

bool Command::RemoveResult(string name, int position)
{
	xml_node<> *node = _doc.first_node("Result");
    xml_node<> *child = FindNode(name, "Result", position);
	if(child)
	{
		node->remove_node(child);
		return true;
	}
	else
		return false;
}

Command* Command::Parse(string input_xml)
{
	vector<SS> args = Command::GetAllArgument(input_xml);
	vector<SS> results = Command::GetAllResult(input_xml);
	string command_name = Command::GetCommandName(input_xml);
    CommandType commandType = Command::GetCommandType(input_xml);

    Command *command = new Command(command_name,commandType);

	for(size_t i = 0; i < args.size(); i++)
	{
		command->AddArgument(args.at(i).first,args.at(i).second);
	}
	for(size_t i = 0; i < results.size(); i++)
	{
		command->AddResult(results.at(i).first,results.at(i).second);
	}

	return command;

}


vector<SS> Command::GetAllArgument(string input_xml)
{
    //    DBG("GetAllArgument");

	vector<char> buffer(input_xml.begin(),input_xml.end());
	buffer.push_back('\0');
	vector<SS> result;
	xml_document<> doc;
	doc.parse<parse_declaration_node | parse_no_data_nodes | parse_validate_closing_tags>(&buffer[0]);
	xml_node<> *root = doc.first_node("Command");
	xml_node<> *args = root->first_node("Argument");
	if(args!=NULL)
	{
		xml_node<> *child = args->first_node();

		for(; child; child = child->next_sibling())
		{
			xml_attribute<>* attr = child->first_attribute("Name");
			xml_attribute<>* val  = child->first_attribute("Value");
			result.push_back(make_pair(attr->value(),val->value()));
		}
	}
	return result;

}

vector<SS>  Command::GetAllResult(string input_xml)
{
    //     DBG("GetAllResult");

	vector<char> buffer(input_xml.begin(),input_xml.end());
	buffer.push_back('\0');
	vector<SS> result;
	xml_document<> doc;
	doc.parse<parse_declaration_node | parse_no_data_nodes | parse_validate_closing_tags>(&buffer[0]);
	xml_node<> *root = doc.first_node("Command");
	xml_node<> *args = root->first_node("Result");

	xml_node<> *child = args->first_node();

	for(; child; child = child->next_sibling())
	{
		xml_attribute<>* attr = child->first_attribute("Name");
		xml_attribute<>* val  = child->first_attribute("Value");
		result.push_back(make_pair(attr->value(),val->value()));
	}
	return result;

}

string Command::GetCommandName(string input_xml)
{
    //    DBG("GetCommandName");

	vector<char> buffer(input_xml.begin(),input_xml.end());
	buffer.push_back('\0');
	xml_document<> doc;
	doc.parse<parse_declaration_node | parse_no_data_nodes | parse_validate_closing_tags>(&buffer[0]);
	xml_node<> *node = doc.first_node("Command");
	return node->first_attribute("Name")->value();

}


CommandType Command::GetCommandType(string input_xml)
{
    //    DBG("GetCommandName");

    vector<char> buffer(input_xml.begin(),input_xml.end());
    buffer.push_back('\0');
    xml_document<> doc;
    doc.parse<parse_declaration_node | parse_no_data_nodes | parse_validate_closing_tags>(&buffer[0]);
    xml_node<> *node = doc.first_node("Command");
    string str = node->first_attribute("Type")->value();
    if(str.find(
                GET_ENUM_STRING(CommandType_Request))
            != string::npos)
        return CommandType_Request;
    else return CommandType_Response;
}


bool Command::SetCommandName(string command_name)
{

	xml_node<> *node = _doc.first_node("Command");
	char* rapidAttributeValue = _doc.allocate_string(command_name.c_str());
	node->first_attribute("Name")->value(rapidAttributeValue);
	return true;

}


bool Command::SetCommandType(CommandType commandType)
{

    xml_node<> *node = _doc.first_node("Command");
    char* rapidAttributeValue = _doc.allocate_string(GET_ENUM_STRING(commandType));
    node->first_attribute("Type")->value(rapidAttributeValue);
    return true;

}

