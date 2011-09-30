/**********************************
*    = Header File Inclusion =
**********************************/

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WMenu>
#include <Wt/WMenuItem>
#include <Wt/WStackedWidget>
#include <Wt/WText>
#include "home.hpp"
#include "base.hpp"
#include "tmconferencemanagement.hpp"
#include "tmconferencerooms.hpp"
#include "tmmcusettings.hpp"
#include "tmsysmon.hpp"
#include "tmsystemsettings.hpp"
#include "tmusermanagement.hpp"
#include "tmwelcome.hpp"


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

Home::Home(CgiRoot *cgi) : BaseWidget(cgi)
{
    m_htmlRoot->clear();
    m_htmlRoot->addWidget(Layout());
}


/**********************************
*    = Destructor =
**********************************/

Home::~Home()
{
}


/**********************************
*    = Public Methods =
**********************************/

/**********************************
*    = Event Handlers =
**********************************/

void Home::ExitPanel(WMenuItem *sender)
{
    if (sender->text() == m_lang->GetString("HML_EXIT"))
        Exit("/");
}


/**********************************
*    = Protected Methods =
**********************************/

/**********************************
*    = Private Methods =
**********************************/

WWidget *Home::CWelcome()
{
    return new TMWelcome(m_cgiRoot);
}

WWidget *Home::CSysMon()
{
    return new TMSysMon(m_cgiRoot);
}

WWidget *Home::CUserManagement()
{
    return new TMUserManagement(m_cgiRoot);
}

WWidget *Home::CSystemSettings()
{
    return new TMSystemSettings(m_cgiRoot);
}

WWidget *Home::CMCUSettings()
{
    return new TMMCUSettings(m_cgiRoot);
}

WWidget *Home::CConferenceRooms()
{
    return new TMConferenceRooms(m_cgiRoot);
}

WWidget *Home::CConferenceManagement()
{
    return new TMConferenceManagement(m_cgiRoot);
}

WWidget *Home::CExit()
{
    return new WText("");
}


/**********************************
*    = Base Class Overrides =
**********************************/

WWidget *Home::Layout()
{
    Div *root = new Div("Home");

    m_cgiRoot->setTitle(m_lang->GetString("HOME_TITLE"));

    Div *dvBody = new Div(root, "dvBody");
    Div *dvTopMenu = new Div(dvBody, "dvTopMenu");

    WStackedWidget *dvBodyInner = new WStackedWidget(dvBody);
    dvBodyInner->setId("dvBodyInner");

    WMenu *topMenu = new WMenu(dvBodyInner, Horizontal, dvTopMenu);
    topMenu->setRenderAsList(true);

    topMenu->addItem
            (m_lang->GetString("HML_WELCOME"), CWelcome(), WMenuItem::PreLoading)->setPathComponent("");

    topMenu->addItem
            (m_lang->GetString("HML_SYSMON"), CSysMon(), WMenuItem::PreLoading)->setPathComponent("");

    topMenu->addItem
            (m_lang->GetString("HML_USER_MANAGEMENT"), CUserManagement(), WMenuItem::PreLoading)->setPathComponent("");

    topMenu->addItem
            (m_lang->GetString("HML_SYSTEM_SETTINGS"), CSystemSettings(), WMenuItem::PreLoading)->setPathComponent("");

    topMenu->addItem
            (m_lang->GetString("HML_MCU_SETTINGS"), CMCUSettings(), WMenuItem::PreLoading)->setPathComponent("");

    topMenu->addItem
            (m_lang->GetString("HML_CONFERENCE_ROOMS"), CConferenceRooms(), WMenuItem::PreLoading)->setPathComponent("");

    topMenu->addItem
            (m_lang->GetString("HML_CONFERENCE_MANAGEMENT"), CConferenceManagement(), WMenuItem::PreLoading)->setPathComponent("");

    topMenu->addItem
            (m_lang->GetString("HML_EXIT"), CExit(), WMenuItem::PreLoading)->setPathComponent("");
    topMenu->itemSelected().connect(this, &Home::ExitPanel);


    Div *dvCopyright = new Div(root, "dvCopyright");
    new WText(Base::Copyright(), dvCopyright);

    return root;
}


/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


