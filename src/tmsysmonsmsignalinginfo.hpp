#ifndef TMSYSMONSMSIGNALINGINFO_HPP
#define TMSYSMONSMSIGNALINGINFO_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMSysMonSMSignalingInfo;
}

class ControlConference::TMSysMonSMSignalingInfo : public ControlConference::BaseWidget
{
public:
    TMSysMonSMSignalingInfo(CgiRoot *cgi);
    ~TMSysMonSMSignalingInfo();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMSYSMONSMSIGNALINGINFO_HPP */


