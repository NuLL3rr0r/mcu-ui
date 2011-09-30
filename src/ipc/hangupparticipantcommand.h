#ifndef HANGUPCOMMAND_H
#define HANGUPCOMMAND_H

#include <string>
#include "basecommand.h"

using namespace Commands;

namespace Commands
{
class HangUpParticipantCommand : public BaseCommand
{
public:
    HangUpParticipantCommand(std::string responderIP,
                             std::string participantAddress,
                             std::string conferenceName);
    bool Send();
private:
    std::string m_participantAddress;
    std::string m_conferenceName;
};
}

#endif // HANGUPCOMMAND_H
