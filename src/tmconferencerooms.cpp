/**********************************
*    = Header File Inclusion =
**********************************/

#include <boost/lexical_cast.hpp>
#include <Wt/WApplication>
#include <Wt/WBorder>
#include <Wt/WCheckBox>
#include <Wt/WColor>
#include <Wt/WComboBox>
#include <Wt/WContainerWidget>
#include <Wt/WCssDecorationStyle>
#include <Wt/WDialog>
#include <Wt/WGridLayout>
#include <Wt/WGroupBox>
#include <Wt/WImage>
#include <Wt/WLengthValidator>
#include <Wt/WLineEdit>
#include <Wt/WMenuItem>
#include <Wt/WMessageBox>
#include <Wt/WPopupMenu>
#include <Wt/WPushButton>
#include <Wt/WRegExpValidator>
#include <Wt/WSignalMapper>
#include <Wt/WSpinBox>
#include <Wt/WStackedWidget>
#include <Wt/WTable>
#include <Wt/WText>
#include <Wt/WTextArea>
#include <Wt/WWidget>
#include "tmconferencerooms.hpp"
#include "participant.hpp"
#include "participantlayoutcell.hpp"
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
*    = Pimpl Things =
**********************************/

class TMConferenceRooms::Impl : public WObject
{
public:
    static const size_t LEGEND_SIZE_WIDTH;
    static const size_t LEGEND_SIZE_HEIGHT;

    static const string COMBO_BOX_INITIAL_VALUE;

    Div *dvParticipants;

    WComboBox *confListCombo;
    WLineEdit *confRateEdit;
    WLineEdit *confInfoE164IdEdit;
    WLineEdit *mtAliasEdit;
    WLineEdit *mtInfoE164IdEdit;
    WLineEdit *ipAddrEdit;
    WLineEdit *callModeEdit;
    WLineEdit *txRateEdit;
    WLineEdit *rxRateEdit;
    WLineEdit *mtCallRateEdit;
    WLineEdit *audioSrcEdit;
    WLineEdit *videoSrcEdit;
    WTextArea *mtStatusEdit;
    WCheckBox *muteCheck;
    WCheckBox *dumbCheck;
    WSpinBox *volInSpin;
    WSpinBox *volOutSpin;
    
    WImage *micIcon;
    WImage *volIcon;
    
    Div *dvContinuousPresence;
    WComboBox *continuousPresenceLayoutCombo;
    Div *dvParticipantsLayoutTable;

    WLineEdit *addParticipantNameEdit;
    WLineEdit *addParticipantAddrEdit;

private:
    CgiRoot *m_cgiRoot;
    Lang_ptr m_lang;
    WMessageBox *m_msgBox;
    WDialog *m_dlg;

public:
    Impl(CgiRoot *cgi);

    void OnEndConfLinkClicked(WText *sender);
    void OnEndConfLinkClickedMsgBoxOK(StandardButton result);

    void OnContinuousPresenceLinkClicked(WText *sender);
    void OnContinuousPresenceLayoutComboChanged(WString item);

    void OnAddParticipantLinkClicked(WText *sender);

    void OnParticipantCall(Participant *sender);
    void OnParticipantHangup(Participant *sender);
    void OnParticipantSetAsManager(Participant *sender);
    void OnParticipantSetAsSpeaker(Participant *sender);
    void OnParticipantView(Participant *sender);
    void OnParticipantRemove(Participant *sender);
    void OnParticipantMuteSpeaker(Participant *sender);
    void OnParticipantMuteMic(Participant *sender);
    void OnParticipantRecieveVideo(Participant *sender);
    void OnParticipantSendVideo(Participant *sender);
    void OnParticipantAddToAddrBook(Participant *sender);
    
    void OnAddParticipantLinkOK();
    void OnAddParticipantLinkOKReturn();
    void OnAddParticipantLinkReturn();

    void OnPhoneBookTableAddBtnClicked(WPushButton *sender);

private:
    WTable *GetLayoutFromString(WString layout);
    
    WWidget *GetAddParticipantForm();
};

const size_t TMConferenceRooms::Impl::LEGEND_SIZE_WIDTH = 12;
const size_t TMConferenceRooms::Impl::LEGEND_SIZE_HEIGHT = 12;

const string TMConferenceRooms::Impl::COMBO_BOX_INITIAL_VALUE = "---";

TMConferenceRooms::Impl::Impl(CgiRoot *cgi) : WObject()
{
    m_cgiRoot = cgi;
    m_lang = cgi->LangInstance;
}

void TMConferenceRooms::Impl::OnEndConfLinkClicked(WText *sender)
{
    wstring title = m_lang->GetString("CONF_ROOMS_MSG_END_CONF_TITLE");
    wstring msg = m_lang->GetString("CONF_ROOMS_MSG_END_CONF_MSG");

    m_msgBox = new WMessageBox(title, msg, Warning, NoButton);
    
    m_msgBox->addButton(m_lang->GetString("GENERAL_CONFIRM"), Ok);
    m_msgBox->addButton(m_lang->GetString("GENERAL_CANCEL"), Cancel);
    
    m_msgBox->buttonClicked().connect(this, &TMConferenceRooms::Impl::OnEndConfLinkClickedMsgBoxOK);

    m_msgBox->show();
}

