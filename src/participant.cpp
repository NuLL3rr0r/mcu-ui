/**********************************
*    = Header File Inclusion =
**********************************/

#include <boost/algorithm/string.hpp>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WImage>
#include <Wt/WMessageBox>
#include <Wt/WPopupMenu>
#include <Wt/WSignalMapper>
#include <Wt/WString>
#include <Wt/WTable>
#include <Wt/WText>
#include "participant.hpp"
#include "lang.hpp"


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


/**********************************
*    = Constants =
**********************************/

const string Participant::ICON_DISCONNECT = "ico_participant_disconnect_96x96.png";
const string Participant::ICON_SHADOW = "ico_participant_shadow_64x64.png";
const string Participant::ICON_MANAGER = "ico_participant_manager_96x96.png";
const string Participant::ICON_SPEAKER = "ico_participant_speaker_96x96.png";
const string Participant::ICON_INCALL_PREFIX = "ico_participant_incall_";
const string Participant::ICON_INCALL_POSTFIX = "_96x96.png";


/**********************************
*    = Enumerations =
**********************************/

/**********************************
*    = Properties =
**********************************/

unordered_map<wstring, Participant *> Participant::TerminalHash;
Participant *Participant::ManagerTerminal = NULL;
Participant *Participant::SpeakerTerminal = NULL;


/**********************************
*    = Fields =
**********************************/

/**********************************
*    = Constructos =
**********************************/

Participant::Participant(Wt::WString name, Wt::WString addr, Wt::WString conf, Lang_ptr lang)
    : WContainerWidget(),
            m_name(name),
            m_addr(addr),
            m_conf(conf),
            m_lang(lang),
            m_callHandler(this),
            m_hangupHandler(this),
            m_setAsManagerHandler(this),
            m_setAsSpeakerHandler(this),
            m_viewHandler(this),
            m_removeHandler(this),
            m_muteSpeakerHandler(this),
            m_muteMicHandler(this),
            m_recieveVideoHandler(this),
            m_sendVideoHandler(this),
            m_addToAddrBookHandler(this)
{
    setInline(true);

    WTable *table = new WTable(this);
    table->setInline(true);

    m_icon = new WImage(ICON_DISCONNECT);
    m_nameLabel = new WText(m_name);
    m_addrLabel = new WText(m_addr);
    
    m_icon->setAttributeValue("name", m_name);
    m_icon->setAttributeValue("addr", m_addr);
    m_icon->setAttributeValue("conf", m_conf);

    table->elementAt(0, 0)->addWidget(m_icon);
    table->elementAt(1, 0)->addWidget(m_nameLabel);
    table->elementAt(2, 0)->addWidget(m_addrLabel);
    
    for (int r = 0; r < table->rowCount(); ++r) {
        table->elementAt(r, 0)->setContentAlignment(AlignCenter | AlignMiddle);
        table->elementAt(r, 0)->setVerticalAlignment(AlignCenter | AlignMiddle, WLength::Auto);
    }

    WImage *shadow = new WImage(ICON_SHADOW, this);
    m_icon->setDraggable("participant-icon", shadow, true);
    
    SetContextMenu();
    
    TerminalHash[m_addr.value()] = this;
}


/**********************************
*    = Destructor =
**********************************/

Participant::~Participant()
{
    // Since this object is deleting right now we won't have to delete it again!!
    // Just making the pointer null
    TerminalHash[m_addr.value()] = NULL;

    if (ManagerTerminal == this)
        ManagerTerminal = NULL;
    if (SpeakerTerminal == this)
        SpeakerTerminal = NULL;

    for (unordered_map<wstring, Participant *>::iterator it = TerminalHash.begin();
        it != TerminalHash.end(); ++it) {
            if (it->first == m_addr.value()) {
                TerminalHash.erase(it);
            }
    }
}


/**********************************
*    = Public Methods =
**********************************/

/**********************************
*    = Event Handlers =
**********************************/

Signal<> &Participant::CallHandler()
{
    return m_callHandler;
}

Signal<> &Participant::HangupHandler()
{
    return m_hangupHandler;
}

Signal<> &Participant::SetAsManagerHandler()
{
    return m_setAsManagerHandler;
}

Signal<> &Participant::SetAsSpeakerHandler()
{
    return m_setAsSpeakerHandler;
}

