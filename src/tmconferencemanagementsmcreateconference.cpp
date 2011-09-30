/**********************************
*    = Header File Inclusion =
**********************************/

#include <boost/lexical_cast.hpp>
#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WButtonGroup>
#include <Wt/WCheckBox>
#include <Wt/WComboBox>
#include <Wt/WContainerWidget>
#include <Wt/WDateValidator>
#include <Wt/WDialog>
#include <Wt/WGridLayout>
#include <Wt/WGroupBox>
#include <Wt/WHBoxLayout>
#include <Wt/WLengthValidator>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WRadioButton>
#include <Wt/WRegExpValidator>
#include <Wt/WSignalMapper>
#include <Wt/WSpinBox>
#include <Wt/WStandardItem>
#include <Wt/WTable>
#include <Wt/WText>
#include <Wt/WVBoxLayout>
#include <Wt/WWidget>
#include "tmconferencemanagementsmcreateconference.hpp"
#include "ipc/getcontactscommand.hpp"


/**********************************
*    = PreProcessor Directives =
**********************************/

/**********************************
*    = Importing NameSpaces =
**********************************/

using namespace std;
using namespace boost;
using namespace Wt;
using namespace ControlConference;
using namespace Commands;


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

TMConferenceManagementSMCreateConference::TMConferenceManagementSMCreateConference(CgiRoot *cgi) : BaseWidget(cgi)
{
    this->clear();
    this->addWidget(Layout());
}


/**********************************
*    = Destructor =
**********************************/

TMConferenceManagementSMCreateConference::~TMConferenceManagementSMCreateConference()
{
}


/**********************************
*    = Public Methods =
**********************************/

/**********************************
*    = Event Handlers =
**********************************/

void TMConferenceManagementSMCreateConference::OnSignalingTypeCmbChanged(WString item)
{
    if (item == "H.323") {
        Div *dvGatekeeper = new Div("dvGatekeeper");
        dvGatekeeper->resize(270, WLength::Auto);
        WGroupBox *gkGroup = new WGroupBox(m_lang->GetString("CONF_MGMT_CREATE_GATEKEEPER_TITLE"), dvGatekeeper);
        WGridLayout *gkLayout = new WGridLayout();
        gkLayout->setColumnStretch(0, 120);
        gkLayout->setColumnStretch(1, 150);
        gkLayout->setVerticalSpacing(11);
        gkGroup->setLayout(gkLayout, AlignTop | AlignJustify);
        m_gatekeeperBtnGroup = new WButtonGroup();  
        WRadioButton *tempRadioBtn;
        tempRadioBtn = new WRadioButton(m_lang->GetString("GENERAL_ACTIVE"));
        m_gatekeeperBtnGroup->addButton(tempRadioBtn, 0);
        tempRadioBtn = new WRadioButton(m_lang->GetString("GENERAL_INACTIVE"));
        m_gatekeeperBtnGroup->addButton(tempRadioBtn, 1);
        m_gkAddressEdit = new WLineEdit();
        m_gkUserEdit = new WLineEdit();
        m_gkPassEdit = new WLineEdit();
        m_gkPassEdit->setEchoMode(WLineEdit::Password);
        gkLayout->addWidget(m_gatekeeperBtnGroup->button(0), 0, 0);
        gkLayout->addWidget(m_gatekeeperBtnGroup->button(1), 0, 1);
        gkLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_GK_IP_ADDR_TEXT")), 1, 0);
        gkLayout->addWidget(m_gkAddressEdit, 1, 1);
        gkLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_GK_USER_TEXT")), 2, 0);
        gkLayout->addWidget(m_gkUserEdit, 2, 1);
        gkLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_GK_PWD_TEXT")), 3, 0);
        gkLayout->addWidget(m_gkPassEdit, 3, 1);
        
        m_dvSignalingTypeForm->clear();
        m_dvSignalingTypeForm->addWidget(dvGatekeeper);
    }
    else if (item == "SIP") {
        Div *dvSIPServer = new Div("dvSIPServer");        
        dvSIPServer->resize(270, WLength::Auto);
        WGroupBox *sipServerGroup = new WGroupBox(m_lang->GetString("CONF_MGMT_CREATE_SIPSERVER_TITLE"),
                                                  dvSIPServer);
        WGridLayout *sipServerLayout = new WGridLayout();
        sipServerLayout->setColumnStretch(0, 120);
        sipServerLayout->setColumnStretch(1, 150);
        sipServerLayout->setVerticalSpacing(11);
        sipServerGroup->setLayout(sipServerLayout, AlignTop | AlignJustify);
        m_sipServerBtnGroup = new WButtonGroup();
        WRadioButton *tempRadioBtn;
        tempRadioBtn = new WRadioButton(m_lang->GetString("GENERAL_ACTIVE"));
        m_sipServerBtnGroup->addButton(tempRadioBtn, 0);
        tempRadioBtn = new WRadioButton(m_lang->GetString("GENERAL_INACTIVE"));
        m_sipServerBtnGroup->addButton(tempRadioBtn, 1);
        m_sipAddressEdit = new WLineEdit();
        m_sipUserEdit = new WLineEdit();
        m_sipPassEdit = new WLineEdit();
        m_sipPassEdit->setEchoMode(WLineEdit::Password);
        sipServerLayout->addWidget(m_sipServerBtnGroup->button(0), 0, 0);
        sipServerLayout->addWidget(m_sipServerBtnGroup->button(1), 0, 1);
        sipServerLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_SIP_IP_ADDR_TEXT")), 1, 0);
        sipServerLayout->addWidget(m_sipAddressEdit, 1, 1);
        sipServerLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_SIP_USER_TEXT")), 2, 0);
        sipServerLayout->addWidget(m_sipUserEdit, 2, 1);
        sipServerLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_SIP_PWD_TEXT")), 3, 0);
        sipServerLayout->addWidget(m_sipPassEdit, 3, 1);

        m_dvSignalingTypeForm->clear();
        m_dvSignalingTypeForm->addWidget(dvSIPServer);
    }
}

