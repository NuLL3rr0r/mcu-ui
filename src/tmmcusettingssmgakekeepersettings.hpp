#ifndef TMMCUSETTINGSSMGAKEKEEPERSETTINGS_HPP
#define TMMCUSETTINGSSMGAKEKEEPERSETTINGS_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMMCUSettingsSMGakeKeeperSettings;
}

class ControlConference::TMMCUSettingsSMGakeKeeperSettings : public ControlConference::BaseWidget
{
public:
    TMMCUSettingsSMGakeKeeperSettings(CgiRoot *cgi);
    ~TMMCUSettingsSMGakeKeeperSettings();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMMCUSETTINGSSMGAKEKEEPERSETTINGS_HPP */


