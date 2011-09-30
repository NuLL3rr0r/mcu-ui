#ifndef LANG_HPP
#define LANG_HPP


#include <memory>
#include <string>
#include "cgienv.hpp"

namespace ControlConference {
    class Lang;
}

class ControlConference::Lang
{
public:
    static const std::wstring REPLACE_KEY_TERMINAL_ID;

private:
    class Impl;
    std::shared_ptr<Impl> m_pimpl;
    
public:
    Lang(const CgiEnv::ELang &lang);
    
    std::wstring GetString(const char *stringId);
};


#endif /* LANG_HPP */

