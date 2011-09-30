#ifndef SETCONFERENCELAYOUTCOMMAND_HPP
#define SETCONFERENCELAYOUTCOMMAND_HPP

#include"basecommand.h"

namespace Commands
{
class SetConferenceLayoutCommand : public BaseCommand
{
public:
    SetConferenceLayoutCommand(std::string responderIP,
                               std::string conferenceName,
                               int layout);
    bool Send();
private :
    std::string m_responderIP;
    std::string m_conferenceName;
    int m_layout;
};
}

#endif // SETCONFERENCELAYOUTCOMMAND_HPP
