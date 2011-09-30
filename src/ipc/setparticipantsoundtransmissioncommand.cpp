#include "setparticipantsoundtransmissioncommand.hpp"
#include "command.h"

using namespace Commands;

SetParticipantSoundTransmissionCommand::SetParticipantSoundTransmissionCommand(std::string responderIP,
                                                                               std::string participantAddress,
                                                                               std::string conferenceName,
                                                                               bool enabled)
    : BaseCommand("SetParticipantSoundTransmission",responderIP)
{
    m_participantAddress = participantAddress;
    m_conferenceName = conferenceName;
    m_enabled = enabled;

    m_command->AddArgument("Address", m_participantAddress);
    m_command->AddArgument("ConferenceName", m_conferenceName);
    m_command->AddArgument("Enabled", m_enabled ? "True" : "False");
}

bool SetParticipantSoundTransmissionCommand::Send()
{
    bool result;

    if (TwoWaySendCommand())
        result = true;
    else
        result = false;

    return result;
}
