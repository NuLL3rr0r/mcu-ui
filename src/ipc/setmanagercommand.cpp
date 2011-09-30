#include "setmanagercommand.hpp"
#include "command.h"

using namespace Commands;

SetManagerCommand::SetManagerCommand(std::string responderIP,
                                     std::string participantAddress,
                                     std::string conferenceName)
    :BaseCommand("SetAsManager",responderIP)
{
    m_participantAddress = participantAddress;
    m_conferenceName = conferenceName;

    m_command->AddArgument("conferenceName", m_conferenceName);
    m_command->AddArgument("ParticipantAddress", m_participantAddress);
}

bool SetManagerCommand::Send()
{
    bool result;

    if (TwoWaySendCommand())
        result = true;
    else
        result = false;

    return result;
}