void TMConferenceManagementSMCreateConference::OnConferenceTypeRadioGroupChanged(WRadioButton *sender)
{
    if (sender->text() == m_lang->GetString("CONF_MGMT_CREATE_TYPE_IMMEDIATE_TEXT")) {
        m_conferenceDateEdit->setEnabled(false);
        m_conferenceTimeEdit->setEnabled(false);
    }
    else if (sender->text() == m_lang->GetString("CONF_MGMT_CREATE_TYPE_BOOKED_TEXT")) {
        m_conferenceDateEdit->setEnabled(true);
        m_conferenceTimeEdit->setEnabled(true);
    }
}

void TMConferenceManagementSMCreateConference::OnSendToStreamChkChanged()
{
    if (m_sendToStreamServerChk->isChecked())
        m_streamDestinationEdit->setEnabled(true);
    else
        m_streamDestinationEdit->setEnabled(false);
}

void TMConferenceManagementSMCreateConference::OnEndingTypeRadioGroupChanged(WRadioButton *sender)
{
    if (sender->text() == m_lang->GetString("CONF_MGMT_CREATE_MANUAL_ENDING_TEXT")) {
        m_maxDurationEdit->setEnabled(false);
    }
    else if (sender->text() == m_lang->GetString("CONF_MGMT_CREATE_AUTO_ENDING_TEXT")) {
        m_maxDurationEdit->setEnabled(true);
    }
}

void TMConferenceManagementSMCreateConference::OnAddParticipantBtnClicked()
{
    if (!Validate(m_newParticipantNameEdit)
            || !Validate(m_newParticipantAddressEdit)) {
        return;
    }
    
    AddContactToParticipantsTable(m_newParticipantAddressEdit->text(), m_newParticipantNameEdit->text());
}

void TMConferenceManagementSMCreateConference::OnPhoneBookBtnClicked()
{
    m_dialogBox = new WDialog(m_lang->GetString("WINDOW_TITLE_PHONEBOOK"));
    m_dialogBox->setModal(true);
    m_dialogBox->contents()->addWidget(GetPhoneBookForm());
    m_dialogBox->show();
}

void TMConferenceManagementSMCreateConference::OnPhoneBookDialogConfirmed()
{
}

void TMConferenceManagementSMCreateConference::OnPhoneBookTableAddBtnClicked(WPushButton *sender)
{
    AddContactToParticipantsTable(sender->attributeValue("addr"), sender->attributeValue("name"));
}

