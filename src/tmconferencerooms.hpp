#ifndef TMCONFERENCEROOMS_HPP
#define TMCONFERENCEROOMS_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class TMConferenceRooms;
}

class ControlConference::TMConferenceRooms : public ControlConference::BaseWidget
{
private:
    class Impl;
    std::shared_ptr<Impl> m_pimpl;
 
public:
    TMConferenceRooms(CgiRoot *cgi);
    ~TMConferenceRooms();

protected:
    Wt::WWidget *Layout();
};


#endif /* TMCONFERENCEROOMS_HPP */
