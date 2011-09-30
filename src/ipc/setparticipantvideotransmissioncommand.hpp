#ifndef SETPARTICIPANTVIDEOSENDINGCOMMAND_HPP
#define SETPARTICIPANTVIDEOSENDINGCOMMAND_HPP

#include "basecommand.h"

namespace Commands
{
class SetParticipantVideoTransmissionCommand : public BaseCommand
{
public:
    SetParticipantVideoTransmissionCommand(std::string responderIP,
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

#endif // SETPARTICIPANTVIDEOSENDINGCOMMAND_HPP