void TMConferenceRooms::Impl::OnEndConfLinkClickedMsgBoxOK(StandardButton result)
{
    if (result == Ok) {
        
    }
    
    delete m_msgBox;
    m_msgBox = NULL;    
}

void TMConferenceRooms::Impl::OnContinuousPresenceLinkClicked(WText *sender)
{
    if (sender->attributeValue("open").toUTF8() == "0") {
        sender->setAttributeValue("open", WString::fromUTF8("1"));
        dvContinuousPresence->clear();

        Div *root = new Div(dvContinuousPresence);

        Div *dvLayoutSelectionForm = new Div(root, "dvLayoutSelectionForm");
        WGridLayout *dvLayoutSelectionFormLayout = new WGridLayout();

        continuousPresenceLayoutCombo = new WComboBox();

        dvLayoutSelectionFormLayout->addWidget(new WText(m_lang->GetString("GENERAL_LAYOUT")),
                                                0, 0);

        dvLayoutSelectionFormLayout->addWidget(continuousPresenceLayoutCombo, 0, 1);

        dvLayoutSelectionFormLayout->setVerticalSpacing(11);
        dvLayoutSelectionFormLayout->setColumnStretch(0, 100);
        dvLayoutSelectionFormLayout->setColumnStretch(1, 200);
        dvLayoutSelectionForm->resize(300, WLength::Auto);
        dvLayoutSelectionForm->setLayout(dvLayoutSelectionFormLayout);

        dvParticipantsLayoutTable = new Div(root, "dvParticipantsLayoutTable");

        continuousPresenceLayoutCombo->addItem(COMBO_BOX_INITIAL_VALUE);
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_1"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_2_LEFT_RIGHT"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_2_TOP_BOTTOM"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_3_HORIZONTAL"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_3_VERTICAL"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_4"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_4_ACTIVE_VOICE"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_5"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_6_HORIZONTAL"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_6_VERTICAL"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_7"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_8"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_9"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_9_ACTIVE_VOICE"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_10"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_11"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_12"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_12_VERTICAL"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_13"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_14"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_15"));
        continuousPresenceLayoutCombo->addItem(m_lang->GetString("CONF_ROOMS_CP_PICS_16"));
        
        continuousPresenceLayoutCombo->sactivated().connect(this,
                                     &TMConferenceRooms::Impl::OnContinuousPresenceLayoutComboChanged);
    } else {
        sender->setAttributeValue("open", WString::fromUTF8("0"));
        dvContinuousPresence->clear();
    }
}

void TMConferenceRooms::Impl::OnContinuousPresenceLayoutComboChanged(WString item)
{
    if (COMBO_BOX_INITIAL_VALUE == item) {
        dvParticipantsLayoutTable->clear();
    } else {
        dvParticipantsLayoutTable->clear();
        dvParticipantsLayoutTable->addWidget(GetLayoutFromString(item));
        
        new WBreak(dvParticipantsLayoutTable);
        new WBreak(dvParticipantsLayoutTable);
    }
}

void TMConferenceRooms::Impl::OnAddParticipantLinkClicked(WText *sender)
{
    m_dlg = new WDialog(m_lang->GetString("CONF_ROOMS_DLG_ADD_PARTICIPANT_TITLE"));
    m_dlg->setModal(true);
    m_dlg->contents()->addWidget(GetAddParticipantForm());
    m_dlg->show();
    addParticipantNameEdit->setFocus();
}

void TMConferenceRooms::Impl::OnParticipantCall(Participant *sender)
{
    sender->OnCallCompleted();
}

void TMConferenceRooms::Impl::OnParticipantHangup(Participant *sender)
{
    sender->OnHangupCompleted();
}

void TMConferenceRooms::Impl::OnParticipantSetAsManager(Participant *sender)
{
    sender->OnSetAsManagerCompleted();
}

void TMConferenceRooms::Impl::OnParticipantSetAsSpeaker(Participant *sender)
{
    sender->OnSetAsSpeakerCompleted();
}

void TMConferenceRooms::Impl::OnParticipantView(Participant *sender)
{
    sender->OnViewCompleted();
}

void TMConferenceRooms::Impl::OnParticipantRemove(Participant *sender)
{
    sender->OnRemoveCompleted();
}

void TMConferenceRooms::Impl::OnParticipantMuteSpeaker(Participant *sender)
{
    sender->OnMuteSpeakerCompleted();
}

void TMConferenceRooms::Impl::OnParticipantMuteMic(Participant *sender)
{
    sender->OnMuteMicCompleted();
}

void TMConferenceRooms::Impl::OnParticipantRecieveVideo(Participant *sender)
{
    sender->OnRecieveVideoCompleted();
}

void TMConferenceRooms::Impl::OnParticipantSendVideo(Participant *sender)
{
    sender->OnSendVideoCompleted();
}

