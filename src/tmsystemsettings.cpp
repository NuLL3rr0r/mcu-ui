/**********************************
*    = Header File Inclusion =
**********************************/

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WMenuItem>
#include <Wt/WStackedWidget>
#include <Wt/WText>
#include <Wt/WWidget>
#include "tmsystemsettings.hpp"


/**********************************
*    = PreProcessor Directives =
**********************************/

using namespace std;
using namespace Wt;
using namespace ControlConference;


/**********************************
*    = Importing NameSpaces =
**********************************/

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

TMSystemSettings::TMSystemSettings(CgiRoot *cgi) : BaseWidget(cgi)
{
    this->clear();
    this->addWidget(Layout());
}


/**********************************
*    = Destructor =
**********************************/

TMSystemSettings::~TMSystemSettings()
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

WWidget *TMSystemSettings::Layout()
{
    Div *root = new Div("TMSystemSettings");

    Div *dvContents = new Div(root, "dvContents");
    WStackedWidget *dvContentsInner = new WStackedWidget(dvContents);
    dvContentsInner->setId("dvContentsInner");

    Div *dvCurSysTimeDate = new Div(dvContentsInner, "dvCurSysTimeDate");

    new WText(L"<h4>" + m_lang->GetString("SYS_SETTINGS_CURRENT_DATE_TIME_TITLE")
              + L"</h4>", dvCurSysTimeDate);

    new WText(m_lang->GetString("TEMPO_UNDER_CONSTRUCTION"), dvCurSysTimeDate);

    return root;
}


/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


