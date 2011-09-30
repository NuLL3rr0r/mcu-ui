#ifndef TMCONFERENCEMANAGEMENTSMTERMINALMANAGEMENT_HPP
#define TMCONFERENCEMANAGEMENTSMTERMINALMANAGEMENT_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMConferenceManagementSMTerminalManagement;
}

class ControlConference::TMConferenceManagementSMTerminalManagement : public ControlConference::BaseWidget
{
public:
    TMConferenceManagementSMTerminalManagement(CgiRoot *cgi);
    ~TMConferenceManagementSMTerminalManagement();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMCONFERENCEMANAGEMENTSMTERMINALMANAGEMENT_HPP */


