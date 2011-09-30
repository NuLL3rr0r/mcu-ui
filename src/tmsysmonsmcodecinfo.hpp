#ifndef TMSYSMONSMCODECINFO_HPP
#define TMSYSMONSMCODECINFO_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMSysMonSMCodecInfo;
}

class ControlConference::TMSysMonSMCodecInfo : public ControlConference::BaseWidget
{
public:
    TMSysMonSMCodecInfo(CgiRoot *cgi);
    ~TMSysMonSMCodecInfo();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMSYSMONSMCODECINFO_HPP */


