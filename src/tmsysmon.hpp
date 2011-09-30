#ifndef TMSYSMON_HPP
#define TMSYSMON_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMSysMon;
}

class ControlConference::TMSysMon : public ControlConference::BaseWidget
{
public:
    TMSysMon(CgiRoot *cgi);
    ~TMSysMon();

private:
    Wt::WWidget *CGeneralInfo();
    Wt::WWidget *CSignalingInfo();
    Wt::WWidget *CCodecInfo();
    Wt::WWidget *CServicesInfo();
    Wt::WWidget *CDSPInfo();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMSYSMON_HPP */
