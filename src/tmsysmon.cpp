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
#include "tmsysmon.hpp"
#include "tmsysmonsmcodecinfo.hpp"
#include "tmsysmonsmdspinfo.hpp"
#include "tmsysmonsmgeneralinfo.hpp"
#include "tmsysmonsmservicesinfo.hpp"
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

TMSysMon::TMSysMon(CgiRoot *cgi) : BaseWidget(cgi)
{
    this->clear();
    this->addWidget(Layout());
}


/**********************************
*    = Destructor =
**********************************/

TMSysMon::~TMSysMon()
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

WWidget *TMSysMon::CGeneralInfo()
{
    return new TMSysMonSMGeneralInfo(m_cgiRoot);
}

WWidget *TMSysMon::CSignalingInfo()
{
    return new TMSysMonSMSignalingInfo(m_cgiRoot);
}

WWidget *TMSysMon::CCodecInfo()
{
    return new TMSysMonSMCodecInfo(m_cgiRoot);
}

WWidget *TMSysMon::CServicesInfo()
{
    return new TMSysMonSMServicesInfo(m_cgiRoot);
}

WWidget *TMSysMon::CDSPInfo()
{
    return new TMSysMonSMDSPInfo(m_cgiRoot);
}


/**********************************
*    = Base Class Overrides =
**********************************/

WWidget *TMSysMon::Layout()
{
    Div *root = new Div("TMSysMon");

    Div *dvSubMenu = new Div(root, "dvSubMenu");
    Div *dvContents = new Div(root, "dvContents");
    Div *dvSubMenuInner = new Div(dvSubMenu, "dvSubMenuInner");

    WStackedWidget *dvContentsInner = new WStackedWidget(dvContents);
    dvContentsInner->setId("dvContentsInner");

    WMenu *subMenu = new WMenu(dvContentsInner, Horizontal, dvSubMenuInner);
    subMenu->setRenderAsList(true);

    subMenu->addItem
            (m_lang->GetString("HML_SYSMON_GENERAL_INFO"), CGeneralInfo(), WMenuItem::PreLoading)->setPathComponent("");

    subMenu->addItem
            (m_lang->GetString("HML_SYSMON_SIGNALING_INFO"), CSignalingInfo(), WMenuItem::PreLoading)->setPathComponent("");

    subMenu->addItem
            (m_lang->GetString("HML_SYSMON_CODEC_INFO"), CCodecInfo(), WMenuItem::PreLoading)->setPathComponent("");

    subMenu->addItem
            (m_lang->GetString("HML_SYSMON_SERVICES_INFO"), CServicesInfo(), WMenuItem::PreLoading)->setPathComponent("");

    subMenu->addItem
            (m_lang->GetString("HML_SYSMON_DSP_INFO"), CDSPInfo(), WMenuItem::PreLoading)->setPathComponent("");

    return root;
}


/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


