#ifndef SYSTEM_HPP
#define SYSTEM_HPP


#include <string>

namespace ControlConference {
    class System;
}

class ControlConference::System
{
public:
    static std::size_t RandSeed();

    static bool Exec(const std::string &cmd);
    static std::string ExecCatchOutput(const std::string &cmd);

    static bool FileExists(const std::string &fileName);
    static std::size_t FileSize(const std::string &fileName);

    static void EraseFile(const std::string &fileName);

    static void ReadFile(const std::string &fileName, std::size_t &out_size, char **out_data);
    static void WriteFile(const std::string &fileName, const char *data);
};


#endif /* SYSTEM_HPP */

