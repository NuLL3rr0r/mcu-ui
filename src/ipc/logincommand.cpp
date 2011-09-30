#include "logincommand.h"
#include "basecommand.h"
#include "command.h"
using namespace Commands;

LoginCommand::LoginCommand(std::string responderIP, std::string userName, std::string password)
    :BaseCommand("Login",responderIP)
{
    m_userName = userName;
    m_password = password;

    m_command->AddArgument("Username",m_userName);
    m_command->AddArgument("Password",m_password);

    m_IsValid = false;
}

bool LoginCommand::Send()
{
    bool result;

    if(TwoWaySendCommand())
    {
        string answer = m_command->GetResult("IsValidLogin");
        m_IsValid = (answer.find("True") != string::npos) ? true : false;

        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool LoginCommand::IsValid()
{
    return m_IsValid;
}