Signal<> &Participant::ViewHandler()
{
    return m_viewHandler;
}

Signal<> &Participant::RemoveHandler()
{
    return m_removeHandler;
}

Signal<> &Participant::MuteSpeakerHandler()
{
    return m_muteSpeakerHandler;
}

Signal<> &Participant::MuteMicHandler()
{
    return m_muteMicHandler;
}

Signal<> &Participant::RecieveVideoHandler()
{
    return m_recieveVideoHandler;
}

Signal<> &Participant::SendVideoHandler()
{
    return m_sendVideoHandler;
}

Signal<> &Participant::AddToAddrBookHandler()
{
    return m_addToAddrBookHandler;
}

void Participant::OnCallHangupClicked(WPopupMenuItem *sender)
{
    if (sender->text() == m_lang->GetString("CONF_ROOMS_PRTCPNT_CTX_CALL")) {
        m_callHandler.emit();
    }
    else {
        m_hangupHandler.emit();
    }
}

void Participant::OnSetAsManagerClicked(WPopupMenuItem *sender)
{
    sender->setChecked(!sender->isChecked());
    m_setAsManagerHandler.emit();
}

void Participant::OnSetAsSpeakerClicked(WPopupMenuItem *sender)
{
    sender->setChecked(!sender->isChecked());
    m_setAsSpeakerHandler.emit();
}

void Participant::OnViewClicked(WPopupMenuItem *sender)
{
    sender->setChecked(!sender->isChecked());
    m_viewHandler.emit();
}

void Participant::OnRemoveClicked(WPopupMenuItem *sender)
{
    wstring title = m_lang->GetString("CONF_ROOMS_PRTCPNT_MSG_ERASE_TITLE");
    wstring msg = m_lang->GetString("CONF_ROOMS_PRTCPNT_MSG_ERASE_MSG");

    boost::algorithm::replace_all(title, Lang::REPLACE_KEY_TERMINAL_ID, m_name.value());
    boost::algorithm::replace_all(msg, Lang::REPLACE_KEY_TERMINAL_ID, m_name.value());

    m_msgBox = new WMessageBox(title, msg, Warning, NoButton);
    
    m_msgBox->addButton(m_lang->GetString("GENERAL_CONFIRM"), Ok);
    m_msgBox->addButton(m_lang->GetString("GENERAL_CANCEL"), Cancel);
    
    m_msgBox->buttonClicked().connect(this, &Participant::OnRemoveClickedMsgBoxOK);
        
    m_msgBox->show();
}

void Participant::OnRemoveClickedMsgBoxOK(StandardButton result)
{
    if (result == Ok) {
        m_removeHandler.emit();
    }
    
    delete m_msgBox;
    m_msgBox = NULL;
}

void Participant::OnMuteSpeakerClicked(WPopupMenuItem *sender)
{
    sender->setChecked(!sender->isChecked());
    m_muteSpeakerHandler.emit();
}

void Participant::OnMuteMicClicked(WPopupMenuItem *sender)
{
    sender->setChecked(!sender->isChecked());
    m_muteMicHandler.emit();
}

void Participant::OnRecieveVideoClicked(WPopupMenuItem *sender)
{
    sender->setChecked(!sender->isChecked());
    m_recieveVideoHandler.emit();
}

void Participant::OnSendVideoClicked(WPopupMenuItem *sender)
{
    sender->setChecked(!sender->isChecked());
    m_sendVideoHandler.emit();
}

void Participant::OnAddToAddrBookClicked(WPopupMenuItem *sender)
{
    m_addToAddrBookHandler.emit();
}

void Participant::OnCallCompleted()
{
    m_ctxItemCallHangup->setText(m_lang->GetString("CONF_ROOMS_PRTCPNT_CTX_HANGUP"));
    m_icon->setImageLink(GetInCallIcon());
    m_ctxItemSetAsManager->setDisabled(false);
    m_ctxItemSetAsSpeaker->setDisabled(false);
    m_ctxItemView->setDisabled(false);
    m_ctxItemMuteSpeaker->setDisabled(false);
    m_ctxItemMuteMic->setDisabled(false);
    m_ctxItemRecieveVideo->setDisabled(false);
    m_ctxItemSendVideo->setDisabled(false);

    m_ctxItemSetAsManager->setChecked(false);
    m_ctxItemSetAsSpeaker->setChecked(false);
    m_ctxItemView->setChecked(false);
    m_ctxItemMuteSpeaker->setChecked(true);
    m_ctxItemMuteMic->setChecked(true);
    m_ctxItemRecieveVideo->setChecked(true);
    m_ctxItemSendVideo->setChecked(true);
}

