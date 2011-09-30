#ifndef ADDPARTICIPANTCOMMAND_H
#define ADDPARTICIPANTCOMMAND_H
#include "basecommand.h"
namespace Commands
{
class AddParticipantCommand : public BaseCommand
{
public:
    AddParticipantCommand(std::string responderIP,
                          std::string participantName,
                          std::string participantAddress,
                          std::string conferenceName);
    bool Send();
private:
    std::string m_responderIP;
    std::string m_participantName;
    std::string m_participantAddress;
    std::string m_conferenceName;
};
}

#endif // ADDPARTICIPANTCOMMAND_H
