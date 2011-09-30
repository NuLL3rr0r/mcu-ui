#ifndef TMMCUSETTINGSSMDSPSETTINGS_HPP
#define TMMCUSETTINGSSMDSPSETTINGS_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMMCUSettingsSMDSPSettings;
}

class ControlConference::TMMCUSettingsSMDSPSettings : public ControlConference::BaseWidget
{
public:
    TMMCUSettingsSMDSPSettings(CgiRoot *cgi);
    ~TMMCUSettingsSMDSPSettings();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMMCUSETTINGSSMDSPSETTINGS_HPP */


