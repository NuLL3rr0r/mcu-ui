#ifndef TMSYSMONSMSERVICESINFO_HPP
#define TMSYSMONSMSERVICESINFO_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMSysMonSMServicesInfo;
}

class ControlConference::TMSysMonSMServicesInfo : public ControlConference::BaseWidget
{
public:
    TMSysMonSMServicesInfo(CgiRoot *cgi);
    ~TMSysMonSMServicesInfo();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMSYSMONSMSERVICESINFO_HPP */


