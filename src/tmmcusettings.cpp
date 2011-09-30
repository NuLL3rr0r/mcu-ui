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
#include "tmmcusettings.hpp"
#include "tmmcusettingssmcodecsettings.hpp"
#include "tmmcusettingssmdspsettings.hpp"
#include "tmmcusettingssmgakekeepersettings.hpp"
#include "tmmcusettingssmsignalingsettings.hpp"
#include "tmmcusettingssmsipserversettings.hpp"
#include "tmmcusettingssmstunsettings.hpp"


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

TMMCUSettings::TMMCUSettings(CgiRoot *cgi) : BaseWidget(cgi)
{
    this->clear();
    this->addWidget(Layout());
}


/**********************************
*    = Destructor =
**********************************/

TMMCUSettings::~TMMCUSettings()
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

WWidget *TMMCUSettings::CCodecSettings()
{
    return new TMMCUSettingsSMCodecSettings(m_cgiRoot);
}

WWidget *TMMCUSettings::CSignalingSettings()
{
    return new TMMCUSettingsSMSignalingSettings(m_cgiRoot);
}

WWidget *TMMCUSettings::CSIPServerSettings()
{
    return new TMMCUSettingsSMSIPServerSettings(m_cgiRoot);
}

WWidget *TMMCUSettings::CGakeKeeperSettings()
{
    return new TMMCUSettingsSMGakeKeeperSettings(m_cgiRoot);
}

WWidget *TMMCUSettings::CSTUNSettings()
{
    return new TMMCUSettingsSMSTUNSettings(m_cgiRoot);
}

WWidget *TMMCUSettings::CDSPSettings()
{
    return new TMMCUSettingsSMDSPSettings(m_cgiRoot);
}


/**********************************
*    = Base Class Overrides =
**********************************/

WWidget *TMMCUSettings::Layout()
{
    Div *root = new Div("TMMCUSettings");

    Div *dvSubMenu = new Div(root, "dvSubMenu");
    Div *dvContents = new Div(root, "dvContents");
    Div *dvSubMenuInner = new Div(dvSubMenu, "dvSubMenuInner");

    WStackedWidget *dvContentsInner = new WStackedWidget(dvContents);
    dvContentsInner->setId("dvContentsInner");

    WMenu *subMenu = new WMenu(dvContentsInner, Horizontal, dvSubMenuInner);
    subMenu->setRenderAsList(true);

    subMenu->addItem
            (m_lang->GetString("HML_MCU_SETTINGS_CODEC_SETTINGS"), CCodecSettings(), WMenuItem::PreLoading)->setPathComponent("");

    subMenu->addItem
            (m_lang->GetString("HML_MCU_SETTINGS_SIGNALING_SETTINGS"), CSignalingSettings(), WMenuItem::PreLoading)->setPathComponent("");

    subMenu->addItem
            (m_lang->GetString("HML_MCU_SETTINGS_SIP_SERVER_SETTINGS"), CSIPServerSettings(), WMenuItem::PreLoading)->setPathComponent("");

    subMenu->addItem
            (m_lang->GetString("HML_MCU_SETTINGS_GATE_KEEPER_SETTINGS"), CGakeKeeperSettings(), WMenuItem::PreLoading)->setPathComponent("");

    subMenu->addItem
            (m_lang->GetString("HML_MCU_SETTINGS_STUN_SETTINGS"), CSTUNSettings(), WMenuItem::PreLoading)->setPathComponent("");

    subMenu->addItem
            (m_lang->GetString("HML_MCU_SETTINGS_DSP_SETTINGS"), CDSPSettings(), WMenuItem::PreLoading)->setPathComponent("");

    return root;
}


/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