void Participant::OnHangupCompleted()
{
    m_ctxItemCallHangup->setText(m_lang->GetString("CONF_ROOMS_PRTCPNT_CTX_CALL"));
    m_icon->setImageLink(ICON_DISCONNECT);
    m_ctxItemSetAsManager->setDisabled(true);
    m_ctxItemSetAsSpeaker->setDisabled(true);
    m_ctxItemView->setDisabled(true);
    m_ctxItemMuteSpeaker->setDisabled(true);
    m_ctxItemMuteMic->setDisabled(true);
    m_ctxItemRecieveVideo->setDisabled(true);
    m_ctxItemSendVideo->setDisabled(true);

    m_ctxItemSetAsManager->setChecked(false);
    m_ctxItemSetAsSpeaker->setChecked(false);
    m_ctxItemView->setChecked(false);
    m_ctxItemMuteSpeaker->setChecked(true);
    m_ctxItemMuteMic->setChecked(true);
    m_ctxItemRecieveVideo->setChecked(true);
    m_ctxItemSendVideo->setChecked(true);
}

void Participant::OnSetAsManagerCompleted()
{
    m_ctxItemSetAsManager->setChecked(!m_ctxItemSetAsManager->isChecked());
    
    if (m_ctxItemSetAsManager->isChecked()) {
        if (ManagerTerminal != NULL) {
            ManagerTerminal->OnSetAsManagerCompleted();
        }

        ManagerTerminal = this;

        m_icon->setImageLink(ICON_MANAGER);        
        m_ctxItemSetAsSpeaker->setDisabled(true);
        m_ctxItemMuteSpeaker->setDisabled(true);
        m_ctxItemMuteMic->setDisabled(true);
        m_ctxItemRecieveVideo->setDisabled(true);
        m_ctxItemSendVideo->setDisabled(true);
        m_ctxItemSetAsSpeaker->setChecked(false);
        m_ctxItemMuteSpeaker->setChecked(true);
        m_ctxItemMuteMic->setChecked(true);
        m_ctxItemRecieveVideo->setChecked(true);
        m_ctxItemSendVideo->setChecked(true);
    } else {
        ManagerTerminal = NULL;

        m_icon->setImageLink(GetInCallIcon());
        m_ctxItemSetAsManager->setDisabled(false);
        m_ctxItemSetAsSpeaker->setDisabled(false);
        m_ctxItemMuteSpeaker->setDisabled(false);
        m_ctxItemMuteMic->setDisabled(false);
        m_ctxItemRecieveVideo->setDisabled(false);
        m_ctxItemSendVideo->setDisabled(false);
        m_ctxItemSetAsManager->setChecked(false);
        m_ctxItemSetAsSpeaker->setChecked(false);
        m_ctxItemMuteSpeaker->setChecked(true);
        m_ctxItemMuteMic->setChecked(true);
        m_ctxItemRecieveVideo->setChecked(true);
        m_ctxItemSendVideo->setChecked(true);
    }
}

void Participant::OnSetAsSpeakerCompleted()
{
    m_ctxItemSetAsSpeaker->setChecked(!m_ctxItemSetAsSpeaker->isChecked());

    if (m_ctxItemSetAsSpeaker->isChecked()) {
        if (SpeakerTerminal != NULL) {
            SpeakerTerminal->OnSetAsSpeakerCompleted();
        }

        SpeakerTerminal = this;

        m_icon->setImageLink(ICON_SPEAKER);        
        m_ctxItemSetAsManager->setDisabled(true);
        m_ctxItemMuteSpeaker->setDisabled(true);
        m_ctxItemMuteMic->setDisabled(true);
        m_ctxItemRecieveVideo->setDisabled(true);
        m_ctxItemSendVideo->setDisabled(true);
        m_ctxItemSetAsManager->setChecked(false);
        m_ctxItemMuteSpeaker->setChecked(true);
        m_ctxItemMuteMic->setChecked(true);
        m_ctxItemRecieveVideo->setChecked(true);
        m_ctxItemSendVideo->setChecked(true);
    } else {
        SpeakerTerminal = NULL;

        m_icon->setImageLink(GetInCallIcon());
        m_ctxItemSetAsManager->setDisabled(false);
        m_ctxItemSetAsSpeaker->setDisabled(false);
        m_ctxItemMuteSpeaker->setDisabled(false);
        m_ctxItemMuteMic->setDisabled(false);
        m_ctxItemRecieveVideo->setDisabled(false);
        m_ctxItemSendVideo->setDisabled(false);
        m_ctxItemSetAsManager->setChecked(false);
        m_ctxItemSetAsSpeaker->setChecked(false);
        m_ctxItemMuteSpeaker->setChecked(true);
        m_ctxItemMuteMic->setChecked(true);
        m_ctxItemRecieveVideo->setChecked(true);
        m_ctxItemSendVideo->setChecked(true);
    }
}

