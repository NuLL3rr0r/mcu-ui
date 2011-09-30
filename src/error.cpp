#include <fstream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "error.hpp"

using namespace std;
using namespace boost;
using namespace ControlConference;

const string Error::LOG_FILE = "../log/error_log";

void Error::Log(const string &msg)
{
    static ofstream error;

    if(!error.is_open()) {
        error.open(LOG_FILE, ios_base::out | ios_base::app);
        error.imbue(locale(error.getloc(), new posix_time::time_facet()));
    }

    error << '[' << posix_time::second_clock::local_time() << "] " << msg << endl;
}


