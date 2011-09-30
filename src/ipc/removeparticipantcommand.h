#ifndef REMOVEPARTICIPANTCOMMAND_H
#define REMOVEPARTICIPANTCOMMAND_H

#include <string>
#include "basecommand.h"

using namespace Commands;

namespace Commands
{
class RemoveParticipantCommand : public BaseCommand
{
public:
    RemoveParticipantCommand(std::string responderIP,
                  std::string participantAddress,
                  std::string conferenceName);
    bool Send();
private:
    std::string m_participantAddress;
    std::string m_conferenceName;
};
}

#endif // REMOVEPARTICIPANTCOMMAND_H
