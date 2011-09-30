#include "hangupparticipantcommand.h"
#include "command.h"

using namespace Commands;

HangUpParticipantCommand::HangUpParticipantCommand(std::string responderIP,
                                                   std::string participantAddress,
                                                   std::string conferenceName):
    BaseCommand("HangUpParticipant",responderIP)
{
    m_participantAddress = participantAddress;
    m_conferenceName = conferenceName;

    m_command->AddArgument("Address", m_participantAddress);
    m_command->AddArgument("ConferenceName", m_conferenceName);
}

bool HangUpParticipantCommand::Send()
{
    bool result;

    if (TwoWaySendCommand())
        result =  true;
    else
        result = false;

    return result;
}

