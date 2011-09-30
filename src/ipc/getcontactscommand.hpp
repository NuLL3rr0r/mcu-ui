#ifndef GETCONTACTSCOMMAND_HPP
#define GETCONTACTSCOMMAND_HPP

#include"basecommand.h"
#include <string>
#include <vector>

namespace Commands
{
struct Contact
{
    std::string Name;
    std::string IP;
};

class GetContactsCommand : public BaseCommand
{
public:
    GetContactsCommand(std::string responderIP);
    bool Send();
    std::vector<Contact> GetContacts();

private:
    std::string m_responderIP;
    std::vector<Contact> m_contacts;

public:
    static void Split(std::vector<std::string> &out_vec, const std::string &str, const std::string &sep);
    static void Split(std::vector<std::wstring> &out_vec, const std::wstring &str, const std::wstring &sep);
};
}

#endif // GETCONTACTSCOMMAND_HPP
