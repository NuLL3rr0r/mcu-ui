#ifndef TMCONFERENCEMANAGEMENTSMCONFERENCELIST_HPP
#define TMCONFERENCEMANAGEMENTSMCONFERENCELIST_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMConferenceManagementSMConferenceList;
}

class ControlConference::TMConferenceManagementSMConferenceList : public ControlConference::BaseWidget
{
public:
    TMConferenceManagementSMConferenceList(CgiRoot *cgi);
    ~TMConferenceManagementSMConferenceList();

private:

protected:
    Wt::WWidget *Layout();
};


#endif /* TMCONFERENCEMANAGEMENTSMCONFERENCELIST_HPP */


