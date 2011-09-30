#ifndef TMSYSMONSMDSPINFO_HPP
#define TMSYSMONSMDSPINFO_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMSysMonSMDSPInfo;
}

class ControlConference::TMSysMonSMDSPInfo : public ControlConference::BaseWidget
{
public:
    TMSysMonSMDSPInfo(CgiRoot *cgi);
    ~TMSysMonSMDSPInfo();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMSYSMONSMDSPINFO_HPP */


