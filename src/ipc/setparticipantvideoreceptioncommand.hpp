#ifndef SETPARTICIPANTVIDEORECEPTIONCOMMAND_HPP
#define SETPARTICIPANTVIDEORECEPTIONCOMMAND_HPP

#include "basecommand.h"

namespace Commands
{
class SetParticipantVideoReceptionCommand : public BaseCommand
{
public:
    SetParticipantVideoReceptionCommand(std::string responderIP,
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

#endif // SETPARTICIPANTVIDEORECEPTIONCOMMAND_HPP
