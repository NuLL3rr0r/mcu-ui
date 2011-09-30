#ifndef SETPATICIPANTVOLUME_H
#define SETPATICIPANTVOLUME_H

#include <string>
#include "basecommand.h"

using namespace Commands;

namespace Commands
{
class SetPaticipantVolumeCommand : public BaseCommand
{
public:
    SetPaticipantVolumeCommand(std::string responderIP,
                               std::string participantAddress,
                               std::string conferenceName,
                               std::string volume);
    bool Send();
private:
    std::string m_participantAddress;
    std::string m_conferenceName;
    std::string m_volume;
};
}

#endif // SETPATICIPANTVOLUME_H
