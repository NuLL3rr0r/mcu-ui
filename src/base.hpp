#ifndef BASE_HPP
#define BASE_HPP


#include <string>
#include <string>

namespace ControlConference {
    class Base;
}

class ControlConference::Base
{
public:
    static const std::string ERR_UNKNOWN;
    static const std::string ERR_CRITICAL;
    
    static const std::string REGEX_EMAIL;
    static const std::string REGEX_IP;
    static const std::string REGEX_TIME;
    
    static const std::size_t MIN_USERNAME_LENGTH;
    static const std::size_t MAX_USERNAME_LENGTH;
    static const std::size_t MIN_PASSWORD_LENGTH;
    static const std::size_t MAX_PASSWORD_LENGTH;

    static const std::string MCU_MANAGER_URL;

private:
    static const std::string ERR_TEMPLATE;
    static const std::string ERR_TEMPLATE_KEY;

    static const std::size_t TIME_INFO_BASE_YEAR;

public:
    static std::vector<std::string> RandIpcIdCollection;

public:
    static const std::string Copyright();

private:
    static std::string GetErrFromTemplate(const std::string &err);
    static std::wstring GetErrFromTemplate(const std::wstring &err);
};


#endif /* BASE_HPP */

