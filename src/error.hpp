#ifndef ERROR_HPP
#define ERROR_HPP


#include <string>

namespace ControlConference {
    class Error;
}

class ControlConference::Error
{
private:
    static const std::string LOG_FILE;

public:
    static void Log(const std::string &msg);
};


#endif /* ERROR_HPP */