void TMConferenceManagementSMCreateConference::OnParticipantsTableRemoveBtnClicked(WPushButton *sender)
{
    int row = lexical_cast<int>(sender->attributeValue("row"));
    
    m_participantsTableRemoveButtons.erase(m_participantsTableRemoveButtons.begin() + row - 1);
    m_participantsTable->deleteRow(row);

    int i = 0;
    for (vector<WPushButton *>::const_iterator it = m_participantsTableRemoveButtons.begin();
        it != m_participantsTableRemoveButtons.end(); ++it) {
            (*it)->setAttributeValue("row", lexical_cast<wstring>(++i));
            m_participantsTable->elementAt(i, 0)->clear();
            m_participantsTable->elementAt(i, 0)->addWidget(new WText(lexical_cast<wstring>(i)));
    }
}


/**********************************
*    = Protected Methods =
**********************************/

/**********************************
*    = Private Methods =
**********************************/

WWidget *TMConferenceManagementSMCreateConference::GetPhoneBookForm()
{
    Div *root = new Div("PhoneBookForm");
    
    Div *dvTable = new Div(root);
    
    dvTable->setOverflow(OverflowAuto, Vertical);
    dvTable->resize(550, 400);
    
    GetContactsCommand cmd(Base::MCU_MANAGER_URL);

    WTable *contactsTable = new WTable();
    contactsTable->setStyleClass("tbl");
    contactsTable->resize(550, WLength::Auto);

    contactsTable->elementAt(0, 0)->addWidget(new WText(m_lang->GetString("GENERAL_INDEX")));
    contactsTable->elementAt(0, 0)->resize(50, WLength::Auto);
    contactsTable->elementAt(0, 1)->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_PARTICIPANT_NAME_TEXT")));
    contactsTable->elementAt(0, 2)->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_PARTICIPANT_ADDRESS_TEXT")));
    contactsTable->elementAt(0, 3)->addWidget(new WText());
    contactsTable->elementAt(0, 3)->resize(75, WLength::Auto);
    contactsTable->elementAt(0, 0)->setStyleClass("tblHeader");
    contactsTable->elementAt(0, 1)->setStyleClass("tblHeader");
    contactsTable->elementAt(0, 2)->setStyleClass("tblHeader");
    contactsTable->elementAt(0, 3)->setStyleClass("tblHeader");

    if (cmd.Send()) {
        vector<Contact> vec = cmd.GetContacts();
        for (size_t i = 0; i < vec.size(); ++i) {
            contactsTable->elementAt(i + 1, 0)->addWidget(new WText(lexical_cast<wstring>(i + 1)));
            contactsTable->elementAt(i + 1, 1)->addWidget(new WText(vec[i].Name));
            contactsTable->elementAt(i + 1, 2)->addWidget(new WText(vec[i].IP));
            WPushButton *btn = new WPushButton(m_lang->GetString("CONF_MGMT_CREATE_ADD_PARTICIPANT_TEXT"));
            btn->setAttributeValue("addr", vec[i].IP);
            btn->setAttributeValue("name", vec[i].Name);
            contactsTable->elementAt(i + 1, 3)->addWidget(btn);
            WSignalMapper<WPushButton *> *signalMapper = new WSignalMapper<WPushButton *>(this);
            signalMapper->mapped().connect(this, &TMConferenceManagementSMCreateConference::OnPhoneBookTableAddBtnClicked);
            signalMapper->mapConnect(btn->clicked(), btn);
        }
    }
    
    dvTable->addWidget(contactsTable);
    
    Div *dvButtons = new Div(root);
    WPushButton *returnButton = new WPushButton(m_lang->GetString("GENERAL_RETURN"), dvButtons);
    
    returnButton->setStyleClass("dialogButton");
    
    
    // HANDLING EVENTS
    m_dialogBox->finished().connect(this, &TMConferenceManagementSMCreateConference::OnPhoneBookDialogConfirmed);
    returnButton->clicked().connect(m_dialogBox, &WDialog::reject);
    
    return root;
}

