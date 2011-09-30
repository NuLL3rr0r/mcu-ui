#include "basecommand.h"
#include "command.h"
#include <zmq.hpp>
using namespace InterProcessCommunication;
using namespace Commands;

BaseCommand::BaseCommand(std::string commandName, std::string responderIP)
{
    m_commandName = commandName;
    m_command = new InterProcessCommunication::Command(m_commandName);
    m_responderIP = responderIP;
}

void BaseCommand::SetCommand(InterProcessCommunication::Command* cmd)
{
    delete m_command;
    m_command = 0 ;
    m_command = cmd;
}

void BaseCommand::SetResponderIP(std::string requesterIP)
{
    m_responderIP = requesterIP;
}

std::string BaseCommand::GetResponderIP()
{
    return m_responderIP;
}

Command *BaseCommand::GetCommand()
{
    return m_command;
}

bool BaseCommand::OneWaySendCommand()
{
    zmq::context_t context(1);
    zmq::socket_t requester(context, ZMQ_REQ);
    std::string requesterAddress = "tcp://" + m_responderIP;
    requester.connect(requesterAddress.c_str());
    std::string sendMessage = m_command->GetString();
    zmq::message_t message(sendMessage.size());
    memcpy(message.data(), sendMessage.data(), sendMessage.size());
    bool rc = requester.send(message);
    return rc;
}

bool BaseCommand::TwoWaySendCommand()
{
    zmq::context_t context(1);
    zmq::socket_t requester(context, ZMQ_REQ);
    std::string requesterAddress = "tcp://" + m_responderIP;
    requester.connect(requesterAddress.c_str());
    std::string sendMessage = m_command->GetString();
    zmq::message_t message(sendMessage.size());
    memcpy(message.data(), sendMessage.data(), sendMessage.size());
    bool rc = requester.send(message);
    if(rc == true)
    {
        zmq::message_t receivedMessage;
        requester.recv(&receivedMessage);
        std::string resultString = std::string(static_cast<char*>(receivedMessage.data()), receivedMessage.size());
        try
        {
            m_command = InterProcessCommunication::Command::Parse(resultString);
        }
        catch(...)
        {
            rc = false;
        }
    }
    return rc;
}
