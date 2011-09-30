#ifndef TMMCUSETTINGSSMSIGNALINGSETTINGS_HPP
#define TMMCUSETTINGSSMSIGNALINGSETTINGS_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMMCUSettingsSMSignalingSettings;
}

class ControlConference::TMMCUSettingsSMSignalingSettings : public ControlConference::BaseWidget
{
public:
    TMMCUSettingsSMSignalingSettings(CgiRoot *cgi);
    ~TMMCUSettingsSMSignalingSettings();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMMCUSETTINGSSMSIGNALINGSETTINGS_HPP */


