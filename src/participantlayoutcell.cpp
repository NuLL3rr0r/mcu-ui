/**********************************
*    = Header File Inclusion =
**********************************/

#include <string>
#include <Wt/WContainerWidget>
#include <Wt/WImage>
#include <Wt/WText>
#include "participantlayoutcell.hpp"


/**********************************
*    = PreProcessor Directives =
**********************************/

/**********************************
*    = Importing NameSpaces =
**********************************/

using namespace std;
using namespace Wt;
using namespace ControlConference;


/**********************************
*    = Constants =
**********************************/

/**********************************
*    = Enumerations =
**********************************/

/**********************************
*    = Properties =
**********************************/

/**********************************
*    = Fields =
**********************************/

/**********************************
*    = Constructos =
**********************************/

ParticipantLayoutCell::ParticipantLayoutCell() : WContainerWidget()
{
    setStyleClass("dvContinuousPresenceLayoutCell");
    acceptDrops("participant-icon", "participant-drop-site");
    
    m_text = new WText("No Pic", this);

    addWidget(m_text);
}


/**********************************
*    = Destructor =
**********************************/

/**********************************
*    = Public Methods =
**********************************/

/**********************************
*    = Event Handlers =
**********************************/

/**********************************
*    = Protected Methods =
**********************************/

/**********************************
*    = Private Methods =
**********************************/

/**********************************
*    = Base Class Overrides =
**********************************/

void ParticipantLayoutCell::dropEvent(WDropEvent event)
{
    if (event.mimeType() == "participant-icon") {
        WImage *participant = reinterpret_cast<WImage *>(event.source());
        m_text->setText(participant->attributeValue("name"));
    }
}


/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