void TMConferenceRooms::Impl::OnParticipantAddToAddrBook(Participant *sender)
{
    sender->OnAddToAddrBookCompleted();
}

void TMConferenceRooms::Impl::OnAddParticipantLinkOK()
{
    if (!Participant::TerminalHash.empty()) {
        for (unordered_map<wstring, Participant *>::const_iterator it = Participant::TerminalHash.begin();
            it != Participant::TerminalHash.end(); ++it) {
                if (it->first == addParticipantAddrEdit->text().value()) {
                    return;
                }
        }
    }

    // Still there's no Conf name until IPC became avail, so I pass an empty string...
    Participant *p = new Participant(addParticipantNameEdit->text(),
                                    addParticipantAddrEdit->text(), "",
                                    m_lang);

    WSignalMapper<Participant *> *participantSignalMapper;

    participantSignalMapper = new WSignalMapper<Participant *>(this);
    participantSignalMapper->mapped().connect(this, &TMConferenceRooms::Impl::OnParticipantCall);
    participantSignalMapper->mapConnect(p->CallHandler(), p);

    participantSignalMapper = new WSignalMapper<Participant *>(this);
    participantSignalMapper->mapped().connect(this, &TMConferenceRooms::Impl::OnParticipantHangup);
    participantSignalMapper->mapConnect(p->HangupHandler(), p);

    participantSignalMapper = new WSignalMapper<Participant *>(this);
    participantSignalMapper->mapped().connect(this, &TMConferenceRooms::Impl::OnParticipantSetAsManager);
    participantSignalMapper->mapConnect(p->SetAsManagerHandler(), p);

    participantSignalMapper = new WSignalMapper<Participant *>(this);
    participantSignalMapper->mapped().connect(this, &TMConferenceRooms::Impl::OnParticipantSetAsSpeaker);
    participantSignalMapper->mapConnect(p->SetAsSpeakerHandler(), p);

    participantSignalMapper = new WSignalMapper<Participant *>(this);
    participantSignalMapper->mapped().connect(this, &TMConferenceRooms::Impl::OnParticipantView);
    participantSignalMapper->mapConnect(p->ViewHandler(), p);

    participantSignalMapper = new WSignalMapper<Participant *>(this);
    participantSignalMapper->mapped().connect(this, &TMConferenceRooms::Impl::OnParticipantRemove);
    participantSignalMapper->mapConnect(p->RemoveHandler(), p);

    participantSignalMapper = new WSignalMapper<Participant *>(this);
    participantSignalMapper->mapped().connect(this, &TMConferenceRooms::Impl::OnParticipantMuteSpeaker);
    participantSignalMapper->mapConnect(p->MuteSpeakerHandler(), p);

    participantSignalMapper = new WSignalMapper<Participant *>(this);
    participantSignalMapper->mapped().connect(this, &TMConferenceRooms::Impl::OnParticipantMuteMic);
    participantSignalMapper->mapConnect(p->MuteMicHandler(), p);

    participantSignalMapper = new WSignalMapper<Participant *>(this);
    participantSignalMapper->mapped().connect(this, &TMConferenceRooms::Impl::OnParticipantRecieveVideo);
    participantSignalMapper->mapConnect(p->RecieveVideoHandler(), p);

    participantSignalMapper = new WSignalMapper<Participant *>(this);
    participantSignalMapper->mapped().connect(this, &TMConferenceRooms::Impl::OnParticipantSendVideo);
    participantSignalMapper->mapConnect(p->SendVideoHandler(), p);

    participantSignalMapper = new WSignalMapper<Participant *>(this);
    participantSignalMapper->mapped().connect(this, &TMConferenceRooms::Impl::OnParticipantAddToAddrBook);
    participantSignalMapper->mapConnect(p->AddToAddrBookHandler(), p);

    dvParticipants->addWidget(p);
}

void TMConferenceRooms::Impl::OnAddParticipantLinkOKReturn()
{
    OnAddParticipantLinkOK();
    OnAddParticipantLinkReturn();
}
    
void TMConferenceRooms::Impl::OnAddParticipantLinkReturn()
{
    delete m_dlg;
    m_dlg = NULL;
}

void TMConferenceRooms::Impl::OnPhoneBookTableAddBtnClicked(WPushButton *sender)
{
    addParticipantNameEdit->setText(sender->attributeValue("name"));
    addParticipantAddrEdit->setText(sender->attributeValue("addr"));
}
    
