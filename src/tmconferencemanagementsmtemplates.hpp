#ifndef TMCONFERENCEMANAGEMENTSMTEMPLATES_HPP
#define TMCONFERENCEMANAGEMENTSMTEMPLATES_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMConferenceManagementSMTemplates;
}

class ControlConference::TMConferenceManagementSMTemplates : public ControlConference::BaseWidget
{
public:
    TMConferenceManagementSMTemplates(CgiRoot *cgi);
    ~TMConferenceManagementSMTemplates();

private:

protected:
    Wt::WWidget *Layout();
};


#endif /* TMCONFERENCEMANAGEMENTSMTEMPLATES_HPP */


