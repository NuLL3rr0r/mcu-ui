#ifndef TMUSERMANAGEMENTSMUSERS_HPP
#define TMUSERMANAGEMENTSMUSERS_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMUserManagementSMUsers;
}

class ControlConference::TMUserManagementSMUsers : public ControlConference::BaseWidget
{
public:
    TMUserManagementSMUsers(CgiRoot *cgi);
    ~TMUserManagementSMUsers();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMUSERMANAGEMENTSMUSERS_HPP */


