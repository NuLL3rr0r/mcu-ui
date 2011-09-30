#ifndef TMWELCOME_HPP
#define TMWELCOME_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMWelcome;
}

class ControlConference::TMWelcome : public ControlConference::BaseWidget
{
private:
    class Impl;
    std::shared_ptr<Impl> m_pimpl;
 
public:
    TMWelcome(CgiRoot *cgi);
    ~TMWelcome();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMWELCOME_HPP */

