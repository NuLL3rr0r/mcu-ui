#include "createconferencecommand.h"
#include "command.h"
#include "boost/lexical_cast.hpp"

using namespace Commands;

CreateConferenceCommand::CreateConferenceCommand(std::string responderIP,
                                                 std::string conferenceName,
                                                 //                                                 std::string videoIPAddress,
                                                 //                                                 std::string audioIPAddress,
                                                 //                                                 std::string audioPort,
                                                 //                                                 std::string videoPort,
                                                 std::string signalingType,
                                                 int capacity
                                                 )
    :BaseCommand("CreateImmediateConference",responderIP)
{
    m_conferenceName = conferenceName;
    //    m_videoIPAddress = videoIPAddress;
    //    m_audioIPAddress = audioIPAddress;
    //    m_audioPort = audioPort;
    //    m_videoPort = videoPort;
    m_signalingType = signalingType;
    m_capacity = capacity;

    m_command->SetSenderName("Majid");
    m_command->AddArgument("Name",m_conferenceName);
    //    m_command->AddArgument("VideoIP", m_videoIPAddress);
    //    m_command->AddArgument("AudioIP", m_audioIPAddress);
    //    m_command->AddArgument("VideoPort", m_videoPort);
    //    m_command->AddArgument("AudioPort", m_audioPort);
    m_command->AddArgument("EndPointType", m_signalingType);
    m_command->AddArgument("MaxParticipants", boost::lexical_cast<std::string>(m_capacity));
}

bool CreateConferenceCommand::Send()
{
    bool result;

    if(TwoWaySendCommand())
        result = true;
    else
        result = false;

    return result;
}
