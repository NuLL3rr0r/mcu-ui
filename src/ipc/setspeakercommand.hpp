#ifndef SETSPEAKERCOMMAND_HPP
#define SETSPEAKERCOMMAND_HPP

#include"basecommand.h"

namespace Commands
{
class SetSpeakerCommand : public BaseCommand
{
public:
    SetSpeakerCommand(std::string responderIP,
                      std::string participantAddress,
                      std::string conferenceName);
    bool Send();
private :
    std::string m_responderIP;
    std::string m_participantAddress;
    std::string m_conferenceName;
};
}

#endif // SETSPEAKERCOMMAND_HPP
