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
#include "tmusermanagement.hpp"
#include "tmusermanagementsmuserlog.hpp"
#include "tmusermanagementsmusers.hpp"


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

TMUserManagement::TMUserManagement(CgiRoot *cgi) : BaseWidget(cgi)
{
    this->clear();
    this->addWidget(Layout());
}


/**********************************
*    = Destructor =
**********************************/

TMUserManagement::~TMUserManagement()
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

WWidget *TMUserManagement::CUserLog()
{
    return new TMUserManagementSMUserLog(m_cgiRoot);
}

WWidget *TMUserManagement::CUsers()
{
    return new TMUserManagementSMUsers(m_cgiRoot);
}


/**********************************
*    = Base Class Overrides =
**********************************/

WWidget *TMUserManagement::Layout()
{
    Div *root = new Div("TMUserManagement");

    Div *dvSubMenu = new Div(root, "dvSubMenu");
    Div *dvContents = new Div(root, "dvContents");
    Div *dvSubMenuInner = new Div(dvSubMenu, "dvSubMenuInner");

    WStackedWidget *dvContentsInner = new WStackedWidget(dvContents);
    dvContentsInner->setId("dvContentsInner");

    WMenu *subMenu = new WMenu(dvContentsInner, Horizontal, dvSubMenuInner);
    subMenu->setRenderAsList(true);

    subMenu->addItem
            (m_lang->GetString("HML_USER_MANAGEMENT_USER_LOG"), CUserLog(), WMenuItem::PreLoading)->setPathComponent("");

    subMenu->addItem
            (m_lang->GetString("HML_USER_MANAGEMENT_USERS"), CUsers(), WMenuItem::PreLoading)->setPathComponent("");

    return root;
}


/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


