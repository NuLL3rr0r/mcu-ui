#ifndef HOME_HPP
#define HOME_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMMCUSettingsSMSTUNSettings;
}

class ControlConference::TMMCUSettingsSMSTUNSettings : public ControlConference::BaseWidget
{
public:
    TMMCUSettingsSMSTUNSettings(CgiRoot *cgi);
    ~TMMCUSettingsSMSTUNSettings();

protected:
    Wt::WWidget *Layout();
};


#endif /* HOME_HPP */


