#ifndef PARTICIPANT_HPP
#define PARTICIPANT_HPP


#include <string>
#include <unordered_map>

namespace Wt {
    class WContainerWidget;
    class WImage;
    class WMessageBox;
    class WPopupMenuItem;
    class WString;
    class WText;

    enum StandardButton;
}

namespace ControlConference {
    class Participant;
    class Lang;
}

class ControlConference::Participant : public Wt::WContainerWidget
{
private:
    typedef std::shared_ptr<ControlConference::Lang> Lang_ptr;

private:
    static const std::string ICON_DISCONNECT;
    static const std::string ICON_SHADOW;
    static const std::string ICON_MANAGER;
    static const std::string ICON_SPEAKER;
    static const std::string ICON_INCALL_PREFIX;
    static const std::string ICON_INCALL_POSTFIX;

public:
    enum EIcon {
        EIcon_Disconnect,
        EIcon_InCall,
        EIcon_Manager,
        EIcon_Speaker
    };

public:
    static std::unordered_map<std::wstring, ControlConference::Participant *> TerminalHash;
    static ControlConference::Participant *ManagerTerminal;
    static ControlConference::Participant *SpeakerTerminal;

private:
    Wt::WString m_name;
    Wt::WString m_addr;
    Wt::WString m_conf;
    Wt::WImage *m_icon;
    Wt::WText *m_nameLabel;
    Wt::WText *m_addrLabel;

    Lang_ptr m_lang;
    
    Wt::WMessageBox *m_msgBox;

    Wt::Signal<> m_callHandler;
    Wt::Signal<> m_hangupHandler;
    Wt::Signal<> m_setAsManagerHandler;
    Wt::Signal<> m_setAsSpeakerHandler;
    Wt::Signal<> m_viewHandler;
    Wt::Signal<> m_removeHandler;
    Wt::Signal<> m_muteSpeakerHandler;
    Wt::Signal<> m_muteMicHandler;
    Wt::Signal<> m_recieveVideoHandler;
    Wt::Signal<> m_sendVideoHandler;
    Wt::Signal<> m_addToAddrBookHandler;
    
    Wt::WPopupMenuItem *m_ctxItemCallHangup;
    Wt::WPopupMenuItem *m_ctxItemSetAsManager;
    Wt::WPopupMenuItem *m_ctxItemSetAsSpeaker;
    Wt::WPopupMenuItem *m_ctxItemView;
    Wt::WPopupMenuItem *m_ctxItemRemove;
    Wt::WPopupMenuItem *m_ctxItemMuteSpeaker;
    Wt::WPopupMenuItem *m_ctxItemMuteMic;
    Wt::WPopupMenuItem *m_ctxItemRecieveVideo;
    Wt::WPopupMenuItem *m_ctxItemSendVideo;
    Wt::WPopupMenuItem *m_ctxItemAddToAddrBook;

public:
    Participant(Wt::WString name, Wt::WString addr, Wt::WString conf, Lang_ptr lang);
    ~Participant();

public:
    Wt::Signal<> &CallHandler();
    Wt::Signal<> &HangupHandler();
    Wt::Signal<> &SetAsManagerHandler();
    Wt::Signal<> &SetAsSpeakerHandler();
    Wt::Signal<> &ViewHandler();
    Wt::Signal<> &RemoveHandler();
    Wt::Signal<> &MuteSpeakerHandler();
    Wt::Signal<> &MuteMicHandler();
    Wt::Signal<> &RecieveVideoHandler();
    Wt::Signal<> &SendVideoHandler();
    Wt::Signal<> &AddToAddrBookHandler();

    void OnCallCompleted();
    void OnHangupCompleted();
    void OnSetAsManagerCompleted();
    void OnSetAsSpeakerCompleted();
    void OnViewCompleted();
    void OnRemoveCompleted();
    void OnMuteSpeakerCompleted();
    void OnMuteMicCompleted();
    void OnRecieveVideoCompleted();
    void OnSendVideoCompleted();
    void OnAddToAddrBookCompleted();

private:
    void OnCallHangupClicked(Wt::WPopupMenuItem *sender);
    void OnSetAsManagerClicked(Wt::WPopupMenuItem *sender);
    void OnSetAsSpeakerClicked(Wt::WPopupMenuItem *sender);
    void OnViewClicked(Wt::WPopupMenuItem *sender);
    void OnRemoveClicked(Wt::WPopupMenuItem *sender);
    void OnMuteSpeakerClicked(Wt::WPopupMenuItem *sender);
    void OnMuteMicClicked(Wt::WPopupMenuItem *sender);
    void OnRecieveVideoClicked(Wt::WPopupMenuItem *sender);
    void OnSendVideoClicked(Wt::WPopupMenuItem *sender);
    void OnAddToAddrBookClicked(Wt::WPopupMenuItem *sender);
    
    void OnRemoveClickedMsgBoxOK(Wt::StandardButton result);

private:
    void SetContextMenu();
    
    std::string GetInCallIcon();
};


#endif /* PARTICIPANT_HPP */


