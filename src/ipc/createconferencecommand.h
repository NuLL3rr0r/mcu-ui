#ifndef CREATECONFERENCECOMMAND_H
#define CREATECONFERENCECOMMAND_H

#include "basecommand.h"

namespace Commands
{
class CreateConferenceCommand : public BaseCommand
{
public:
    CreateConferenceCommand(std::string responderIP,
                            std::string conferenceName,
//                            std::string videoIPAddress,
//                            std::string audioIPAddress,
//                            std::string audioPort,
//                            std::string videoPort,
                            std::string signalingType,
                            int capacity);
    bool Send();
private :
    std::string m_responderIP;
    std::string m_conferenceName;
    std::string m_videoIPAddress;
    std::string m_audioIPAddress;
    int m_audioPort;
    int m_videoPort;
    std::string m_signalingType;
    int m_capacity;
};
}

#endif // CREATECONFERENCECOMMAND_H
