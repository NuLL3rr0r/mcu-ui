#ifndef TMSYSTEMSETTINGS_HPP
#define TMSYSTEMSETTINGS_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMSystemSettings;
}

class ControlConference::TMSystemSettings : public ControlConference::BaseWidget
{
private:
    Wt::WText *m_sysDateTimeText;
    Wt::WDatePicker *m_sysDateDatePicker;
    Wt::WLineEdit *m_sysTimeLineEdit;

public:
    TMSystemSettings(CgiRoot *cgi);
    ~TMSystemSettings();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMSYSTEMSETTINGS_HPP */
