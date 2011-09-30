/**********************************
*    = Header File Inclusion =
**********************************/

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WGroupBox>
#include <Wt/WHBoxLayout>
#include <Wt/WPushButton>
#include <Wt/WStandardItemModel>
#include <Wt/WText>
#include <Wt/WVBoxLayout>
#include <Wt/WWidget>
#include "tmconferencemanagementsmtemplates.hpp"


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

TMConferenceManagementSMTemplates::TMConferenceManagementSMTemplates(CgiRoot *cgi) : BaseWidget(cgi)
{
    this->clear();
    this->addWidget(Layout());
}


/**********************************
*    = Destructor =
**********************************/

TMConferenceManagementSMTemplates::~TMConferenceManagementSMTemplates()
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

WWidget *TMConferenceManagementSMTemplates::Layout()
{
    Div *root = new Div("TMConferenceManagementSMTemplates");

    /*************************************************************************
                                 Templates Table
    *************************************************************************/

    WGroupBox *templatesListGroup = new WGroupBox(m_lang->GetString("CONF_MGMT_TEMPLATES_TABLE_TITLE"),
                                                   root);
    templatesListGroup->resize(WLength::Auto, 250);

    //Div *dvTemplatesTable = new Div(templatesListGroup, "dvTemplatesTable");


    /*************************************************************************
                              Template Table Buttons
    *************************************************************************/

    Div *dvTemplatesTableButtons = new Div(root, "dvTemplatesTableButtons");
    dvTemplatesTableButtons->resize(480, WLength::Auto);

    WGridLayout *dvTemplateButtonsLayout = new WGridLayout();
    dvTemplateButtonsLayout->setColumnStretch(0, 120);
    dvTemplateButtonsLayout->setColumnStretch(1, 120);
    dvTemplateButtonsLayout->setColumnStretch(2, 120);
    dvTemplateButtonsLayout->setColumnStretch(3, 120);
    dvTemplateButtonsLayout->setVerticalSpacing(11);
    dvTemplatesTableButtons->setLayout(dvTemplateButtonsLayout, AlignTop | AlignJustify);

    WPushButton *createTemplateBtn = new WPushButton(m_lang->GetString("CONF_MGMT_TEMPLATES_CREATE_TEXT"));
    WPushButton *editTemplateBtn = new WPushButton(m_lang->GetString("CONF_MGMT_TEMPLATES_EDIT_TEXT"));
    WPushButton *deleteTemplateBtn = new WPushButton(m_lang->GetString("CONF_MGMT_TEMPLATES_DELETE_TEXT"));
    WPushButton *holdTemplateBtn = new WPushButton(m_lang->GetString("CONF_MGMT_TEMPLATES_HOLD_TEXT"));

    dvTemplateButtonsLayout->addWidget(createTemplateBtn, 0, 0);
    dvTemplateButtonsLayout->addWidget(editTemplateBtn, 0, 1);
    dvTemplateButtonsLayout->addWidget(deleteTemplateBtn, 0, 2);
    dvTemplateButtonsLayout->addWidget(holdTemplateBtn, 0, 3);

    /*************************************************************************
                                  Template Info
    *************************************************************************/

    WGroupBox *templateInfoGroup = new WGroupBox(m_lang->GetString("CONF_MGMT_TEMPLATES_INFO_TITLE"),
                                                   root);
    templateInfoGroup->resize(WLength::Auto, 350);

    WVBoxLayout *templateInfoVBox = new WVBoxLayout(templateInfoGroup);
    WHBoxLayout *topTemplateInfoBox = new WHBoxLayout();
    WHBoxLayout *bottomTemplateInfoBox = new WHBoxLayout();

    Div *dvGeneralInfo = new Div("dvGeneralInfo");
    dvGeneralInfo->resize(270, WLength::Auto);

    WGridLayout *dvGeneralInfoLayout = new WGridLayout();
    dvGeneralInfoLayout->setColumnStretch(0, 150);
    dvGeneralInfoLayout->setColumnStretch(1, 120);
    dvGeneralInfoLayout->setVerticalSpacing(11);
    dvGeneralInfo->setLayout(dvGeneralInfoLayout, AlignTop | AlignJustify);

    dvGeneralInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_NAME_TEXT")), 0, 0);
    dvGeneralInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_ID_TEXT")), 1, 0);
    dvGeneralInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_SIGNALING_TEXT")), 2, 0);
    dvGeneralInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_LIST_CONFERENCE_TIME")), 3, 0);

    Div *dvMediaInfo = new Div("dvMediaInfo");
    dvMediaInfo->resize(270, WLength::Auto);

    WGridLayout *dvMediaInfoLayout = new WGridLayout();
    dvMediaInfoLayout->setColumnStretch(0, 150);
    dvMediaInfoLayout->setColumnStretch(1, 120);
    dvMediaInfoLayout->setVerticalSpacing(11);
    dvMediaInfo->setLayout(dvMediaInfoLayout, AlignTop | AlignJustify);

    dvMediaInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_AUDIO_CODEC_TEXT")), 0, 0);
    dvMediaInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_VIDEO_CODEC_TEXT")), 1, 0);
    dvMediaInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_VIDEO_RES_TEXT")), 2, 0);
    dvMediaInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_CONF_RATE_TEXT")), 3, 0);

    Div *dvOtherInfo = new Div("dvOtherInfo");
    dvOtherInfo->resize(320, WLength::Auto);

    WGridLayout *dvOtherInfoLayout = new WGridLayout();
    dvOtherInfoLayout->setColumnStretch(0, 200);
    dvOtherInfoLayout->setColumnStretch(1, 120);
    dvOtherInfoLayout->setVerticalSpacing(11);
    dvOtherInfo->setLayout(dvOtherInfoLayout, AlignTop | AlignJustify);

    dvOtherInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_HAS_H239_TEXT")), 0, 0);
    dvOtherInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_EXTERNAL_USER_TEXT")), 1, 0);
    dvOtherInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_LIST_CONF_SEND_TO_SERVER")), 2, 0);
    dvOtherInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_LIST_CONF_STREAM_DEST")), 3, 0);

    topTemplateInfoBox->addWidget(dvGeneralInfo);
    topTemplateInfoBox->addWidget(dvMediaInfo);
    topTemplateInfoBox->addWidget(dvOtherInfo);

    Div *dvGatekeeperInfo = new Div("dvGatekeeperInfo");
    dvGatekeeperInfo->resize(270, WLength::Auto);

    WGridLayout *dvGatekeeperInfoLayout = new WGridLayout();
    dvGatekeeperInfoLayout->setColumnStretch(0, 150);
    dvGatekeeperInfoLayout->setColumnStretch(1, 120);
    dvGatekeeperInfoLayout->setVerticalSpacing(11);
    dvGatekeeperInfo->setLayout(dvGatekeeperInfoLayout, AlignTop | AlignJustify);

    dvGatekeeperInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_LIST_CONF_GATEKEEPER")), 0, 0);
    dvGatekeeperInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_LIST_CONF_GATEKEEPER_ADDRESS")), 1, 0);
    dvGatekeeperInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_LIST_CONF_GATEKEEPER_USERNAME")), 2, 0);
    dvGatekeeperInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_LIST_CONF_GATEKEEPER_PASSWORD")), 3, 0);

    Div *dvSIPServerInfo = new Div("dvSIPServerInfo");
    dvSIPServerInfo->resize(270, WLength::Auto);

    WGridLayout *dvSIPServerInfoLayout = new WGridLayout();
    dvSIPServerInfoLayout->setColumnStretch(0, 150);
    dvSIPServerInfoLayout->setColumnStretch(1, 120);
    dvSIPServerInfoLayout->setVerticalSpacing(11);
    dvSIPServerInfo->setLayout(dvSIPServerInfoLayout, AlignTop | AlignJustify);

    dvSIPServerInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_LIST_CONF_SIPSERVER")), 0, 0);
    dvSIPServerInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_LIST_CONF_SIPSERVER_ADDRESS")), 1, 0);
    dvSIPServerInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_LIST_CONF_SIPSERVER_USERNAME")), 2, 0);
    dvSIPServerInfoLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_LIST_CONF_SIPSERVER_PASSWORD")), 3, 0);

    Div *dvEmpty = new Div();
    dvEmpty->resize(270, WLength::Auto);

    bottomTemplateInfoBox->addWidget(dvGatekeeperInfo);
    bottomTemplateInfoBox->addWidget(dvSIPServerInfo);
    bottomTemplateInfoBox->addWidget(dvEmpty);

    templateInfoVBox->addLayout(topTemplateInfoBox);
    templateInfoVBox->addLayout(bottomTemplateInfoBox);

    return root;
}


/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


