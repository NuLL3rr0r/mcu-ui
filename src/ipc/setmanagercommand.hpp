#ifndef SETMANAGERCOMMAND_HPP
#define SETMANAGERCOMMAND_HPP

#include"basecommand.h"

namespace Commands
{
class SetManagerCommand : public BaseCommand
{
public:
    SetManagerCommand(std::string responderIP,
                      std::string participantAddress,
                      std::string conferenceName);
    bool Send();
private :
    std::string m_responderIP;
    std::string m_participantAddress;
    std::string m_conferenceName;
};
}

#endif // SETMANAGERCOMMAND_HPP