WTable *TMConferenceRooms::Impl::GetLayoutFromString(WString layout)
{
    WTable *layoutTable = new WTable();

    if (m_lang->GetString("CONF_ROOMS_CP_PICS_1") == layout) {
        layoutTable->elementAt(0, 0)->addWidget(new ParticipantLayoutCell());

    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_2_LEFT_RIGHT") == layout) {
        for (size_t j = 0; j < 2; ++j)
            layoutTable->elementAt(0, j)->addWidget(new ParticipantLayoutCell());

    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_2_TOP_BOTTOM") == layout) {
        for (size_t i = 0; i < 2; ++i)
            layoutTable->elementAt(i, 0)->addWidget(new ParticipantLayoutCell());

    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_3_HORIZONTAL") == layout) {
        layoutTable->elementAt(0, 0)->addWidget(new ParticipantLayoutCell());
        for (size_t j = 0; j < 2; ++j)
            layoutTable->elementAt(1, j)->addWidget(new ParticipantLayoutCell());
        layoutTable->elementAt(0, 0)->setColumnSpan(2);

    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_3_VERTICAL") == layout) {
        layoutTable->elementAt(0, 0)->addWidget(new ParticipantLayoutCell());
        for (size_t i = 0; i < 2; ++i)
            layoutTable->elementAt(i, 1)->addWidget(new ParticipantLayoutCell());
        layoutTable->elementAt(0, 0)->setRowSpan(2);

    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_4") == layout) {
        for (size_t i = 0; i < 2; ++i)
            for (size_t j = 0; j < 2; ++j)
                layoutTable->elementAt(i, j)->addWidget(new ParticipantLayoutCell());

    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_4_ACTIVE_VOICE") == layout) {
        layoutTable->elementAt(0, 0)->addWidget(new ParticipantLayoutCell());
        for (size_t j = 0; j < 3; ++j)
            layoutTable->elementAt(1, j)->addWidget(new ParticipantLayoutCell());
        layoutTable->elementAt(0, 0)->setColumnSpan(3);

    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_5") == layout) {
        layoutTable->elementAt(0, 0)->addWidget(new ParticipantLayoutCell());
        for (size_t i = 1; i < 3; ++i)
            for (size_t j = 0; j < 2; ++j)
                layoutTable->elementAt(i, j)->addWidget(new ParticipantLayoutCell());
        layoutTable->elementAt(0, 0)->setColumnSpan(2);

    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_6_HORIZONTAL") == layout) {
        for (size_t i = 0; i < 2; ++i)
            for (size_t j = 0; j < 3; ++j)
                layoutTable->elementAt(i, j)->addWidget(new ParticipantLayoutCell());

    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_6_VERTICAL") == layout) {
        for (size_t i = 0; i < 3; ++i)
            for (size_t j = 0; j < 2; ++j)
                layoutTable->elementAt(i, j)->addWidget(new ParticipantLayoutCell());

    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_7") == layout) {
        layoutTable->elementAt(0, 0)->addWidget(new ParticipantLayoutCell());
        for (size_t i = 1; i < 4; ++i)
            for (size_t j = 0; j < 2; ++j)
                layoutTable->elementAt(i, j)->addWidget(new ParticipantLayoutCell());
        layoutTable->elementAt(0, 0)->setColumnSpan(2);
    
    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_8") == layout) {
        for (size_t i = 0; i < 2; ++i)
            for (size_t j = 0; j < 4; ++j)
                layoutTable->elementAt(i, j)->addWidget(new ParticipantLayoutCell());
    
    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_9") == layout) {
        for (size_t i = 0; i < 3; ++i)
            for (size_t j = 0; j < 3; ++j)
                layoutTable->elementAt(i, j)->addWidget(new ParticipantLayoutCell());
    
    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_9_ACTIVE_VOICE") == layout) {
        layoutTable->elementAt(0, 0)->addWidget(new ParticipantLayoutCell());
        for (size_t i = 1; i < 3; ++i)
            for (size_t j = 0; j < 4; ++j)
                layoutTable->elementAt(i, j)->addWidget(new ParticipantLayoutCell());
        layoutTable->elementAt(0, 0)->setColumnSpan(4);
    
    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_10") == layout) {
        layoutTable->elementAt(0, 0)->addWidget(new ParticipantLayoutCell());
        for (size_t i = 1; i < 4; ++i)
            for (size_t j = 0; j < 3; ++j)
                layoutTable->elementAt(i, j)->addWidget(new ParticipantLayoutCell());
        layoutTable->elementAt(0, 0)->setColumnSpan(3);

    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_11") == layout) {
        for (size_t j = 0; j < 4; ++j)
            layoutTable->elementAt(0, j)->addWidget(new ParticipantLayoutCell());
        layoutTable->elementAt(1, 0)->addWidget(new ParticipantLayoutCell());
        layoutTable->elementAt(1, 1)->addWidget(new ParticipantLayoutCell());
        layoutTable->elementAt(1, 3)->addWidget(new ParticipantLayoutCell());
        for (size_t j = 0; j < 4; ++j)
            layoutTable->elementAt(2, j)->addWidget(new ParticipantLayoutCell());
        layoutTable->elementAt(1, 1)->setColumnSpan(2);

    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_12") == layout) {
        for (size_t i = 0; i < 3; ++i)
            for (size_t j = 0; j < 4; ++j)
                layoutTable->elementAt(i, j)->addWidget(new ParticipantLayoutCell());
    
    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_12_VERTICAL") == layout) {
        for (size_t i = 0; i < 6; ++i)
            for (size_t j = 0; j < 2; ++j)
                layoutTable->elementAt(i, j)->addWidget(new ParticipantLayoutCell());
    
    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_13") == layout) {
        layoutTable->elementAt(0, 0)->addWidget(new ParticipantLayoutCell());
        for (size_t i = 1; i < 4; ++i)
            for (size_t j = 0; j < 4; ++j)
                layoutTable->elementAt(i, j)->addWidget(new ParticipantLayoutCell());
        layoutTable->elementAt(0, 0)->setColumnSpan(4);
    
    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_14") == layout) {
        for (size_t j = 0; j < 3; j += 2)
            layoutTable->elementAt(0, j)->addWidget(new ParticipantLayoutCell());
        for (size_t i = 1; i < 4; ++i)
            for (size_t j = 0; j < 4; ++j)
                layoutTable->elementAt(i, j)->addWidget(new ParticipantLayoutCell());
        layoutTable->elementAt(0, 0)->setColumnSpan(2);
        layoutTable->elementAt(0, 2)->setColumnSpan(2);
    
    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_15") == layout) {
        for (size_t i = 0; i < 3; ++i)
            for (size_t j = 0; j < 5; ++j)
                layoutTable->elementAt(i, j)->addWidget(new ParticipantLayoutCell());
    
    } else if (m_lang->GetString("CONF_ROOMS_CP_PICS_16") == layout) {
        for (size_t i = 0; i < 4; ++i)
            for (size_t j = 0; j < 4; ++j)
                layoutTable->elementAt(i, j)->addWidget(new ParticipantLayoutCell());
    }
    
    return layoutTable;
}

