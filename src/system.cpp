/**********************************
*    = Header File Inclusion =
**********************************/

#include <fstream>
#include <cstdlib>
#include <sys/time.h>
#include "system.hpp"


/**********************************
*    = PreProcessor Directives =
**********************************/

/**********************************
*    = Importing NameSpaces =
**********************************/

using namespace std;
using namespace ControlConference;


/**********************************
*    = Constants =
**********************************/

/**********************************
*    = Enumerations =
**********************************/

/**********************************
*    = Properties =
**********************************/

/**********************************
*    = Fields =
**********************************/

/**********************************
*    = Constructos =
**********************************/

/**********************************
*    = Destructor =
**********************************/

/**********************************
*    = Public Methods =
**********************************/

size_t System::RandSeed()
{
    timespec ts;

    #if defined (__FreeBSD__)
        clock_gettime(CLOCK_MONOTONIC, &ts);
    #elif defined (__linux)
        clock_gettime(CLOCK_REALTIME, &ts);
    #endif

    return ts.tv_nsec;
}

bool System::Exec(const string &cmd)
{
    int r = system(cmd.c_str());
    if (r == 0)
        return true;
    else
        return false;
}

string System::ExecCatchOutput(const string &cmd)
{
    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe)
        return "3rr0r";

    char buffer[128];
    string result("");
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }

    pclose(pipe);
    return result;
}

bool System::FileExists(const string &fileName)
{
    ifstream file(fileName.c_str());
    if (file.good())
        return true;
    else
        return false;
}

size_t System::FileSize(const string &fileName)
{
    if (FileExists(fileName.c_str())) {
        ifstream::pos_type begin;
        ifstream::pos_type end;
        ifstream file(fileName.c_str());
        begin = file.tellg();
        file.seekg(0, ios::end);
        end = file.tellg();
        file.close();
        return static_cast<size_t>(end - begin);
    } else {
        return 0;
    }
}

void System::EraseFile(const string &fileName)
{
    if (FileExists(fileName.c_str())) {
        remove(fileName.c_str());
    }
}

void System::ReadFile(const string &fileName, size_t &out_size, char **out_data)
{
    char *buffer = NULL;
    out_size = 0;

    ifstream file(fileName.c_str(), ios::in | ios::binary | ios::ate);
    if (file.is_open()) {
        ifstream::pos_type size;

        size = file.tellg();
        buffer = new char[size];
        file.seekg(0, ios::beg);
        file.read(buffer, size);
        file.close();

        out_size = static_cast<size_t>(size);
        *out_data = buffer;
    }
}

void System::WriteFile(const string &fileName, const char *data)
{
    ofstream file(fileName.c_str(), ios::out | ios::trunc);
    if (file.is_open()) {
        file << data;
        file.close();
    }
}


/**********************************
*    = Event Handlers =
**********************************/

/**********************************
*    = Protected Methods =
**********************************/

/**********************************
*    = Private Methods =
**********************************/

/**********************************
*    = Base Class Overrides =
**********************************/

/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


