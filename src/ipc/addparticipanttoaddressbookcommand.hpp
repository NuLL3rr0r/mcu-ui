#ifndef ADDPARTICIPANTTOADDRESSBOOKCOMMAND_HPP
#define ADDPARTICIPANTTOADDRESSBOOKCOMMAND_HPP

#include"basecommand.h"

namespace Commands
{
class AddParticipantToAddressBookCommand : public BaseCommand
{
public:
    AddParticipantToAddressBookCommand(std::string responderIP,
                                       std::string participantName,
                                       std::string participantAddress);
    bool Send();
private :
    std::string m_responderIP;
    std::string m_participantName;
    std::string m_participantAddress;
};
}

#endif // ADDPARTICIPANTTOADDRESSBOOKCOMMAND_HPP
