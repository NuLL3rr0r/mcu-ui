#ifndef SETPARTICIPANTLAYOUTSLOTCOMMAND_HPP
#define SETPARTICIPANTLAYOUTSLOTCOMMAND_HPP

#include"basecommand.h"

namespace Commands
{
class SetParticipantLayoutSlotCommand : public BaseCommand
{
public:
    SetParticipantLayoutSlotCommand(std::string responderIP,
                                    std::string participantAddress,
                                    std::string conferenceName,
                                    int slotNumber);
    bool Send();
private :
    std::string m_responderIP;
    std::string m_participantAddress;
    std::string m_conferenceName;
    int m_slotNumber;
};
}

#endif // SETPARTICIPANTLAYOUTSLOTCOMMAND_HPP
