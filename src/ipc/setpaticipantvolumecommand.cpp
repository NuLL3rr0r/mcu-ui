#include "setpaticipantvolumecommand.h"
#include "command.h"

using namespace Commands;

SetPaticipantVolumeCommand::SetPaticipantVolumeCommand(std::string responderIP,
                                                       std::string participantAddress,
                                                       std::string conferenceName,
                                                       std::string volume):
    BaseCommand("SetParticipantVolume",responderIP)
{
    m_participantAddress = participantAddress;
    m_conferenceName = conferenceName;
    m_volume = volume;

    m_command->AddArgument("ConferenceName", m_conferenceName);
    m_command->AddArgument("Address", m_participantAddress);
    m_command->AddArgument("Volume", m_volume);
}

bool SetPaticipantVolumeCommand::Send()
{
    bool result;

    if (TwoWaySendCommand())
        result = true;
    else
        result = false;

    return result;
}