WWidget *TMConferenceRooms::Impl::GetAddParticipantForm()
{
    Div *root = new Div("AddParticipantForm");

    Div *dvTable = new Div(root);
    
    dvTable->setOverflow(OverflowAuto, Vertical);
    dvTable->resize(400, 200);

    GetContactsCommand cmd(Base::MCU_MANAGER_URL);

    WTable *contactsTable = new WTable();
    contactsTable->setStyleClass("tbl");
    contactsTable->resize(400, WLength::Auto);

    contactsTable->elementAt(0, 0)->addWidget(new WText(m_lang->GetString("GENERAL_INDEX")));
    contactsTable->elementAt(0, 0)->resize(50, WLength::Auto);
    contactsTable->elementAt(0, 1)->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_PARTICIPANT_NAME_TEXT")));
    contactsTable->elementAt(0, 2)->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_PARTICIPANT_ADDRESS_TEXT")));
    contactsTable->elementAt(0, 3)->addWidget(new WText());
    contactsTable->elementAt(0, 3)->resize(50, WLength::Auto);
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
            signalMapper->mapped().connect(this, &TMConferenceRooms::Impl::OnPhoneBookTableAddBtnClicked);
            signalMapper->mapConnect(btn->clicked(), btn);
        }
    }
    
    dvTable->addWidget(contactsTable);
    

    Div *dvForm = new Div(root);
    WGridLayout *dvFormLayout = new WGridLayout();

    dvFormLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_PARTICIPANT_NAME_TEXT")),
                                      0, 0);
    dvFormLayout->addWidget(new WText(m_lang->GetString("CONF_MGMT_CREATE_PARTICIPANT_ADDRESS_TEXT")),
                                      1, 0);

    addParticipantNameEdit = new WLineEdit();
    addParticipantAddrEdit = new WLineEdit();

    WLengthValidator *nameValidator = new WLengthValidator(1, 255);
    nameValidator->setMandatory(true);
    addParticipantNameEdit->setValidator(nameValidator);

    WRegExpValidator *addrValidator = new WRegExpValidator(Base::REGEX_IP);
    addrValidator->setMandatory(true);
    addParticipantAddrEdit->setValidator(addrValidator);

    dvFormLayout->addWidget(addParticipantNameEdit, 0, 1);
    dvFormLayout->addWidget(addParticipantAddrEdit, 1, 1);

    dvFormLayout->setColumnStretch(0, 100);
    dvFormLayout->setColumnStretch(1, 200);
    dvFormLayout->setVerticalSpacing(11);
    dvForm->setLayout(dvFormLayout);

    
    Div *dvButtons = new Div(root);
    WPushButton *addButton = new WPushButton(m_lang->GetString("GENERAL_ADD"), dvButtons);
    WPushButton *addReturnButton = new WPushButton(m_lang->GetString("GENERAL_ADD_RETURN"), dvButtons);
    WPushButton *returnButton = new WPushButton(m_lang->GetString("GENERAL_RETURN"), dvButtons);
    
    addButton->setStyleClass("dialogButton");
    addReturnButton->setStyleClass("dialogButton");
    returnButton->setStyleClass("dialogButton");

    addParticipantNameEdit->enterPressed().connect(this, &TMConferenceRooms::Impl::OnAddParticipantLinkOK);
    addParticipantAddrEdit->enterPressed().connect(this, &TMConferenceRooms::Impl::OnAddParticipantLinkOK);
    addButton->clicked().connect(this, &TMConferenceRooms::Impl::OnAddParticipantLinkOK);
    addReturnButton->clicked().connect(this, &TMConferenceRooms::Impl::OnAddParticipantLinkOKReturn);
    returnButton->clicked().connect(this, &TMConferenceRooms::Impl::OnAddParticipantLinkReturn);

    return root;
}


