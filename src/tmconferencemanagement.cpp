/**********************************
*    = Header File Inclusion =
**********************************/

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WMenu>
#include <Wt/WMenuItem>
#include <Wt/WText>
#include <Wt/WStackedWidget>
#include <Wt/WWidget>
#include "tmconferencemanagement.hpp"
#include "tmconferencemanagementsmconferencelist.hpp"
#include "tmconferencemanagementsmcreateconference.hpp"
#include "tmconferencemanagementsmtemplates.hpp"
#include "tmconferencemanagementsmterminalmanagement.hpp"


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

TMConferenceManagement::TMConferenceManagement(CgiRoot *cgi) : BaseWidget(cgi)
{
    this->clear();
    this->addWidget(Layout());
}


/**********************************
*    = Destructor =
**********************************/

TMConferenceManagement::~TMConferenceManagement()
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

WWidget *TMConferenceManagement::CCreateConference()
{
    return new TMConferenceManagementSMCreateConference(m_cgiRoot);
}

WWidget *TMConferenceManagement::CTemplates()
{
    return new TMConferenceManagementSMTemplates(m_cgiRoot);
}

WWidget *TMConferenceManagement::CConferenceList()
{
    return new TMConferenceManagementSMConferenceList(m_cgiRoot);
}

WWidget *TMConferenceManagement::CTerminalManagement()
{
    return new TMConferenceManagementSMTerminalManagement(m_cgiRoot);
}


/**********************************
*    = Base Class Overrides =
**********************************/

WWidget *TMConferenceManagement::Layout()
{
    Div *root = new Div("TMConferenceManagement");

    Div *dvSubMenu = new Div(root, "dvSubMenu");
    Div *dvContents = new Div(root, "dvContents");
    Div *dvSubMenuInner = new Div(dvSubMenu, "dvSubMenuInner");

    WStackedWidget *dvContentsInner = new WStackedWidget(dvContents);
    dvContentsInner->setId("dvContentsInner");

    WMenu *subMenu = new WMenu(dvContentsInner, Horizontal, dvSubMenuInner);
    subMenu->setRenderAsList(true);

    subMenu->addItem
            (m_lang->GetString("HML_CONFERENCE_MANAGEMENT_CREATE_CONFERENCE"), CCreateConference(), WMenuItem::PreLoading)->setPathComponent("");

    subMenu->addItem
            (m_lang->GetString("HML_CONFERENCE_MANAGEMENT_TEMPLATES"), CTemplates(), WMenuItem::PreLoading)->setPathComponent("");

    subMenu->addItem
            (m_lang->GetString("HML_CONFERENCE_MANAGEMENT_CONFERENCE_LIST"), CConferenceList(), WMenuItem::PreLoading)->setPathComponent("");

    subMenu->addItem
            (m_lang->GetString("HML_CONFERENCE_MANAGEMENT_TERMINAL_MANAGEMENT"), CTerminalManagement(), WMenuItem::PreLoading)->setPathComponent("");

    return root;
}


/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


