/**********************************
*    = Header File Inclusion =
**********************************/

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WGroupBox>
#include <Wt/WHBoxLayout>
#include <Wt/WStandardItemModel>
#include <Wt/WText>
#include <Wt/WVBoxLayout>
#include <Wt/WWidget>
#include "tmconferencemanagementsmconferencelist.hpp"


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

TMConferenceManagementSMConferenceList::TMConferenceManagementSMConferenceList(CgiRoot *cgi) : BaseWidget(cgi)
{
    this->clear();
    this->addWidget(Layout());
}


/**********************************
*    = Destructor =
**********************************/

TMConferenceManagementSMConferenceList::~TMConferenceManagementSMConferenceList()
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

WWidget *TMConferenceManagementSMConferenceList::Layout()
{
    Div *root = new Div("TMConferenceManagementSMConferenceList");

    /*************************************************************************
                                 Conferences Table
    *************************************************************************/

    WGroupBox *conferenceListGroup = new WGroupBox(m_lang->GetString("CONF_MGMT_LIST_CONFERENCE_LIST"),
                                                   root);
    conferenceListGroup->resize(WLength::Auto, 250);

    //Div *dvConferencesTable = new Div(conferenceListGroup, "dvConferencesTable");


    /*************************************************************************
                                 Conference Info
    *************************************************************************/

    WGroupBox *conferenceInfoGroup = new WGroupBox(m_lang->GetString("CONF_MGMT_LIST_CONFERENCE_INFO"),
                                                   root);
    conferenceInfoGroup->resize(WLength::Auto, 350);

    WVBoxLayout *conferenceInfoVBox = new WVBoxLayout(conferenceInfoGroup);
    WHBoxLayout *topConferenceInfoBox = new WHBoxLayout();
    WHBoxLayout *bottomConferenceInfoBox = new WHBoxLayout();

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

    topConferenceInfoBox->addWidget(dvGeneralInfo);
    topConferenceInfoBox->addWidget(dvMediaInfo);
    topConferenceInfoBox->addWidget(dvOtherInfo);

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

    Div *dvParticipantsInfo = new Div("dvParticipantsInfo");
    dvParticipantsInfo->resize(270, WLength::Auto);

    bottomConferenceInfoBox->addWidget(dvGatekeeperInfo);
    bottomConferenceInfoBox->addWidget(dvSIPServerInfo);
    bottomConferenceInfoBox->addWidget(dvParticipantsInfo);

    conferenceInfoVBox->addLayout(topConferenceInfoBox);
    conferenceInfoVBox->addLayout(bottomConferenceInfoBox);

    return root;
}


/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