void TMConferenceManagementSMCreateConference::AddContactToParticipantsTable(Wt::WString addr, Wt::WString name)
{
    for (vector<WPushButton *>::const_iterator it = m_participantsTableRemoveButtons.begin();
        it != m_participantsTableRemoveButtons.end(); ++it) {
            if ((*it)->attributeValue("addr") == addr) {
                return;
            }
    }

    int row = m_participantsTable->rowCount();

    m_participantsTable->elementAt(row, 0)->addWidget(new WText(lexical_cast<wstring>(row)));
    m_participantsTable->elementAt(row, 1)->addWidget(new WText(name));
    m_participantsTable->elementAt(row, 2)->addWidget(new WText(addr));

    WPushButton *btn = new WPushButton("X");
    btn->setAttributeValue("row", lexical_cast<wstring>(row));
    btn->setAttributeValue("addr", addr);
    btn->setAttributeValue("name", name);
    WSignalMapper<WPushButton *> *signalMapper = new WSignalMapper<WPushButton *>(this);
    signalMapper->mapped().connect(this, &TMConferenceManagementSMCreateConference::OnParticipantsTableRemoveBtnClicked);
    m_participantsTableRemoveButtons.push_back(btn);
    signalMapper->mapConnect(btn->clicked(), btn);

    m_participantsTable->elementAt(row, 3)->addWidget(btn);
}


/**********************************
*    = Base Class Overrides =
**********************************/

