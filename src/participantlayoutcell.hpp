#ifndef PARTICIPANTLAYOUTCELL_HPP
#define PARTICIPANTLAYOUTCELL_HPP


namespace Wt {
    class WContainerWidget;
    class WDropEvent;
    class WText;
}

namespace ControlConference {
    class ParticipantLayoutCell;
}

class ControlConference::ParticipantLayoutCell : public Wt::WContainerWidget
{
private:
    Wt::WText *m_text;

public:
    ParticipantLayoutCell();

protected:
    void dropEvent(Wt::WDropEvent event);
};


#endif /* PARTICIPANTLAYOUTCELL_HPP */

