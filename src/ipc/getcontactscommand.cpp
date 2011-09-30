#include <boost/algorithm/string.hpp>
#include "getcontactscommand.hpp"
#include "command.h"

using namespace boost;
using namespace Commands;

GetContactsCommand::GetContactsCommand(std::string responderIP)
    :BaseCommand("GetContacts",responderIP)
{
}

bool GetContactsCommand::Send()
{
    bool result;

    if(TwoWaySendCommand()) {
        vector<intStr> tempContacts = m_command->GetResultAsArray("Contact");

        for (size_t i = 0; i < tempContacts.size(); ++i) {
            string tempString = ((intStr)(tempContacts.at(i))).second;
            vector<string> strList;
            Split(strList, tempString, ",");

            Contact temp;
            temp.Name = strList[0];
            temp.IP = strList[1];

            m_contacts.push_back(temp);
        }

        result = true;
    }
    else {
        result = false;
    }

    return result;
}

std::vector<Contact> GetContactsCommand::GetContacts()
{
    return m_contacts;
}

void GetContactsCommand::Split(vector<string> &out_vec, const string &str, const string &sep) {
    split(out_vec, str, is_any_of(sep));
}

void GetContactsCommand::Split(vector<wstring> &out_vec, const wstring &str, const wstring &sep) {
    split(out_vec, str, is_any_of(sep));
}


