/**********************************
*    = Header File Inclusion =
**********************************/

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WText>
#include <Wt/WWidget>
#include "tmsysmonsmsignalinginfo.hpp"


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

TMSysMonSMSignalingInfo::TMSysMonSMSignalingInfo(CgiRoot *cgi) : BaseWidget(cgi)
{
    this->clear();
    this->addWidget(Layout());
}


/**********************************
*    = Destructor =
**********************************/

TMSysMonSMSignalingInfo::~TMSysMonSMSignalingInfo()
{
}


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

WWidget *TMSysMonSMSignalingInfo::Layout()
{
    Div *root = new Div("TMSysMonSMSignalingInfo");

    new WText(m_lang->GetString("TEMPO_UNDER_CONSTRUCTION"), root);

    return root;
}


/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


