#include "callparticipantcommand.h"
#include "command.h"

using namespace Commands;

CallParticipantCommand::CallParticipantCommand(std::string responderIP,
                                               std::string participantAddress,
                                               std::string conferenceName):
    BaseCommand("CallParticipant",responderIP)
{
    m_participantAddress = participantAddress;
    m_conferenceName = conferenceName;

    m_command->AddArgument("ConferenceName", m_conferenceName);
    m_command->AddArgument("Address", m_participantAddress);
}

bool CallParticipantCommand::Send()
{
    bool result;

    if (TwoWaySendCommand())
        result = true;
    else
        result = false;

    return result;
}

