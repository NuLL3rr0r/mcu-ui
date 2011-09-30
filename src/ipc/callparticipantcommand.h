#ifndef CALLPARTICIPANTCOMMAND_H
#define CALLPARTICIPANTCOMMAND_H

#include "basecommand.h"

namespace Commands
{
class CallParticipantCommand : public BaseCommand
{
public:
    CallParticipantCommand(std::string responderIP,
                           std::string participantAddress,
                           std::string conferenceName);
    bool Send();
private:
    std::string m_participantAddress;
    std::string m_conferenceName;
};
}

#endif // CALLPARTICIPANTCOMMAND_H
