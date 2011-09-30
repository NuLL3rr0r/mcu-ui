#ifndef BASECOMMAND_H
#define BASECOMMAND_H
#include <iostream>
#include <zmq.hpp>
#include <boost/thread/thread.hpp>

using namespace std;
namespace InterProcessCommunication
{
class Command;
}

namespace Commands
{
class BaseCommand
{
public:
    BaseCommand(std::string commandName, std::string responderIP);
    void SetCommand(InterProcessCommunication::Command* cmd);
    InterProcessCommunication::Command *GetCommand();
    bool OneWaySendCommand();
    bool TwoWaySendCommand();
    std::string GetResponderIP();
    void SetResponderIP(std::string responderIP);

protected :
    InterProcessCommunication::Command *m_command;
    std::string m_responderIP;
    std::string m_commandName;
};
}
#endif // BASECOMMAND_H
