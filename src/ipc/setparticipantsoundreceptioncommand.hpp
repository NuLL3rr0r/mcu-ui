#ifndef SETPARTICIPANTSOUNDRECEPTION_HPP
#define SETPARTICIPANTSOUNDRECEPTION_HPP

#include "basecommand.h"

namespace Commands
{
class SetParticipantSoundReceptionCommand : public BaseCommand
{
public:
    SetParticipantSoundReceptionCommand(std::string responderIP,
                                        std::string participantAddress,
                                        std::string conferenceName,
                                        bool enabled);
    bool Send();
private:
    std::string m_responderIP;
    std::string m_participantAddress;
    std::string m_conferenceName;
    bool m_enabled;
};
}

#endif // SETPARTICIPANTSOUNDRECEPTION_HPP
