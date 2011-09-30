#ifndef TMMCUSETTINGSSMSIPSERVERSETTINGS_HPP
#define TMMCUSETTINGSSMSIPSERVERSETTINGS_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMMCUSettingsSMSIPServerSettings;
}

class ControlConference::TMMCUSettingsSMSIPServerSettings : public ControlConference::BaseWidget
{
public:
    TMMCUSettingsSMSIPServerSettings(CgiRoot *cgi);
    ~TMMCUSettingsSMSIPServerSettings();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMMCUSETTINGSSMSIPSERVERSETTINGS_HPP */