void Participant::OnViewCompleted()
{
    m_ctxItemView->setChecked(!m_ctxItemView->isChecked());
}

void Participant::OnRemoveCompleted()
{
    delete this;
}

void Participant::OnMuteSpeakerCompleted()
{
    m_ctxItemMuteSpeaker->setChecked(!m_ctxItemMuteSpeaker->isChecked());
    m_icon->setImageLink(GetInCallIcon());
}

void Participant::OnMuteMicCompleted()
{
    m_ctxItemMuteMic->setChecked(!m_ctxItemMuteMic->isChecked());
    m_icon->setImageLink(GetInCallIcon());
}

void Participant::OnRecieveVideoCompleted()
{
    m_ctxItemRecieveVideo->setChecked(!m_ctxItemRecieveVideo->isChecked());
    m_icon->setImageLink(GetInCallIcon());
}

void Participant::OnSendVideoCompleted()
{
    m_ctxItemSendVideo->setChecked(!m_ctxItemSendVideo->isChecked());
    m_icon->setImageLink(GetInCallIcon());
}

void Participant::OnAddToAddrBookCompleted()
{
}


/**********************************
*    = Protected Methods =
**********************************/

/**********************************
*    = Private Methods =
**********************************/

void Participant::SetContextMenu()
{
    WPopupMenu *popup = new WPopupMenu();
    WPopupMenuItem *item;
    WSignalMapper<WPopupMenuItem *> *itemSignalMapper;

    item = popup->addItem(m_lang->GetString("CONF_ROOMS_PRTCPNT_CTX_CALL"));
    item->setAttributeValue("addr", m_addr);
    itemSignalMapper = new WSignalMapper<WPopupMenuItem *>(this);
    itemSignalMapper->mapped().connect(this, &Participant::OnCallHangupClicked);
    itemSignalMapper->mapConnect(item->triggered(), item);
    m_ctxItemCallHangup = item;

    item = popup->addItem(m_lang->GetString("CONF_ROOMS_PRTCPNT_CTX_SET_AS_MNGR"));
    item->setCheckable(true);
    item->setChecked(false);
    item->setDisabled(true);
    item->setAttributeValue("addr", m_addr);
    itemSignalMapper = new WSignalMapper<WPopupMenuItem *>(this);
    itemSignalMapper->mapped().connect(this, &Participant::OnSetAsManagerClicked);
    itemSignalMapper->mapConnect(item->triggered(), item);  
    m_ctxItemSetAsManager = item;  

    item = popup->addItem(m_lang->GetString("CONF_ROOMS_PRTCPNT_CTX_SET_AS_SPK"));
    item->setCheckable(true);
    item->setChecked(false);
    item->setDisabled(true);
    item->setAttributeValue("addr", m_addr);
    itemSignalMapper = new WSignalMapper<WPopupMenuItem *>(this);
    itemSignalMapper->mapped().connect(this, &Participant::OnSetAsSpeakerClicked);
    itemSignalMapper->mapConnect(item->triggered(), item);
    m_ctxItemSetAsSpeaker = item;

    item = popup->addItem(m_lang->GetString("CONF_ROOMS_PRTCPNT_CTX_VIEW"));
    item->setCheckable(true);
    item->setChecked(false);
    item->setDisabled(true);
    item->setAttributeValue("addr", m_addr);
    itemSignalMapper = new WSignalMapper<WPopupMenuItem *>(this);
    itemSignalMapper->mapped().connect(this, &Participant::OnViewClicked);
    itemSignalMapper->mapConnect(item->triggered(), item);
    m_ctxItemView = item;

    popup->addSeparator();

    item = popup->addItem(m_lang->GetString("CONF_ROOMS_PRTCPNT_CTX_RM_FROM_CONF"));
    item->setAttributeValue("addr", m_addr);
    itemSignalMapper = new WSignalMapper<WPopupMenuItem *>(this);
    itemSignalMapper->mapped().connect(this, &Participant::OnRemoveClicked);
    itemSignalMapper->mapConnect(item->triggered(), item);
    m_ctxItemRemove = item;

    popup->addSeparator();

    item = popup->addItem(m_lang->GetString("CONF_ROOMS_PRTCPNT_CTX_MUTE_SPK"));
    item->setCheckable(true);
    item->setChecked(true);
    item->setDisabled(true);
    item->setAttributeValue("addr", m_addr);
    itemSignalMapper = new WSignalMapper<WPopupMenuItem *>(this);
    itemSignalMapper->mapped().connect(this, &Participant::OnMuteSpeakerClicked);
    itemSignalMapper->mapConnect(item->triggered(), item);
    m_ctxItemMuteSpeaker = item;

    item = popup->addItem(m_lang->GetString("CONF_ROOMS_PRTCPNT_CTX_MUTE_MIC"));
    item->setCheckable(true);
    item->setChecked(true);
    item->setDisabled(true);
    item->setAttributeValue("addr", m_addr);
    itemSignalMapper = new WSignalMapper<WPopupMenuItem *>(this);
    itemSignalMapper->mapped().connect(this, &Participant::OnMuteMicClicked);
    itemSignalMapper->mapConnect(item->triggered(), item);
    m_ctxItemMuteMic = item;

    item = popup->addItem(m_lang->GetString("CONF_ROOMS_PRTCPNT_CTX_RECV_VID"));
    item->setCheckable(true);
    item->setChecked(true);
    item->setDisabled(true);
    item->setAttributeValue("addr", m_addr);
    itemSignalMapper = new WSignalMapper<WPopupMenuItem *>(this);
    itemSignalMapper->mapped().connect(this, &Participant::OnRecieveVideoClicked);
    itemSignalMapper->mapConnect(item->triggered(), item);
    m_ctxItemRecieveVideo = item;

    item = popup->addItem(m_lang->GetString("CONF_ROOMS_PRTCPNT_CTX_SEND_VID"));
    item->setCheckable(true);
    item->setChecked(true);
    item->setDisabled(true);
    item->setAttributeValue("addr", m_addr);
    itemSignalMapper = new WSignalMapper<WPopupMenuItem *>(this);
    itemSignalMapper->mapped().connect(this, &Participant::OnSendVideoClicked);
    itemSignalMapper->mapConnect(item->triggered(), item);
    m_ctxItemSendVideo = item;

    popup->addSeparator();

    item = popup->addItem(m_lang->GetString("CONF_ROOMS_PRTCPNT_CTX_ADD_TO_ADDR_BOOK"));
    item->setAttributeValue("addr", m_addr);
    itemSignalMapper = new WSignalMapper<WPopupMenuItem *>(this);
    itemSignalMapper->mapped().connect(this, &Participant::OnAddToAddrBookClicked);
    itemSignalMapper->mapConnect(item->triggered(), item);
    m_ctxItemAddToAddrBook = item;

    m_icon->clicked().connect(popup, &WPopupMenu::popup);
    m_icon->mouseWentUp().connect(popup, &WPopupMenu::popup);
    m_icon->setAttributeValue
        ("oncontextmenu",
                "event.cancelBubble = true; event.returnValue = false; return false;");
}

string Participant::GetInCallIcon()
{
    string icon(ICON_INCALL_PREFIX);

    icon += m_ctxItemMuteSpeaker->isChecked() ? "1" : "0";
    icon += m_ctxItemMuteMic->isChecked() ? "1" : "0";
    icon += m_ctxItemRecieveVideo->isChecked() ? "1" : "0";
    icon += m_ctxItemSendVideo->isChecked() ? "1" : "0";

    icon += ICON_INCALL_POSTFIX;

    return icon;
}


/**********************************
*    = Base Class Overrides =
**********************************/

/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


