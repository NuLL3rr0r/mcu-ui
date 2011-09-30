#ifndef TMCONFERENCEMANAGEMENTSMCREATECONFERENCE_HPP
#define TMCONFERENCEMANAGEMENTSMCREATECONFERENCE_HPP


#include <vector>
#include "basewidget.hpp"

namespace ControlConference {
    class TMConferenceManagementSMCreateConference;
}

class ControlConference::TMConferenceManagementSMCreateConference : public ControlConference::BaseWidget
{
private:
    Wt::WButtonGroup *m_conferenceTypeBtnGroup;
    Wt::WButtonGroup *m_gatekeeperBtnGroup;
    Wt::WButtonGroup *m_sipServerBtnGroup;
    Wt::WButtonGroup *m_endingTypeBtnGroup;

    Wt::WLineEdit *m_conferenceNameEdit;
    Wt::WLineEdit *m_conferenceNumberEdit;
    Wt::WLineEdit *m_gkAddressEdit;
    Wt::WLineEdit *m_gkUserEdit;
    Wt::WLineEdit *m_gkPassEdit;
    Wt::WLineEdit *m_sipAddressEdit;
    Wt::WLineEdit *m_sipUserEdit;
    Wt::WLineEdit *m_sipPassEdit;
    Wt::WLineEdit *m_conferenceDateEdit;
    Wt::WLineEdit *m_conferenceTimeEdit;
    Wt::WLineEdit *m_maxDurationEdit;
    Wt::WLineEdit *m_streamDestinationEdit;
    Wt::WLineEdit *m_newParticipantNameEdit;
    Wt::WLineEdit *m_newParticipantAddressEdit;

    Wt::WComboBox *m_signalingTypeCmb;
    Wt::WComboBox *m_outputSoundCodecCmb;
    Wt::WComboBox *m_outputVideoCodecCmb;
    Wt::WComboBox *m_outputRateCmb;

    Wt::WCheckBox *m_videoRes720pChk;
    Wt::WCheckBox *m_videoResCIFChk;
    Wt::WCheckBox *m_videoRes4CIFChk;
    Wt::WCheckBox *m_hasH239Chk;
    Wt::WCheckBox *m_externalUserChk;
    Wt::WCheckBox *m_sendToStreamServerChk;
    Wt::WCheckBox *m_addParticipantToAddrBookChk;

    Wt::WSpinBox *m_participantNumSpin;

    Wt::WTable *m_participantsTable;
    
    Div *m_dvSignalingTypeForm;
    Div *m_dvConferenceDateTimeForm;
    
    Wt::WDialog *m_dialogBox;
    
    std::vector<Wt::WPushButton *> m_participantsTableRemoveButtons;

public:
    TMConferenceManagementSMCreateConference(CgiRoot *cgi);
    ~TMConferenceManagementSMCreateConference();

private:
    void OnSignalingTypeCmbChanged(Wt::WString item);
    void OnConferenceTypeRadioGroupChanged(Wt::WRadioButton *);
    void OnSendToStreamChkChanged();
    void OnEndingTypeRadioGroupChanged(Wt::WRadioButton *);
    void OnAddParticipantBtnClicked();
    void OnPhoneBookBtnClicked();
    void OnPhoneBookDialogConfirmed();
    void OnPhoneBookTableAddBtnClicked(Wt::WPushButton *sender);
    void OnParticipantsTableRemoveBtnClicked(Wt::WPushButton *sender);
    
private:
    Wt::WWidget *GetPhoneBookForm();
    void AddContactToParticipantsTable(Wt::WString addr, Wt::WString name);

protected:
    Wt::WWidget *Layout();
};


#endif /* TMCONFERENCEMANAGEMENTSMCREATECONFERENCE_HPP */