/**********************************
*    = Constructos =
**********************************/

TMConferenceRooms::TMConferenceRooms(CgiRoot *cgi) : BaseWidget(cgi), m_pimpl(new Impl(cgi))
{
/*DANGEROUS TEMPO HACK - START*/
    delete Participant::ManagerTerminal;
    delete Participant::SpeakerTerminal;
    
    Participant::ManagerTerminal = NULL;
    Participant::SpeakerTerminal = NULL;

    for (unordered_map<wstring, Participant *>::iterator it = Participant::TerminalHash.begin();
        it != Participant::TerminalHash.end(); ++it) {
            delete it->second;
            it->second = NULL;
            Participant::TerminalHash.erase(it);
    }
/*DANGEROUS TEMPO HACK - START*/


    this->clear();
    this->addWidget(Layout());
}


/**********************************
*    = Destructor =
**********************************/

TMConferenceRooms::~TMConferenceRooms()
{
    delete Participant::ManagerTerminal;
    delete Participant::SpeakerTerminal;
    
    Participant::ManagerTerminal = NULL;
    Participant::SpeakerTerminal = NULL;

    for (unordered_map<wstring, Participant *>::iterator it = Participant::TerminalHash.begin();
        it != Participant::TerminalHash.end(); ++it) {
            delete it->second;
            it->second = NULL;
            Participant::TerminalHash.erase(it);
    }
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

WWidget *TMConferenceRooms::Layout()
{
    Div *root = new Div("TMConferenceRooms");

    Div *dvContents = new Div(root, "dvContents");
    WStackedWidget *dvContentsInner = new WStackedWidget(dvContents);
    dvContentsInner->setId("dvContentsInner");
    Div *wrapper = new Div(dvContentsInner);

    Div *dvManageConfBar = new Div(wrapper, "dvConfRoomsManageConfBar");
    WTable *manageConfBarTable = new WTable(dvManageConfBar);
    
    Div *dvParticipantsList = new Div(wrapper, "dvConfRoomsParticipantsList");
    Div *dvSidePane = new Div(wrapper, "dvConfRoomsSidePane");
    Div *dvCPForm = new Div(dvParticipantsList);

    WGroupBox *confInfoGroup = new WGroupBox(m_lang->GetString("CONF_ROOMS_CONF_INFO"), dvSidePane);
    WGroupBox *mtInfoGroup = new WGroupBox(m_lang->GetString("CONF_ROOMS_MT_INFO"), dvSidePane);

    WGridLayout *confInfoLayout = new WGridLayout();
    confInfoLayout->setColumnStretch(0, 75);
    confInfoLayout->setColumnStretch(1, 125);
    confInfoLayout->setVerticalSpacing(11);
    confInfoGroup->setLayout(confInfoLayout, AlignTop | AlignJustify);

    WGridLayout *mtInfoLayout = new WGridLayout();
    mtInfoLayout->setColumnStretch(0, 75);
    mtInfoLayout->setColumnStretch(1, 125);
    mtInfoLayout->setVerticalSpacing(11);
    mtInfoGroup->setLayout(mtInfoLayout, AlignTop | AlignJustify);


    /******************************
    ** Adding SidePane Labels
    ******************************/
    
    confInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_CONF_LIST")), 0, 0);
    confInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_CONF_RATE")), 1, 0);
    confInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_E164ID")), 2, 0);

    mtInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_MT_ALIAS")), 0, 0);
    mtInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_E164ID")), 1, 0);
    mtInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_IP_ADDR")), 2, 0);
    mtInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_CALL_MODE")), 3, 0);
    mtInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_TX_RATE")), 4, 0);
    mtInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_RX_RATE")), 5, 0);
    mtInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_MT_CALL_RATE")), 6, 0);
    mtInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_AUDIO_SRC")), 7, 0);
    mtInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_VIDEO_SRC")), 8, 0);
    mtInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_MT_STATUS")), 9, 0);
    mtInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_MUTE")), 10, 0);
    mtInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_DUMB")), 11, 0);
    mtInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_VOL_IN")), 12, 0);
    mtInfoLayout->addWidget(new WText(m_lang->GetString("CONF_ROOMS_VOL_OUT")), 13, 0);


    /******************************
    ** Adding SidePane Widgets
    ******************************/

    m_pimpl->confListCombo = new WComboBox();
    m_pimpl->confRateEdit = new WLineEdit();
    m_pimpl->confInfoE164IdEdit = new WLineEdit();
    m_pimpl->mtAliasEdit = new WLineEdit();
    m_pimpl->mtInfoE164IdEdit = new WLineEdit();
    m_pimpl->ipAddrEdit = new WLineEdit();
    m_pimpl->callModeEdit = new WLineEdit();
    m_pimpl->txRateEdit = new WLineEdit();
    m_pimpl->rxRateEdit = new WLineEdit();
    m_pimpl->mtCallRateEdit = new WLineEdit();
    m_pimpl->audioSrcEdit = new WLineEdit();
    m_pimpl->videoSrcEdit = new WLineEdit();
    m_pimpl->mtStatusEdit = new WTextArea();
    m_pimpl->muteCheck = new WCheckBox();
    m_pimpl->dumbCheck = new WCheckBox();
    m_pimpl->volInSpin = new WSpinBox();
    m_pimpl->volOutSpin = new WSpinBox();

    m_pimpl->volInSpin->setMinimum(0);
    m_pimpl->volInSpin->setMaximum(100);
    m_pimpl->volOutSpin->setMinimum(0);
    m_pimpl->volOutSpin->setMaximum(100);
    
    m_pimpl->confRateEdit->setReadOnly(true);
    m_pimpl->confInfoE164IdEdit->setReadOnly(true);
    m_pimpl->mtAliasEdit->setReadOnly(true);
    m_pimpl->mtInfoE164IdEdit->setReadOnly(true);
    m_pimpl->ipAddrEdit->setReadOnly(true);
    m_pimpl->callModeEdit->setReadOnly(true);
    m_pimpl->txRateEdit->setReadOnly(true);
    m_pimpl->rxRateEdit->setReadOnly(true);
    m_pimpl->mtCallRateEdit->setReadOnly(true);
    m_pimpl->audioSrcEdit->setReadOnly(true);
    m_pimpl->videoSrcEdit->setReadOnly(true);
    m_pimpl->mtStatusEdit->setReadOnly(true);

    confInfoLayout->addWidget(m_pimpl->confListCombo, 0, 1);
    confInfoLayout->addWidget(m_pimpl->confRateEdit, 1, 1);
    confInfoLayout->addWidget(m_pimpl->confInfoE164IdEdit, 2, 1);

    mtInfoLayout->addWidget(m_pimpl->mtAliasEdit, 0, 1);
    mtInfoLayout->addWidget(m_pimpl->mtInfoE164IdEdit, 1, 1);
    mtInfoLayout->addWidget(m_pimpl->ipAddrEdit, 2, 1);
    mtInfoLayout->addWidget(m_pimpl->callModeEdit, 3, 1);
    mtInfoLayout->addWidget(m_pimpl->txRateEdit, 4, 1);
    mtInfoLayout->addWidget(m_pimpl->rxRateEdit, 5, 1);
    mtInfoLayout->addWidget(m_pimpl->mtCallRateEdit, 6, 1);
    mtInfoLayout->addWidget(m_pimpl->audioSrcEdit, 7, 1);
    mtInfoLayout->addWidget(m_pimpl->videoSrcEdit, 8, 1);
    mtInfoLayout->addWidget(m_pimpl->mtStatusEdit, 9, 1);
    mtInfoLayout->addWidget(m_pimpl->muteCheck, 10, 1);
    mtInfoLayout->addWidget(m_pimpl->dumbCheck, 11, 1);
    mtInfoLayout->addWidget(m_pimpl->volInSpin, 12, 1);
    mtInfoLayout->addWidget(m_pimpl->volOutSpin, 13, 1);

    /******************************
    ** Terminate Conference
    ******************************/

    WText *endConfLink = new WText(m_lang->GetString("CONF_ROOMS_END_CONF"));
    endConfLink->setStyleClass("link");
    manageConfBarTable->elementAt(0, 0)->addWidget(endConfLink);

    WSignalMapper<WText *> *endConfMap = new WSignalMapper<WText *>(this);
    endConfMap->mapped().connect(m_pimpl.get(), &TMConferenceRooms::Impl::OnEndConfLinkClicked);
    endConfMap->mapConnect(endConfLink->clicked(), endConfLink);
  
    /******************************
    ** Continuous Presence
    ******************************/

    WText *continuousPresenceLink = new WText(m_lang->GetString("CONF_ROOMS_CONTINUOUS_PRESENCE"));
    continuousPresenceLink->setStyleClass("link");
    continuousPresenceLink->setAttributeValue("open", WString::fromUTF8("0"));
    manageConfBarTable->elementAt(0, 1)->addWidget(continuousPresenceLink);

    WSignalMapper<WText *> *continuousPresenceMap = new WSignalMapper<WText *>(this);
    continuousPresenceMap->mapped().connect(m_pimpl.get(), &TMConferenceRooms::Impl::OnContinuousPresenceLinkClicked);
    continuousPresenceMap->mapConnect(continuousPresenceLink->clicked(), continuousPresenceLink);
    m_pimpl->dvContinuousPresence = new Div(dvCPForm);

    new WBreak(dvParticipantsList);

    /******************************
    ** Add Participant Link
    ******************************/

    WText *addParticipantLink = new WText(m_lang->GetString("CONF_ROOMS_ADD_PARTICIPANT"));
    addParticipantLink->setStyleClass("link");
    manageConfBarTable->elementAt(0, 2)->addWidget(addParticipantLink);

    WSignalMapper<WText *> *addParticipantMap = new WSignalMapper<WText *>(this);
    addParticipantMap->mapped().connect(m_pimpl.get(), &TMConferenceRooms::Impl::OnAddParticipantLinkClicked);
    addParticipantMap->mapConnect(addParticipantLink->clicked(), addParticipantLink);

    /******************************
    ** LEGENDS
    ******************************/

    WCssDecorationStyle legendStyle;
    WColor legendBorderColor(0, 0, 0);
    WColor disconnectLegendBgColor(0, 0, 0);
    WColor incallLegendBgColor(0, 153, 0);
    WColor managerLegendBgColor(153, 0, 0);
    WColor speakerLegendBgColor(0, 0, 153);
    WBorder legendBorder(WBorder::Solid, WBorder::Thin, legendBorderColor);
    legendStyle.setBorder(legendBorder, All);

    Div *dvLegends = new Div(dvParticipantsList, "dvConfRoomsLegends");
    WTable *legendsTable = new WTable(dvLegends);
    

    legendStyle.setBackgroundColor(disconnectLegendBgColor);
    WTable *disconnectLegendTable = new WTable();
    Div *dvDisconnectLegend = new Div();
    dvDisconnectLegend->resize(m_pimpl->LEGEND_SIZE_WIDTH, m_pimpl->LEGEND_SIZE_HEIGHT);
    dvDisconnectLegend->setDecorationStyle(legendStyle);
    disconnectLegendTable->elementAt(0, 0)->addWidget(dvDisconnectLegend);
    disconnectLegendTable->elementAt(0, 1)->addWidget(
                        new WText(m_lang->GetString("CONF_ROOMS_LEGEND_DISCONNECT")));

    legendStyle.setBackgroundColor(incallLegendBgColor);
    WTable *incallLegendTable = new WTable();
    Div *dvIncallLegend = new Div();
    dvIncallLegend->resize(m_pimpl->LEGEND_SIZE_WIDTH, m_pimpl->LEGEND_SIZE_HEIGHT);
    dvIncallLegend->setDecorationStyle(legendStyle);
    incallLegendTable->elementAt(0, 0)->addWidget(dvIncallLegend);
    incallLegendTable->elementAt(0, 1)->addWidget(
                        new WText(m_lang->GetString("CONF_ROOMS_LEGEND_INCALL")));

    legendStyle.setBackgroundColor(managerLegendBgColor);
    WTable *managerLegendTable = new WTable();
    Div *dvManagerLegend = new Div();
    dvManagerLegend->resize(m_pimpl->LEGEND_SIZE_WIDTH, m_pimpl->LEGEND_SIZE_HEIGHT);
    dvManagerLegend->setDecorationStyle(legendStyle);
    managerLegendTable->elementAt(0, 0)->addWidget(dvManagerLegend);
    managerLegendTable->elementAt(0, 1)->addWidget(
                        new WText(m_lang->GetString("CONF_ROOMS_LEGEND_MANAGER")));

    legendStyle.setBackgroundColor(speakerLegendBgColor);
    WTable *speakerLegendTable = new WTable();
    Div *dvSpeakerLegend = new Div();
    dvSpeakerLegend->resize(m_pimpl->LEGEND_SIZE_WIDTH, m_pimpl->LEGEND_SIZE_HEIGHT);
    dvSpeakerLegend->setDecorationStyle(legendStyle);
    speakerLegendTable->elementAt(0, 0)->addWidget(dvSpeakerLegend);
    speakerLegendTable->elementAt(0, 1)->addWidget(
                        new WText(m_lang->GetString("CONF_ROOMS_LEGEND_SPEAKER")));

    legendsTable->elementAt(0, 0)->addWidget(disconnectLegendTable);
    legendsTable->elementAt(0, 1)->addWidget(incallLegendTable);
    legendsTable->elementAt(0, 2)->addWidget(managerLegendTable);
    legendsTable->elementAt(0, 3)->addWidget(speakerLegendTable);

    new WBreak(dvParticipantsList);

    /******************************
    ** PARTICIPANTS
    ******************************/

    m_pimpl->dvParticipants = new Div(dvParticipantsList, "dvConfRoomsParticipants");
    
  
    ///// THIS IS TEMPORARY HACK UNTIL IPC BECAME AVAIL,
    m_pimpl->addParticipantNameEdit = new WLineEdit();
    m_pimpl->addParticipantAddrEdit = new WLineEdit();
    m_pimpl->addParticipantNameEdit->setText("Majid");
    m_pimpl->addParticipantAddrEdit->setText("192.168.1.12");
    m_pimpl->OnAddParticipantLinkOK();
    m_pimpl->addParticipantNameEdit->setText("Morteza");
    m_pimpl->addParticipantAddrEdit->setText("192.168.1.15");
    m_pimpl->OnAddParticipantLinkOK();
    m_pimpl->addParticipantNameEdit->setText("Alireza");
    m_pimpl->addParticipantAddrEdit->setText("192.168.1.20");
    m_pimpl->OnAddParticipantLinkOK();

    //m_pimpl->TerminalHash[terminalId.value()] = participant001;


    return root;
}


/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


