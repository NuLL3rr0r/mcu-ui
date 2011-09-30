#include "addparticipanttoaddressbookcommand.hpp"
#include "command.h"

using namespace Commands;

AddParticipantToAddressBookCommand::AddParticipantToAddressBookCommand(std::string responderIP,
                                                                       std::string participantName,
                                                                       std::string participantAddress)
    :BaseCommand("AddParticipantToAddressBook",responderIP)
{
    m_participantName = participantName;
    m_participantAddress = participantAddress;

    m_command->AddArgument("Name", m_participantName);
    m_command->AddArgument("Address", m_participantAddress);
}

bool AddParticipantToAddressBookCommand::Send()
{
    bool result;

    if(TwoWaySendCommand())
        result = true;
    else
        result = false;

    return result;
}
