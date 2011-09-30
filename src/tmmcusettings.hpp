#ifndef TMMCUSETTINGS_HPP
#define TMMCUSETTINGS_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMMCUSettings;
}

class ControlConference::TMMCUSettings : public ControlConference::BaseWidget
{
public:
    TMMCUSettings(CgiRoot *cgi);
    ~TMMCUSettings();

private:
    Wt::WWidget *CCodecSettings();
    Wt::WWidget *CSignalingSettings();
    Wt::WWidget *CSIPServerSettings();
    Wt::WWidget *CGakeKeeperSettings();
    Wt::WWidget *CSTUNSettings();
    Wt::WWidget *CDSPSettings();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMMCUSETTINGS_HPP */
