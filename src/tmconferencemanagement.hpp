#ifndef TMCONFERENCEMANAGEMENT_HPP
#define TMCONFERENCEMANAGEMENT_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMConferenceManagement;
}

class ControlConference::TMConferenceManagement : public ControlConference::BaseWidget
{
public:
    TMConferenceManagement(CgiRoot *cgi);
    ~TMConferenceManagement();

private:
    Wt::WWidget *CCreateConference();
    Wt::WWidget *CTemplates();
    Wt::WWidget *CConferenceList();
    Wt::WWidget *CTerminalManagement();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMCONFERENCEMANAGEMENT_HPP */
