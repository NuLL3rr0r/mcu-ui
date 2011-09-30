#include "addparticipantcommand.h"
#include "command.h"
using namespace Commands;

AddParticipantCommand::AddParticipantCommand(std::string responderIP,
                                             std::string participantName,
                                             std::string participantAddress,
                                             std::string conferenceName)
    :BaseCommand("AddParticipant",responderIP)
{
    m_participantName = participantName;
    m_participantAddress = participantAddress;
    m_conferenceName = conferenceName ;

    m_command->AddArgument("Name", m_participantName);
    m_command->AddArgument("Address", m_participantAddress);
    m_command->AddArgument("ConferenceName", m_conferenceName);
}

bool AddParticipantCommand::Send()
{
    bool result;

    if (TwoWaySendCommand())
        result = true;
    else
        result = false;

    return result;
}
