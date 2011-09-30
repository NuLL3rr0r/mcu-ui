#ifndef TMUSERMANAGEMENTSMUSERLOG_HPP
#define TMUSERMANAGEMENTSMUSERLOG_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMUserManagementSMUserLog;
}

class ControlConference::TMUserManagementSMUserLog : public ControlConference::BaseWidget
{
public:
    TMUserManagementSMUserLog(CgiRoot *cgi);
    ~TMUserManagementSMUserLog();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMUSERMANAGEMENTSMUSERLOG_HPP */


