#ifndef TMMCUSETTINGSSMCODECSETTINGS_HPP
#define TMMCUSETTINGSSMCODECSETTINGS_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMMCUSettingsSMCodecSettings;
}

class ControlConference::TMMCUSettingsSMCodecSettings : public ControlConference::BaseWidget
{
public:
    TMMCUSettingsSMCodecSettings(CgiRoot *cgi);
    ~TMMCUSettingsSMCodecSettings();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMMCUSETTINGSSMCODECSETTINGS_HPP */