WWidget *TMConferenceManagementSMCreateConference::Layout()
{
    Div *root = new Div("TMConferenceManagementSMCreateConference");

    /*************************************************************************
                                    General Info
    *************************************************************************/

    WGroupBox *generalSettingsGroup = new WGroupBox(
                m_lang->GetString("CONF_MGMT_CREATE_GENERAL_TITLE"),
                root);
    generalSettingsGroup->resize(WLength::Auto, 230);

    WHBoxLayout *generalSettingsBox = new WHBoxLayout(generalSettingsGroup);

    Div *dvGeneralSettings = new Div("dvGeneralSettings");
    dvGeneralSettings->resize(270, WLength::Auto);
    WGridLayout *dvGeneralSettingsLayout = new WGridLayout();
    dvGeneralSettingsLayout->setColumnStretch(0, 120);
    dvGeneralSettingsLayout->setColumnStretch(1, 150);
    dvGeneralSettingsLayout->setVerticalSpacing(11);
    dvGeneralSettings->setLayout(dvGeneralSettingsLayout, AlignTop | AlignJustify);
    
    WRadioButton *tempRadioBtn;
    m_conferenceTypeBtnGroup = new WButtonGroup();
    tempRadioBtn = new WRadioButton(m_lang->GetString("CONF_MGMT_CREATE_TYPE_IMMEDIATE_TEXT"));
    m_conferenceTypeBtnGroup->addButton(tempRadioBtn, 0);
    tempRadioBtn = new WRadioButton(m_lang->GetString("CONF_MGMT_CREATE_TYPE_BOOKED_TEXT"));
    m_conferenceTypeBtnGroup->addButton(tempRadioBtn, 1);
    m_conferenceTypeBtnGroup->setSelectedButtonIndex(0);
    m_conferenceNameEdit = new WLineEdit();
    m_conferenceNumberEdit = new WLineEdit();
    m_signalingTypeCmb = new WComboBox();
    m_signalingTypeCmb->addItem("SIP");
    m_signalingTypeCmb->addItem("H.323");

    m_dvSignalingTypeForm = new Div("dvSignalingTypeForm");

    /*************************************************************************
                             General Info -> Date & Time
    *************************************************************************/

    m_dvConferenceDateTimeForm = new Div("dvConferenceTypeRadioGroup");
    m_dvConferenceDateTimeForm->resize(270, WLength::Auto);
    WGroupBox *dateTimeGroup = new WGroupBox(m_lang->GetString("CONF_MGMT_CREATE_DATETIME_TITLE"),
                                              m_dvConferenceDateTimeForm);
    WGridLayout *dateTimeLayout = new WGridLayout();
    dateTimeLayout->setColumnStretch(0, 120);
    dateTimeLayout->setColumnStretch(1, 150);
    dateTimeLayout->setVerticalSpacing(11);
    dateTimeGroup->setLayout(dateTimeLayout, AlignTop | AlignJustify);
    m_conferenceDateEdit = new WLineEdit();
    WDateValidator *dateValidator = new WDateValidator("yyyy-mm-dd");
    m_conferenceDateEdit->setValidator(dateValidator);
    m_conferenceTimeEdit = new WLineEdit();
    WRegExpValidator *timeValidator = new WRegExpValidator(Base::REGEX_TIME);
    m_conferenceTimeEdit->setValidator(timeValidator);
    dateTimeLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_DATE_TEXT")), 0, 0);
    dateTimeLayout->addWidget(m_conferenceDateEdit, 0, 1);
    dateTimeLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_TIME_TEXT")), 1, 0);
    dateTimeLayout->addWidget(m_conferenceTimeEdit, 1, 1);

    /************************************************************************/
    
    m_signalingTypeCmb->setCurrentIndex(1);
    OnSignalingTypeCmbChanged("H.323");
    OnConferenceTypeRadioGroupChanged(m_conferenceTypeBtnGroup->button(0));
    
    generalSettingsBox->addWidget(dvGeneralSettings);
    generalSettingsBox->addWidget(m_dvSignalingTypeForm);
    generalSettingsBox->addWidget(m_dvConferenceDateTimeForm);

    dvGeneralSettingsLayout->addWidget(
                new WText(m_lang->GetString("CONF_MGMT_CREATE_TYPE_TITLE")),
                0, 0, Wt::AlignMiddle);
    dvGeneralSettingsLayout->addWidget(
                m_conferenceTypeBtnGroup->button(0),
                0, 1, Wt::AlignMiddle);
    dvGeneralSettingsLayout->addWidget(
                m_conferenceTypeBtnGroup->button(1),
                1, 1, Wt::AlignMiddle);
    dvGeneralSettingsLayout->addWidget(
                new WText(m_lang->GetString("CONF_MGMT_CREATE_NAME_TEXT")),
                2, 0, Wt::AlignMiddle);
    dvGeneralSettingsLayout->addWidget(
                m_conferenceNameEdit,
                2, 1, Wt::AlignMiddle);
    dvGeneralSettingsLayout->addWidget(
                new WText(m_lang->GetString("CONF_MGMT_CREATE_ID_TEXT")),
                3, 0, Wt::AlignMiddle);
    dvGeneralSettingsLayout->addWidget(
                m_conferenceNumberEdit,
                3, 1, Wt::AlignMiddle);
    dvGeneralSettingsLayout->addWidget(
                new WText(m_lang->GetString("CONF_MGMT_CREATE_SIGNALING_TEXT")),
                4, 0, Wt::AlignMiddle);
    dvGeneralSettingsLayout->addWidget(
                m_signalingTypeCmb,
                4, 1, Wt::AlignMiddle);
                
    /*************************************************************************
                                    Media Settings
    *************************************************************************/

    WGroupBox *mediaSettingsGroup = new WGroupBox(
                m_lang->GetString("CONF_MGMT_CREATE_MEDIA_TITLE"),
                root);
    mediaSettingsGroup->resize(WLength::Auto, 200);

    Div *dvMediaSettings = new Div(mediaSettingsGroup, "dvMediaSettings");
    dvMediaSettings->resize(570, WLength::Auto);

    WGridLayout *dvMediaSettingsLayout = new WGridLayout();
    dvMediaSettingsLayout->setColumnStretch(0, 120);
    dvMediaSettingsLayout->setColumnStretch(1, 150);
    dvMediaSettingsLayout->setColumnStretch(2, 150);
    dvMediaSettingsLayout->setColumnStretch(3, 150);
    dvMediaSettingsLayout->setVerticalSpacing(11);
    dvMediaSettings->setLayout(dvMediaSettingsLayout, AlignTop | AlignJustify);
    
    m_outputSoundCodecCmb = new WComboBox();
    m_outputSoundCodecCmb->addItem("G.711 a-low");
    m_outputSoundCodecCmb->addItem("G.711 u-low");
    m_outputSoundCodecCmb->addItem("G.722 - 24k");
    m_outputSoundCodecCmb->addItem("G.722 - 32k");
    m_outputSoundCodecCmb->addItem("G.722 - 48k");
    m_outputVideoCodecCmb = new WComboBox();
    m_outputVideoCodecCmb->addItem("H.264");
    m_outputVideoCodecCmb->addItem("H.263");
    m_outputVideoCodecCmb->addItem("MPEG-4");
    m_videoRes720pChk = new WCheckBox("720p");
    m_videoResCIFChk = new WCheckBox("CIF");
    m_videoRes4CIFChk = new WCheckBox("4CIF");
    m_outputRateCmb = new WComboBox();
    m_outputRateCmb->addItem("386");
    m_outputRateCmb->addItem("512");
    m_outputRateCmb->addItem("768");
    m_outputRateCmb->addItem("1024");
    m_outputRateCmb->addItem("1216");
    m_outputRateCmb->addItem("1536");
    m_outputRateCmb->addItem("1792");
    m_outputRateCmb->addItem("2048");
    m_outputRateCmb->addItem("3072");
    m_outputRateCmb->addItem("4096");

    dvMediaSettingsLayout->addWidget(
                new WText(m_lang->GetString("CONF_MGMT_CREATE_AUDIO_CODEC_TEXT")),
                0, 0, Wt::AlignMiddle);
    dvMediaSettingsLayout->addWidget(
                m_outputSoundCodecCmb,
                0, 1, Wt::AlignMiddle);
    dvMediaSettingsLayout->addWidget(
                new WText(m_lang->GetString("CONF_MGMT_CREATE_VIDEO_CODEC_TEXT")),
                1, 0, Wt::AlignMiddle);
    dvMediaSettingsLayout->addWidget(
                m_outputVideoCodecCmb,
                1, 1, Wt::AlignMiddle);
    dvMediaSettingsLayout->addWidget(
                new WText(m_lang->GetString("CONF_MGMT_CREATE_VIDEO_RES_TEXT")),
                2, 0, Wt::AlignMiddle);
    dvMediaSettingsLayout->addWidget(
                m_videoRes720pChk,
                2, 1, Wt::AlignMiddle);
    dvMediaSettingsLayout->addWidget(
                m_videoResCIFChk,
                2, 2, Wt::AlignMiddle);
    dvMediaSettingsLayout->addWidget(
                m_videoRes4CIFChk,
                2, 3, Wt::AlignMiddle);
    dvMediaSettingsLayout->addWidget(
                new WText(m_lang->GetString("CONF_MGMT_CREATE_CONF_RATE_TEXT")),
                3, 0, Wt::AlignMiddle);
    dvMediaSettingsLayout->addWidget(
                m_outputRateCmb,
                3, 1, Wt::AlignMiddle);

    /*************************************************************************
                                   Other Settings
    *************************************************************************/

    WGroupBox *otherSettingsGroup = new WGroupBox(
                m_lang->GetString("CONF_MGMT_CREATE_OTHER_TITLE"),
                root);
    otherSettingsGroup->resize(WLength::Auto, 230);

    Div *dvOtherSettings = new Div(otherSettingsGroup, "dvOtherSettings");
    dvOtherSettings->resize(570, WLength::Auto);

    WGridLayout *dvOtherSettingsLayout = new WGridLayout();
    dvOtherSettingsLayout->setColumnStretch(0, 270);
    dvOtherSettingsLayout->setColumnStretch(1, 150);
    dvOtherSettingsLayout->setColumnStretch(2, 150);
    dvOtherSettingsLayout->setVerticalSpacing(11);
    dvOtherSettings->setLayout(dvOtherSettingsLayout, AlignTop | AlignJustify);

    m_participantNumSpin = new WSpinBox();
    m_participantNumSpin->setMinimum(1);
    m_participantNumSpin->setMaximum(16);
    m_participantNumSpin->setValue(1);
    m_hasH239Chk = new WCheckBox(m_lang->GetString("CONF_MGMT_CREATE_HAS_H239_TEXT"));
    m_externalUserChk = new WCheckBox(m_lang->GetString("CONF_MGMT_CREATE_EXTERNAL_USER_TEXT"));
    m_sendToStreamServerChk = new WCheckBox(m_lang->GetString("CONF_MGMT_CREATE_SEND_TO_SERVER_TEXT"));
    m_streamDestinationEdit = new WLineEdit();
    m_endingTypeBtnGroup = new WButtonGroup();
    tempRadioBtn = new WRadioButton(m_lang->GetString("CONF_MGMT_CREATE_MANUAL_ENDING_TEXT"));
    m_endingTypeBtnGroup->addButton(tempRadioBtn, 0);
    tempRadioBtn = new WRadioButton(m_lang->GetString("CONF_MGMT_CREATE_AUTO_ENDING_TEXT"));
    m_endingTypeBtnGroup->addButton(tempRadioBtn, 1);
    m_endingTypeBtnGroup->setSelectedButtonIndex(0);
    m_maxDurationEdit = new WLineEdit();

    dvOtherSettingsLayout->addWidget(
                new WText(m_lang->GetString("CONF_MGMT_CREATE_NUM_OF_PARTICIPANTS_TEXT")),
                0, 0, Wt::AlignMiddle);
    dvOtherSettingsLayout->addWidget(
                m_participantNumSpin,
                0, 1, Wt::AlignMiddle);
    dvOtherSettingsLayout->addWidget(
                m_hasH239Chk,
                1, 0, Wt::AlignMiddle);
    dvOtherSettingsLayout->addWidget(
                m_externalUserChk,
                2, 0, Wt::AlignMiddle);
    dvOtherSettingsLayout->addWidget(
                m_sendToStreamServerChk,
                3, 0, Wt::AlignMiddle);
    dvOtherSettingsLayout->addWidget(
                m_streamDestinationEdit,
                3, 1, Wt::AlignMiddle);
    dvOtherSettingsLayout->addWidget(
                m_endingTypeBtnGroup->button(0),
                4, 0, Wt::AlignMiddle);
    dvOtherSettingsLayout->addWidget(
                m_endingTypeBtnGroup->button(1),
                5, 0, Wt::AlignMiddle);
    dvOtherSettingsLayout->addWidget(
                m_maxDurationEdit,
                5, 1, Wt::AlignMiddle);

    OnSendToStreamChkChanged();
    OnEndingTypeRadioGroupChanged(m_endingTypeBtnGroup->button(0));

    /*************************************************************************
                                    Participants
    *************************************************************************/

    WGroupBox *participantsGroup = new WGroupBox(
                m_lang->GetString("CONF_MGMT_CREATE_PARTICIPANTS_TITLE"),
                root);
    participantsGroup->resize(WLength::Auto, 270);

    WHBoxLayout *participantsBox = new WHBoxLayout(participantsGroup);

    /*************************************************************************
                                 Adding Participants
    *************************************************************************/

    Div *dvParticipants = new Div("dvParticipants");
    dvParticipants->resize(350, WLength::Auto);

    Div *dvSelectPhonebook = new Div(dvParticipants, "dvSelectPhonebook");
    dvSelectPhonebook->resize(270, WLength::Auto);
    WGridLayout *selectPhonebookLayout = new WGridLayout();
    selectPhonebookLayout->setColumnStretch(0, 150);
    selectPhonebookLayout->setColumnStretch(1, 120);
    selectPhonebookLayout->setVerticalSpacing(11);
    dvSelectPhonebook->setLayout(selectPhonebookLayout);

    WPushButton *phonebookBtn = new WPushButton(m_lang->GetString("CONF_MGMT_CREATE_PHONEBOOK_TEXT"),
                                                dvParticipants);

    selectPhonebookLayout->addWidget(new WText(
                                         m_lang->GetString("CONF_MGMT_CREATE_SELECT_PHONEBOOK_TEXT")), 0, 0);
    selectPhonebookLayout->addWidget(phonebookBtn, 0, 1);

    WGroupBox *newParticipantGroup = new WGroupBox(
                m_lang->GetString("CONF_MGMT_CREATE_NEW_CONTACT_TEXT"),
                dvParticipants);

    WGridLayout *participantsLayout = new WGridLayout();
    participantsLayout->setColumnStretch(0, 150);
    participantsLayout->setColumnStretch(1, 200);
    participantsLayout->setVerticalSpacing(11);
    newParticipantGroup->setLayout(participantsLayout, AlignTop | AlignJustify);

    m_newParticipantNameEdit = new WLineEdit();
    m_newParticipantAddressEdit = new WLineEdit();
    m_addParticipantToAddrBookChk = new WCheckBox(m_lang->GetString("CONF_MGMT_CREATE_ADD_TO_PHONEBOOK_TEXT"));
    WPushButton *addParticipantBtn = new WPushButton(m_lang->GetString("CONF_MGMT_CREATE_ADD_PARTICIPANT_TEXT"));

    WLengthValidator *newParticipantNameLenValidator = new WLengthValidator(1, 255);
    newParticipantNameLenValidator->setMandatory(true);
    m_newParticipantNameEdit->setValidator(newParticipantNameLenValidator);

    WRegExpValidator *newParticipantAddressRegExValidator = new WRegExpValidator(Base::REGEX_IP);
    newParticipantAddressRegExValidator->setMandatory(true);
    m_newParticipantAddressEdit->setValidator(newParticipantAddressRegExValidator);

    participantsLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_PARTICIPANT_NAME_TEXT")), 0, 0);
    participantsLayout->addWidget(m_newParticipantNameEdit, 0, 1);
    participantsLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_PARTICIPANT_ADDRESS_TEXT")), 1, 0);
    participantsLayout->addWidget(m_newParticipantAddressEdit, 1, 1);
    participantsLayout->addWidget(m_addParticipantToAddrBookChk, 2, 0);
    participantsLayout->addWidget(addParticipantBtn, 3, 1);

    /*********************** End of Adding Participants *********************/


    /*************************************************************************
                                 Participants Table
    *************************************************************************/

    Div *dvParticipantsTable = new Div();
    dvParticipantsTable->setOverflow(OverflowAuto, Vertical);
    dvParticipantsTable->resize(530, 200);
    
    m_participantsTable = new WTable(dvParticipantsTable);
    m_participantsTable->resize(500, WLength::Auto);
    
    m_participantsTable->setStyleClass("tbl");
    m_participantsTable->elementAt(0, 0)->addWidget(new WText(m_lang->GetString("GENERAL_INDEX")));
    m_participantsTable->elementAt(0, 1)->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_PARTICIPANT_NAME_TEXT")));
    m_participantsTable->elementAt(0, 2)->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_PARTICIPANT_ADDRESS_TEXT")));
    m_participantsTable->elementAt(0, 3)->addWidget(new WText());
    m_participantsTable->elementAt(0, 0)->setStyleClass("tblHeader");
    m_participantsTable->elementAt(0, 1)->setStyleClass("tblHeader");
    m_participantsTable->elementAt(0, 2)->setStyleClass("tblHeader");
    m_participantsTable->elementAt(0, 0)->resize(50, WLength::Auto);
    m_participantsTable->elementAt(0, 1)->resize(200, WLength::Auto);
    m_participantsTable->elementAt(0, 2)->resize(200, WLength::Auto);
    m_participantsTable->elementAt(0, 3)->resize(50, WLength::Auto);


    /*********************** End of Participants Table **********************/

    participantsBox->addWidget(dvParticipants);
    participantsBox->addWidget(dvParticipantsTable);

    /*************************************************************************
                                      Buttons
    *************************************************************************/

    Div *dvButtons = new Div(root, "dvButtons");
    dvButtons->resize(320, WLength::Auto);

    WGridLayout *dvButtonsLayout = new WGridLayout();
    dvButtonsLayout->setColumnStretch(0, 120);
    dvButtonsLayout->setColumnStretch(1, 200);
    dvButtonsLayout->setVerticalSpacing(11);
    dvButtons->setLayout(dvButtonsLayout, AlignTop | AlignJustify);

    WPushButton *submitBtn = new WPushButton(m_lang->GetString("CONF_MGMT_CREATE_SUBMIT_TEXT"));
    WPushButton *saveBtn = new WPushButton(m_lang->GetString("CONF_MGMT_CREATE_SAVE_TEXT"));

    dvButtonsLayout->addWidget(
                submitBtn,
                0, 0, Wt::AlignMiddle);
    dvButtonsLayout->addWidget(
                saveBtn,
                0, 1, Wt::AlignMiddle);

    /*************************************************************************
                                 Connecting Events
    *************************************************************************/
    
    m_signalingTypeCmb->sactivated().connect(this,
                               &TMConferenceManagementSMCreateConference::OnSignalingTypeCmbChanged);
    
    m_conferenceTypeBtnGroup->checkedChanged().connect(this,
                               &TMConferenceManagementSMCreateConference::OnConferenceTypeRadioGroupChanged);

    m_sendToStreamServerChk->changed().connect(this,
                               &TMConferenceManagementSMCreateConference::OnSendToStreamChkChanged);

    m_endingTypeBtnGroup->checkedChanged().connect(this,
                               &TMConferenceManagementSMCreateConference::OnEndingTypeRadioGroupChanged);

    addParticipantBtn->clicked().connect(this,
                               &TMConferenceManagementSMCreateConference::OnAddParticipantBtnClicked);

    phonebookBtn->clicked().connect(this,
                               &TMConferenceManagementSMCreateConference::OnPhoneBookBtnClicked);
    return root;
}


/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


