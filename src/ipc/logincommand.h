#ifndef LOGINCOMMAND_H
#define LOGINCOMMAND_H

#include <string>
#include"basecommand.h"

namespace Commands
{
class LoginCommand : public BaseCommand
{
public:
    LoginCommand(std::string responderIP, std::string userName, std::string password);
    bool IsValid();
    bool Send();

private :
    std::string m_userName;
    std::string m_password;
    bool m_IsValid;
};
}
#endif // LOGINCOMMAND_H
