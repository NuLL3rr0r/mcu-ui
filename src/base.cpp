/**********************************
*    = Header File Inclusion =
**********************************/

#include <ctime>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "base.hpp"


/**********************************
*    = PreProcessor Directives =
**********************************/


/**********************************
*    = Importing NameSpaces =
**********************************/

using namespace std;
using namespace boost;
using namespace ControlConference;


/**********************************
*    = Constants =
**********************************/

const string Base::ERR_TEMPLATE = "<div style=\"margin:33px;background-color:#FFFFFF;"
                                  "color:#990000;"
                                  "font-family:'Bitstream Vera Sans',arial,helvetica,sans-serif;"
                                  "font-weight:bold;font-size:13px;\">"
                                  "<h1>3RR0R!!</h1>"
                                  "<pre>{ERR}</pre>"
                                  "</div>";
                                  
const string Base::ERR_TEMPLATE_KEY = "{ERR}";

const string Base::ERR_UNKNOWN = "** Unknown Error!!";
const string Base::ERR_CRITICAL = GetErrFromTemplate("Internal Server Error! Contact your administrator, please.");

const string Base::REGEX_EMAIL = "[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,4}";
const string Base::REGEX_IP = "\\b(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b";
const string Base::REGEX_TIME = "^((([0]?[1-9]|1[0-2])(:)[0-5][0-9]((:)[0-5][0-9])?( )"
                                "?(AM|am|aM|Am|PM|pm|pM|Pm))|(([0]?[0-9]|1[0-9]|2[0-3])"
                                "(:)[0-5][0-9]((:)[0-5][0-9])?))$";

const size_t Base::MIN_USERNAME_LENGTH = 4;
const size_t Base::MAX_USERNAME_LENGTH = 16;
const size_t Base::MIN_PASSWORD_LENGTH = 8;
const size_t Base::MAX_PASSWORD_LENGTH = 16;

const size_t Base::TIME_INFO_BASE_YEAR = 1900;

const string Base::MCU_MANAGER_URL = "192.168.1.218:8087";


/**********************************
*    = Enumerations =
**********************************/

/**********************************
*    = Properties =
**********************************/

std::vector<std::string> RandIpcIdCollection;


/**********************************
*    = Fields =
**********************************/

/**********************************
*    = Constructors =
**********************************/

/**********************************
*    = Destructor =
**********************************/

/**********************************
*    = Public Methods =
**********************************/

const string Base::Copyright()
{
    time_t rawTime;
    time(&rawTime);
    struct tm *timeInfo = localtime(&rawTime);

    return "&copy; " + lexical_cast<string>(timeInfo->tm_year + TIME_INFO_BASE_YEAR)
            + " Hiva Rayan Co.";
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

std::string Base::GetErrFromTemplate(const std::string &err)
{
    std::string result(ERR_TEMPLATE);
    
    boost::algorithm::replace_all(result, ERR_TEMPLATE_KEY, err);
    
    return result;
}

std::wstring Base::GetErrFromTemplate(const std::wstring &err)
{
    std::wstring result(ERR_TEMPLATE.begin(), ERR_TEMPLATE.end());
    
    boost::algorithm::replace_all(result, ERR_TEMPLATE_KEY, err);
    
    return result;
}


/**********************************
*    = Debug Methods =
**********************************/


