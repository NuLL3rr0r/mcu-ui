#include "setspeakercommand.hpp"
#include "command.h"

using namespace Commands;

SetSpeakerCommand::SetSpeakerCommand(std::string responderIP,
                                     std::string participantAddress,
                                     std::string conferenceName)
    :BaseCommand("SetAsSpeaker",responderIP)
{
    m_participantAddress = participantAddress;
    m_conferenceName = conferenceName;

    m_command->AddArgument("Address", m_participantAddress);
    m_command->AddArgument("ConferenceName", m_conferenceName);
}

bool SetSpeakerCommand::Send()
{
    bool result;

    if(TwoWaySendCommand())
        result = true;
    else
        result = false;

    return result;
}
