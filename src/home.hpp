#ifndef HOME_HPP
#define HOME_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class Home;
}

class ControlConference::Home : public ControlConference::BaseWidget
{
public:
    Home(CgiRoot *cgi);
    ~Home();

protected:
    Wt::WWidget *Layout();

private:
    void ExitPanel(Wt::WMenuItem *sender);

private:
    Wt::WWidget *CWelcome();
    Wt::WWidget *CSysMon();
    Wt::WWidget *CUserManagement();
    Wt::WWidget *CSystemSettings();
    Wt::WWidget *CMCUSettings();
    Wt::WWidget *CConferenceRooms();
    Wt::WWidget *CConferenceManagement();
    Wt::WWidget *CExit();
};


#endif /* HOME_HPP */

