#ifndef SETPARTICIPANTSOUNDSENDINGCOMMAND_HPP
#define SETPARTICIPANTSOUNDSENDINGCOMMAND_HPP

#include "basecommand.h"

namespace Commands
{
class SetParticipantSoundTransmissionCommand : public BaseCommand
{
public:
    SetParticipantSoundTransmissionCommand(std::string responderIP,
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

#endif // SETPARTICIPANTSOUNDSENDINGCOMMAND_HPP
