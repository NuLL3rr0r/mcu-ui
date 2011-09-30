#include "setparticipantvideoreceptioncommand.hpp"
#include "basecommand.h"
#include "command.h"

using namespace Commands;

SetParticipantVideoReceptionCommand::SetParticipantVideoReceptionCommand(std::string responderIP,
                                                                         std::string participantAddress,
                                                                         std::string conferenceName,
                                                                         bool enabled)
    : BaseCommand("SetParticipantVideoReception",responderIP)
{
    m_participantAddress = participantAddress;
    m_conferenceName = conferenceName ;
    m_enabled = enabled;

    m_command->AddArgument("Address", m_participantAddress);
    m_command->AddArgument("ConferenceName", m_conferenceName);
    m_command->AddArgument("Enabled", m_enabled ? "True" : "False");
}

bool SetParticipantVideoReceptionCommand::Send()
{
    bool result;

    if (TwoWaySendCommand())
        result = true;
    else
        result = false;

    return result;
}


