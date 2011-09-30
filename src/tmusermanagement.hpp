#ifndef TMUSERMANAGEMENT_HPP
#define TMUSERMANAGEMENT_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMUserManagement;
}

class ControlConference::TMUserManagement : public ControlConference::BaseWidget
{
public:
    TMUserManagement(CgiRoot *cgi);
    ~TMUserManagement();

private:
    Wt::WWidget *CUserLog();
    Wt::WWidget *CUsers();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMUSERMANAGEMENT_HPP */
