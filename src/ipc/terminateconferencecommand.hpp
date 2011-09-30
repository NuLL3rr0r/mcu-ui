#ifndef TERMINATECONFERENCECOMMAND_HPP
#define TERMINATECONFERENCECOMMAND_HPP

#include"basecommand.h"

namespace Commands
{
class TerminateConferenceCommand : public BaseCommand
{
public:
    TerminateConferenceCommand(std::string responderIP,
                               std::string conferenceName);
    bool Send();
private :
    std::string m_responderIP;
    std::string m_conferenceName;
};
}

#endif // TERMINATECONFERENCECOMMAND_HPP
