/**********************************
*    = Header File Inclusion =
**********************************/

#include <unordered_map>
#include <string>
#include "lang.hpp"


/**********************************
*    = PreProcessor Directives =
**********************************/

/**********************************
*    = Importing NameSpaces =
**********************************/

using namespace std;
using namespace ControlConference;


/**********************************
*    = Constants =
**********************************/

const wstring Lang::REPLACE_KEY_TERMINAL_ID = L"{TERMINAL_ID}";


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

class Lang::Impl
{
public:
    static const std::wstring TEMPO_UNDER_CONSTRUCTION_EN;
    static const std::wstring TEMPO_UNDER_CONSTRUCTION_FA;

    static const std::wstring GENERAL_ACTIVE_EN;
    static const std::wstring GENERAL_ACTIVE_FA;
    static const std::wstring GENERAL_INACTIVE_EN;
    static const std::wstring GENERAL_INACTIVE_FA;
    static const std::wstring GENERAL_CONFIRM_EN;
    static const std::wstring GENERAL_CONFIRM_FA;
    static const std::wstring GENERAL_CANCEL_EN;
    static const std::wstring GENERAL_CANCEL_FA;

    static const std::wstring GENERAL_INDEX_EN;
    static const std::wstring GENERAL_INDEX_FA;
    
    static const std::wstring GENERAL_ERASE_EN;
    static const std::wstring GENERAL_ERASE_FA;
    static const std::wstring GENERAL_EDIT_EN;
    static const std::wstring GENERAL_EDIT_FA;

    static const std::wstring GENERAL_ADD_EN;
    static const std::wstring GENERAL_ADD_FA;
    static const std::wstring GENERAL_ADD_RETURN_EN;
    static const std::wstring GENERAL_ADD_RETURN_FA;
    static const std::wstring GENERAL_RETURN_EN;
    static const std::wstring GENERAL_RETURN_FA;
    
    static const std::wstring GENERAL_LAYOUT_EN;
    static const std::wstring GENERAL_LAYOUT_FA;

    static const std::wstring WARN_NO_SCRIPT_EN;
    static const std::wstring WARN_NO_SCRIPT_FA;
    
    static const std::wstring LOGIN_TITLE_EN;
    static const std::wstring LOGIN_TITLE_FA;
    
    static const std::wstring HOME_TITLE_EN;
    static const std::wstring HOME_TITLE_FA;

    static const std::wstring LOGIN_FORM_TITLE_EN;
    static const std::wstring LOGIN_FORM_TITLE_FA;
    static const std::wstring LOGIN_FORM_USER_TEXT_EN;
    static const std::wstring LOGIN_FORM_USER_TEXT_FA;
    static const std::wstring LOGIN_FORM_PWD_TEXT_EN;
    static const std::wstring LOGIN_FORM_PWD_TEXT_FA;
    static const std::wstring LOGIN_FORM_CAPTCHA_TEXT_EN;
    static const std::wstring LOGIN_FORM_CAPTCHA_TEXT_FA;
    static const std::wstring LOGIN_FORM_EMAIL_TEXT_EN;
    static const std::wstring LOGIN_FORM_EMAIL_TEXT_FA;
    static const std::wstring LOGIN_FORM_LOGIN_TEXT_EN;
    static const std::wstring LOGIN_FORM_LOGIN_TEXT_FA;
    static const std::wstring LOGIN_FORM_RECOVER_TEXT_EN;
    static const std::wstring LOGIN_FORM_RECOVER_TEXT_FA;
    static const std::wstring LOGIN_FORM_FORGOT_TEXT_EN;
    static const std::wstring LOGIN_FORM_FORGOT_TEXT_FA;
    
    static const std::wstring LOGIN_FORM_ERR_LOGIN_EN;
    static const std::wstring LOGIN_FORM_ERR_LOGIN_FA;
    static const std::wstring LOGIN_FORM_ERR_FORGOT_EN;
    static const std::wstring LOGIN_FORM_ERR_FORGOT_FA;
    static const std::wstring LOGIN_FORM_MSG_FORGOT_EN;
    static const std::wstring LOGIN_FORM_MSG_FORGOT_FA;
    
    static const std::wstring HML_WELCOME_EN;
    static const std::wstring HML_WELCOME_FA;
    static const std::wstring HML_SYSMON_EN;
    static const std::wstring HML_SYSMON_FA;
    static const std::wstring HML_USER_MANAGEMENT_EN;
    static const std::wstring HML_USER_MANAGEMENT_FA;
    static const std::wstring HML_SYSTEM_SETTINGS_EN;
    static const std::wstring HML_SYSTEM_SETTINGS_FA;
    static const std::wstring HML_MCU_SETTINGS_EN;
    static const std::wstring HML_MCU_SETTINGS_FA;
    static const std::wstring HML_CONFERENCE_ROOMS_EN;
    static const std::wstring HML_CONFERENCE_ROOMS_FA;
    static const std::wstring HML_CONFERENCE_MANAGEMENT_EN;
    static const std::wstring HML_CONFERENCE_MANAGEMENT_FA;
    static const std::wstring HML_EXIT_EN;
    static const std::wstring HML_EXIT_FA;

    static const std::wstring HML_CONFERENCE_MANAGEMENT_CREATE_CONFERENCE_EN;
    static const std::wstring HML_CONFERENCE_MANAGEMENT_CREATE_CONFERENCE_FA;
    static const std::wstring HML_CONFERENCE_MANAGEMENT_TEMPLATES_EN;
    static const std::wstring HML_CONFERENCE_MANAGEMENT_TEMPLATES_FA;
    static const std::wstring HML_CONFERENCE_MANAGEMENT_CONFERENCE_LIST_EN;
    static const std::wstring HML_CONFERENCE_MANAGEMENT_CONFERENCE_LIST_FA;
    static const std::wstring HML_CONFERENCE_MANAGEMENT_TERMINAL_MANAGEMENT_EN;
    static const std::wstring HML_CONFERENCE_MANAGEMENT_TERMINAL_MANAGEMENT_FA;

    static const std::wstring HML_MCU_SETTINGS_CODEC_SETTINGS_EN;
    static const std::wstring HML_MCU_SETTINGS_CODEC_SETTINGS_FA;
    static const std::wstring HML_MCU_SETTINGS_SIGNALING_SETTINGS_EN;
    static const std::wstring HML_MCU_SETTINGS_SIGNALING_SETTINGS_FA;
    static const std::wstring HML_MCU_SETTINGS_SIP_SERVER_SETTINGS_EN;
    static const std::wstring HML_MCU_SETTINGS_SIP_SERVER_SETTINGS_FA;
    static const std::wstring HML_MCU_SETTINGS_GATE_KEEPER_SETTINGS_EN;
    static const std::wstring HML_MCU_SETTINGS_GATE_KEEPER_SETTINGS_FA;
    static const std::wstring HML_MCU_SETTINGS_STUN_SETTINGS_EN;
    static const std::wstring HML_MCU_SETTINGS_STUN_SETTINGS_FA;
    static const std::wstring HML_MCU_SETTINGS_DSP_SETTINGS_EN;
    static const std::wstring HML_MCU_SETTINGS_DSP_SETTINGS_FA;

    static const std::wstring HML_SYSMON_GENERAL_INFO_EN;
    static const std::wstring HML_SYSMON_GENERAL_INFO_FA;
    static const std::wstring HML_SYSMON_SIGNALING_INFO_EN;
    static const std::wstring HML_SYSMON_SIGNALING_INFO_FA;
    static const std::wstring HML_SYSMON_CODEC_INFO_EN;
    static const std::wstring HML_SYSMON_CODEC_INFO_FA;
    static const std::wstring HML_SYSMON_SERVICES_INFO_EN;
    static const std::wstring HML_SYSMON_SERVICES_INFO_FA;
    static const std::wstring HML_SYSMON_DSP_INFO_EN;
    static const std::wstring HML_SYSMON_DSP_INFO_FA;

    static const std::wstring HML_USER_MANAGEMENT_USER_LOG_EN;
    static const std::wstring HML_USER_MANAGEMENT_USER_LOG_FA;
    static const std::wstring HML_USER_MANAGEMENT_USERS_EN;
    static const std::wstring HML_USER_MANAGEMENT_USERS_FA;
    
    static const std::wstring WELCOME_GREETING_EN;
    static const std::wstring WELCOME_GREETING_FA;
    static const std::wstring WELCOME_CONFERENCE_LIST_EN;
    static const std::wstring WELCOME_CONFERENCE_LIST_FA;

    static const std::wstring SYS_SETTINGS_CURRENT_DATE_TIME_TITLE_EN;
    static const std::wstring SYS_SETTINGS_CURRENT_DATE_TIME_TITLE_FA;

    static const std::wstring CONF_MGMT_CREATE_TYPE_TITLE_EN;
    static const std::wstring CONF_MGMT_CREATE_TYPE_TITLE_FA;
    static const std::wstring CONF_MGMT_CREATE_TYPE_IMMEDIATE_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_TYPE_IMMEDIATE_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_TYPE_BOOKED_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_TYPE_BOOKED_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_NAME_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_NAME_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_ID_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_ID_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_SIGNALING_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_SIGNALING_TEXT_FA;

    static const std::wstring CONF_MGMT_CREATE_GENERAL_TITLE_EN;
    static const std::wstring CONF_MGMT_CREATE_GENERAL_TITLE_FA;
    static const std::wstring CONF_MGMT_CREATE_MEDIA_TITLE_EN;
    static const std::wstring CONF_MGMT_CREATE_MEDIA_TITLE_FA;
    static const std::wstring CONF_MGMT_CREATE_OTHER_TITLE_EN;
    static const std::wstring CONF_MGMT_CREATE_OTHER_TITLE_FA;
    
    static const std::wstring CONF_MGMT_CREATE_DATETIME_TITLE_EN;
    static const std::wstring CONF_MGMT_CREATE_DATETIME_TITLE_FA;
    static const std::wstring CONF_MGMT_CREATE_DATE_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_DATE_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_TIME_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_TIME_TEXT_FA;
        
    static const std::wstring CONF_MGMT_CREATE_GATEKEEPER_TITLE_EN;
    static const std::wstring CONF_MGMT_CREATE_GATEKEEPER_TITLE_FA;
    static const std::wstring CONF_MGMT_CREATE_GK_IP_ADDR_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_GK_IP_ADDR_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_GK_USER_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_GK_USER_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_GK_PWD_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_GK_PWD_TEXT_FA;
    
    static const std::wstring CONF_MGMT_CREATE_SIPSERVER_TITLE_EN;
    static const std::wstring CONF_MGMT_CREATE_SIPSERVER_TITLE_FA;
    static const std::wstring CONF_MGMT_CREATE_SIP_IP_ADDR_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_SIP_IP_ADDR_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_SIP_USER_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_SIP_USER_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_SIP_PWD_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_SIP_PWD_TEXT_FA;
    
    static const std::wstring CONF_MGMT_CREATE_AUDIO_CODEC_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_AUDIO_CODEC_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_VIDEO_CODEC_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_VIDEO_CODEC_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_VIDEO_RES_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_VIDEO_RES_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_CONF_RATE_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_CONF_RATE_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_NUM_OF_PARTICIPANTS_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_NUM_OF_PARTICIPANTS_TEXT_FA;

    static const std::wstring CONF_MGMT_CREATE_HAS_H239_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_HAS_H239_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_EXTERNAL_USER_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_EXTERNAL_USER_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_SEND_TO_SERVER_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_SEND_TO_SERVER_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_AUTO_ENDING_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_AUTO_ENDING_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_MANUAL_ENDING_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_MANUAL_ENDING_TEXT_FA;

    static const std::wstring CONF_MGMT_CREATE_PARTICIPANTS_TITLE_EN;
    static const std::wstring CONF_MGMT_CREATE_PARTICIPANTS_TITLE_FA;
    static const std::wstring CONF_MGMT_CREATE_SELECT_PHONEBOOK_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_SELECT_PHONEBOOK_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_PHONEBOOK_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_PHONEBOOK_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_NEW_CONTACT_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_NEW_CONTACT_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_PARTICIPANT_NAME_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_PARTICIPANT_NAME_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_PARTICIPANT_ADDRESS_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_PARTICIPANT_ADDRESS_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_ADD_TO_PHONEBOOK_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_ADD_TO_PHONEBOOK_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_ADD_PARTICIPANT_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_ADD_PARTICIPANT_TEXT_FA;

    static const std::wstring CONF_MGMT_CREATE_SUBMIT_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_SUBMIT_TEXT_FA;
    static const std::wstring CONF_MGMT_CREATE_SAVE_TEXT_EN;
    static const std::wstring CONF_MGMT_CREATE_SAVE_TEXT_FA;

    static const std::wstring CONF_MGMT_LIST_CONFERENCE_LIST_EN;
    static const std::wstring CONF_MGMT_LIST_CONFERENCE_LIST_FA;
    static const std::wstring CONF_MGMT_LIST_CONFERENCE_INFO_EN;
    static const std::wstring CONF_MGMT_LIST_CONFERENCE_INFO_FA;
    static const std::wstring CONF_MGMT_LIST_CONFERENCE_TIME_EN;
    static const std::wstring CONF_MGMT_LIST_CONFERENCE_TIME_FA;
    static const std::wstring CONF_MGMT_LIST_CONF_SEND_TO_SERVER_EN;
    static const std::wstring CONF_MGMT_LIST_CONF_SEND_TO_SERVER_FA;
    static const std::wstring CONF_MGMT_LIST_CONF_STREAM_DEST_EN;
    static const std::wstring CONF_MGMT_LIST_CONF_STREAM_DEST_FA;
    static const std::wstring CONF_MGMT_LIST_CONF_GATEKEEPER_EN;
    static const std::wstring CONF_MGMT_LIST_CONF_GATEKEEPER_FA;
    static const std::wstring CONF_MGMT_LIST_CONF_GATEKEEPER_ADDRESS_EN;
    static const std::wstring CONF_MGMT_LIST_CONF_GATEKEEPER_ADDRESS_FA;
    static const std::wstring CONF_MGMT_LIST_CONF_GATEKEEPER_USERNAME_EN;
    static const std::wstring CONF_MGMT_LIST_CONF_GATEKEEPER_USERNAME_FA;
    static const std::wstring CONF_MGMT_LIST_CONF_GATEKEEPER_PASSWORD_EN;
    static const std::wstring CONF_MGMT_LIST_CONF_GATEKEEPER_PASSWORD_FA;
    static const std::wstring CONF_MGMT_LIST_CONF_SIPSERVER_EN;
    static const std::wstring CONF_MGMT_LIST_CONF_SIPSERVER_FA;
    static const std::wstring CONF_MGMT_LIST_CONF_SIPSERVER_ADDRESS_EN;
    static const std::wstring CONF_MGMT_LIST_CONF_SIPSERVER_ADDRESS_FA;
    static const std::wstring CONF_MGMT_LIST_CONF_SIPSERVER_USERNAME_EN;
    static const std::wstring CONF_MGMT_LIST_CONF_SIPSERVER_USERNAME_FA;
    static const std::wstring CONF_MGMT_LIST_CONF_SIPSERVER_PASSWORD_EN;
    static const std::wstring CONF_MGMT_LIST_CONF_SIPSERVER_PASSWORD_FA;

    static const std::wstring CONF_MGMT_TEMPLATES_TABLE_TITLE_EN;
    static const std::wstring CONF_MGMT_TEMPLATES_TABLE_TITLE_FA;
    static const std::wstring CONF_MGMT_TEMPLATES_INFO_TITLE_EN;
    static const std::wstring CONF_MGMT_TEMPLATES_INFO_TITLE_FA;
    static const std::wstring CONF_MGMT_TEMPLATES_CREATE_TEXT_EN;
    static const std::wstring CONF_MGMT_TEMPLATES_CREATE_TEXT_FA;
    static const std::wstring CONF_MGMT_TEMPLATES_EDIT_TEXT_EN;
    static const std::wstring CONF_MGMT_TEMPLATES_EDIT_TEXT_FA;
    static const std::wstring CONF_MGMT_TEMPLATES_DELETE_TEXT_EN;
    static const std::wstring CONF_MGMT_TEMPLATES_DELETE_TEXT_FA;
    static const std::wstring CONF_MGMT_TEMPLATES_HOLD_TEXT_EN;
    static const std::wstring CONF_MGMT_TEMPLATES_HOLD_TEXT_FA;

    static const std::wstring WINDOW_TITLE_PHONEBOOK_EN;
    static const std::wstring WINDOW_TITLE_PHONEBOOK_FA;

    static const std::wstring CONF_ROOMS_MSG_END_CONF_TITLE_EN;
    static const std::wstring CONF_ROOMS_MSG_END_CONF_TITLE_FA;
    static const std::wstring CONF_ROOMS_MSG_END_CONF_MSG_EN;
    static const std::wstring CONF_ROOMS_MSG_END_CONF_MSG_FA;

    static const std::wstring CONF_ROOMS_CONF_INFO_EN;
    static const std::wstring CONF_ROOMS_CONF_INFO_FA;
    static const std::wstring CONF_ROOMS_CONF_LIST_EN;
    static const std::wstring CONF_ROOMS_CONF_LIST_FA;
    static const std::wstring CONF_ROOMS_CONF_RATE_EN;
    static const std::wstring CONF_ROOMS_CONF_RATE_FA;
    static const std::wstring CONF_ROOMS_E164ID_EN;
    static const std::wstring CONF_ROOMS_E164ID_FA;
    static const std::wstring CONF_ROOMS_MT_INFO_EN;
    static const std::wstring CONF_ROOMS_MT_INFO_FA;
    static const std::wstring CONF_ROOMS_MT_ALIAS_EN;
    static const std::wstring CONF_ROOMS_MT_ALIAS_FA;
    static const std::wstring CONF_ROOMS_IP_ADDR_EN;
    static const std::wstring CONF_ROOMS_IP_ADDR_FA;
    static const std::wstring CONF_ROOMS_CALL_MODE_EN;
    static const std::wstring CONF_ROOMS_CALL_MODE_FA;
    static const std::wstring CONF_ROOMS_TX_RATE_EN;
    static const std::wstring CONF_ROOMS_TX_RATE_FA;
    static const std::wstring CONF_ROOMS_RX_RATE_EN;
    static const std::wstring CONF_ROOMS_RX_RATE_FA;
    static const std::wstring CONF_ROOMS_MT_CALL_RATE_EN;
    static const std::wstring CONF_ROOMS_MT_CALL_RATE_FA;
    static const std::wstring CONF_ROOMS_AUDIO_SRC_EN;
    static const std::wstring CONF_ROOMS_AUDIO_SRC_FA;
    static const std::wstring CONF_ROOMS_VIDEO_SRC_EN;
    static const std::wstring CONF_ROOMS_VIDEO_SRC_FA;
    static const std::wstring CONF_ROOMS_MT_STATUS_EN;
    static const std::wstring CONF_ROOMS_MT_STATUS_FA;
    static const std::wstring CONF_ROOMS_MUTE_EN;
    static const std::wstring CONF_ROOMS_MUTE_FA;
    static const std::wstring CONF_ROOMS_DUMB_EN;
    static const std::wstring CONF_ROOMS_DUMB_FA;
    static const std::wstring CONF_ROOMS_VOL_IN_EN;
    static const std::wstring CONF_ROOMS_VOL_IN_FA;
    static const std::wstring CONF_ROOMS_VOL_OUT_EN;
    static const std::wstring CONF_ROOMS_VOL_OUT_FA;
    static const std::wstring CONF_ROOMS_CHAIRMAN_EN;
    static const std::wstring CONF_ROOMS_CHAIRMAN_FA;
    static const std::wstring CONF_ROOMS_SPEAKER_EN;
    static const std::wstring CONF_ROOMS_SPEAKER_FA;
    static const std::wstring CONF_ROOMS_CONTINUOUS_PRESENCE_EN;
    static const std::wstring CONF_ROOMS_CONTINUOUS_PRESENCE_FA;

    static const std::wstring CONF_ROOMS_CP_PICS_1_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_1_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_2_LEFT_RIGHT_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_2_LEFT_RIGHT_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_2_TOP_BOTTOM_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_2_TOP_BOTTOM_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_3_HORIZONTAL_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_3_HORIZONTAL_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_3_VERTICAL_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_3_VERTICAL_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_4_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_4_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_4_ACTIVE_VOICE_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_4_ACTIVE_VOICE_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_5_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_5_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_6_HORIZONTAL_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_6_HORIZONTAL_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_6_VERTICAL_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_6_VERTICAL_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_7_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_7_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_8_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_8_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_9_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_9_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_9_ACTIVE_VOICE_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_9_ACTIVE_VOICE_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_10_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_10_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_11_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_11_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_12_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_12_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_12_VERTICAL_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_12_VERTICAL_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_13_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_13_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_14_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_14_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_15_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_15_FA;
    static const std::wstring CONF_ROOMS_CP_PICS_16_EN;
    static const std::wstring CONF_ROOMS_CP_PICS_16_FA;

    static const std::wstring CONF_ROOMS_CP_CELL_NO_PIC_EN;
    static const std::wstring CONF_ROOMS_CP_CELL_NO_PIC_FA;

    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_CALL_EN;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_CALL_FA;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_HANGUP_EN;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_HANGUP_FA;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_SET_AS_MNGR_EN;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_SET_AS_MNGR_FA;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_SET_AS_SPK_EN;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_SET_AS_SPK_FA;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_VIEW_EN;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_VIEW_FA;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_RM_FROM_CONF_EN;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_RM_FROM_CONF_FA;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_MUTE_SPK_EN;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_MUTE_SPK_FA;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_MUTE_MIC_EN;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_MUTE_MIC_FA;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_RECV_VID_EN;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_RECV_VID_FA;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_SEND_VID_EN;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_SEND_VID_FA;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_ADD_TO_ADDR_BOOK_EN;
    static const std::wstring CONF_ROOMS_PRTCPNT_CTX_ADD_TO_ADDR_BOOK_FA;

    static const std::wstring CONF_ROOMS_PRTCPNT_MSG_ERASE_TITLE_EN;
    static const std::wstring CONF_ROOMS_PRTCPNT_MSG_ERASE_TITLE_FA;
    static const std::wstring CONF_ROOMS_PRTCPNT_MSG_ERASE_MSG_EN;
    static const std::wstring CONF_ROOMS_PRTCPNT_MSG_ERASE_MSG_FA;

    static const std::wstring CONF_ROOMS_LEGEND_DISCONNECT_EN;
    static const std::wstring CONF_ROOMS_LEGEND_DISCONNECT_FA;
    static const std::wstring CONF_ROOMS_LEGEND_INCALL_EN;
    static const std::wstring CONF_ROOMS_LEGEND_INCALL_FA;
    static const std::wstring CONF_ROOMS_LEGEND_MANAGER_EN;
    static const std::wstring CONF_ROOMS_LEGEND_MANAGER_FA;
    static const std::wstring CONF_ROOMS_LEGEND_SPEAKER_EN;
    static const std::wstring CONF_ROOMS_LEGEND_SPEAKER_FA;

    static const std::wstring CONF_ROOMS_END_CONF_EN;
    static const std::wstring CONF_ROOMS_END_CONF_FA;
    static const std::wstring CONF_ROOMS_ADD_PARTICIPANT_EN;
    static const std::wstring CONF_ROOMS_ADD_PARTICIPANT_FA;

    static const std::wstring CONF_ROOMS_DLG_ADD_PARTICIPANT_TITLE_EN;
    static const std::wstring CONF_ROOMS_DLG_ADD_PARTICIPANT_TITLE_FA;

public:
    std::unordered_map<std::string, std::wstring> LangStringsHash;
    
public:
    Impl(const CgiEnv::ELang &lang)
    {
        switch(lang) {
        case CgiEnv::ELang_En:
            LangStringsHash["TEMPO_UNDER_CONSTRUCTION"] = TEMPO_UNDER_CONSTRUCTION_EN;
            LangStringsHash["WARN_NO_SCRIPT"] = WARN_NO_SCRIPT_EN;
            LangStringsHash["LOGIN_TITLE"] = LOGIN_TITLE_EN;
            LangStringsHash["HOME_TITLE"] = HOME_TITLE_EN;
            LangStringsHash["GENERAL_ACTIVE"] = GENERAL_ACTIVE_EN;
            LangStringsHash["GENERAL_INACTIVE"] = GENERAL_INACTIVE_EN;
            LangStringsHash["GENERAL_CONFIRM"] = GENERAL_CONFIRM_EN;
            LangStringsHash["GENERAL_CANCEL"] = GENERAL_CANCEL_EN;
            LangStringsHash["GENERAL_INDEX"] = GENERAL_INDEX_EN;
            LangStringsHash["GENERAL_ERASE"] = GENERAL_ERASE_EN;
            LangStringsHash["GENERAL_EDIT"] = GENERAL_EDIT_EN;
            LangStringsHash["GENERAL_ADD"] = GENERAL_ADD_EN;
            LangStringsHash["GENERAL_ADD_RETURN"] = GENERAL_ADD_RETURN_EN;
            LangStringsHash["GENERAL_RETURN"] = GENERAL_RETURN_EN;
            LangStringsHash["GENERAL_LAYOUT"] = GENERAL_LAYOUT_EN;
            LangStringsHash["LOGIN_FORM_TITLE"] = LOGIN_FORM_TITLE_EN;
            LangStringsHash["LOGIN_FORM_USER_TEXT"] = LOGIN_FORM_USER_TEXT_EN;
            LangStringsHash["LOGIN_FORM_PWD_TEXT"] = LOGIN_FORM_PWD_TEXT_EN;
            LangStringsHash["LOGIN_FORM_CAPTCHA_TEXT"] = LOGIN_FORM_CAPTCHA_TEXT_EN;
            LangStringsHash["LOGIN_FORM_EMAIL_TEXT"] = LOGIN_FORM_EMAIL_TEXT_EN;
            LangStringsHash["LOGIN_FORM_LOGIN_TEXT"] = LOGIN_FORM_LOGIN_TEXT_EN;
            LangStringsHash["LOGIN_FORM_RECOVER_TEXT"] = LOGIN_FORM_RECOVER_TEXT_EN;
            LangStringsHash["LOGIN_FORM_FORGOT_TEXT"] = LOGIN_FORM_FORGOT_TEXT_EN;
            LangStringsHash["LOGIN_FORM_ERR_LOGIN"] = LOGIN_FORM_ERR_LOGIN_EN;
            LangStringsHash["LOGIN_FORM_ERR_FORGOT"] = LOGIN_FORM_ERR_FORGOT_EN;
            LangStringsHash["LOGIN_FORM_MSG_FORGOT"] = LOGIN_FORM_MSG_FORGOT_EN;
            LangStringsHash["HML_WELCOME"] = HML_WELCOME_EN;
            LangStringsHash["HML_SYSMON"] = HML_SYSMON_EN;
            LangStringsHash["HML_USER_MANAGEMENT"] = HML_USER_MANAGEMENT_EN;
            LangStringsHash["HML_SYSTEM_SETTINGS"] = HML_SYSTEM_SETTINGS_EN;
            LangStringsHash["HML_MCU_SETTINGS"] = HML_MCU_SETTINGS_EN;
            LangStringsHash["HML_CONFERENCE_ROOMS"] = HML_CONFERENCE_ROOMS_EN;
            LangStringsHash["HML_CONFERENCE_MANAGEMENT"] = HML_CONFERENCE_MANAGEMENT_EN;
            LangStringsHash["HML_EXIT"] = HML_EXIT_EN;
            LangStringsHash["HML_CONFERENCE_MANAGEMENT_CREATE_CONFERENCE"] = HML_CONFERENCE_MANAGEMENT_CREATE_CONFERENCE_EN;
            LangStringsHash["HML_CONFERENCE_MANAGEMENT_TEMPLATES"] = HML_CONFERENCE_MANAGEMENT_TEMPLATES_EN;
            LangStringsHash["HML_CONFERENCE_MANAGEMENT_CONFERENCE_LIST"] = HML_CONFERENCE_MANAGEMENT_CONFERENCE_LIST_EN;
            LangStringsHash["HML_CONFERENCE_MANAGEMENT_TERSTREAM_DESTMINAL_MANAGEMENT"] = HML_CONFERENCE_MANAGEMENT_TERMINAL_MANAGEMENT_EN;
            LangStringsHash["HML_MCU_SETTINGS_CODEC_SETTINGS"] = HML_MCU_SETTINGS_CODEC_SETTINGS_EN;
            LangStringsHash["HML_MCU_SETTINGS_SIGNALING_SETTINGS"] = HML_MCU_SETTINGS_SIGNALING_SETTINGS_EN;
            LangStringsHash["HML_MCU_SETTINGS_SIP_SERVER_SETTINGS"] = HML_MCU_SETTINGS_SIP_SERVER_SETTINGS_EN;
            LangStringsHash["HML_MCU_SETTINGS_GATE_KEEPER_SETTINGS"] = HML_MCU_SETTINGS_GATE_KEEPER_SETTINGS_EN;
            LangStringsHash["HML_MCU_SETTINGS_STUN_SETTINGS"] = HML_MCU_SETTINGS_STUN_SETTINGS_EN;
            LangStringsHash["HML_MCU_SETTINGS_DSP_SETTINGS"] = HML_MCU_SETTINGS_DSP_SETTINGS_EN;
            LangStringsHash["HML_SYSMON_GENERAL_INFO"] = HML_SYSMON_GENERAL_INFO_EN;
            LangStringsHash["HML_SYSMON_SIGNALING_INFO"] = HML_SYSMON_SIGNALING_INFO_EN;
            LangStringsHash["HML_SYSMON_CODEC_INFO"] = HML_SYSMON_CODEC_INFO_EN;
            LangStringsHash["HML_SYSMON_SERVICES_INFO"] = HML_SYSMON_SERVICES_INFO_EN;
            LangStringsHash["HML_SYSMON_DSP_INFO"] = HML_SYSMON_DSP_INFO_EN;
            LangStringsHash["HML_USER_MANAGEMENT_USER_LOG"] = HML_USER_MANAGEMENT_USER_LOG_EN;
            LangStringsHash["HML_USER_MANAGEMENT_USERS"] = HML_USER_MANAGEMENT_USERS_EN;
            LangStringsHash["WELCOME_GREETING"] = WELCOME_GREETING_EN;
            LangStringsHash["WELCOME_CONFERENCE_LIST"] = WELCOME_CONFERENCE_LIST_EN;
            LangStringsHash["SYS_SETTINGS_CURRENT_DATE_TIME_TITLE"] = SYS_SETTINGS_CURRENT_DATE_TIME_TITLE_EN;
            LangStringsHash["CONF_MGMT_CREATE_TYPE_TITLE"] = CONF_MGMT_CREATE_TYPE_TITLE_EN;
            LangStringsHash["CONF_MGMT_CREATE_TYPE_IMMEDIATE_TEXT"] = CONF_MGMT_CREATE_TYPE_IMMEDIATE_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_TYPE_BOOKED_TEXT"] = CONF_MGMT_CREATE_TYPE_BOOKED_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_NAME_TEXT"] = CONF_MGMT_CREATE_NAME_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_ID_TEXT"] = CONF_MGMT_CREATE_ID_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_SIGNALING_TEXT"] = CONF_MGMT_CREATE_SIGNALING_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_GENERAL_TITLE"] = CONF_MGMT_CREATE_GENERAL_TITLE_EN;
            LangStringsHash["CONF_MGMT_CREATE_MEDIA_TITLE"] = CONF_MGMT_CREATE_MEDIA_TITLE_EN;
            LangStringsHash["CONF_MGMT_CREATE_OTHER_TITLE"] = CONF_MGMT_CREATE_OTHER_TITLE_EN;
            LangStringsHash["CONF_MGMT_CREATE_DATETIME_TITLE"] = CONF_MGMT_CREATE_DATETIME_TITLE_EN;
            LangStringsHash["CONF_MGMT_CREATE_DATE_TEXT"] = CONF_MGMT_CREATE_DATE_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_TIME_TEXT"] = CONF_MGMT_CREATE_TIME_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_GATEKEEPER_TITLE"] = CONF_MGMT_CREATE_GATEKEEPER_TITLE_EN;
            LangStringsHash["CONF_MGMT_CREATE_GK_IP_ADDR_TEXT"] = CONF_MGMT_CREATE_GK_IP_ADDR_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_GK_USER_TEXT"] = CONF_MGMT_CREATE_GK_USER_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_GK_PWD_TEXT"] = CONF_MGMT_CREATE_GK_PWD_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_SIPSERVER_TITLE"] = CONF_MGMT_CREATE_SIPSERVER_TITLE_EN;
            LangStringsHash["CONF_MGMT_CREATE_SIP_IP_ADDR_TEXT"] = CONF_MGMT_CREATE_SIP_IP_ADDR_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_SIP_USER_TEXT"] = CONF_MGMT_CREATE_SIP_USER_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_SIP_PWD_TEXT"] = CONF_MGMT_CREATE_SIP_PWD_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_AUDIO_CODEC_TEXT"] = CONF_MGMT_CREATE_AUDIO_CODEC_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_VIDEO_CODEC_TEXT"] = CONF_MGMT_CREATE_VIDEO_CODEC_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_VIDEO_RES_TEXT"] = CONF_MGMT_CREATE_VIDEO_RES_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_CONF_RATE_TEXT"] = CONF_MGMT_CREATE_CONF_RATE_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_NUM_OF_PARTICIPANTS_TEXT"] = CONF_MGMT_CREATE_NUM_OF_PARTICIPANTS_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_HAS_H239_TEXT"] = CONF_MGMT_CREATE_HAS_H239_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_EXTERNAL_USER_TEXT"] = CONF_MGMT_CREATE_EXTERNAL_USER_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_SEND_TO_SERVER_TEXT"] = CONF_MGMT_CREATE_SEND_TO_SERVER_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_AUTO_ENDING_TEXT"] = CONF_MGMT_CREATE_AUTO_ENDING_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_MANUAL_ENDING_TEXT"] = CONF_MGMT_CREATE_MANUAL_ENDING_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_PARTICIPANTS_TITLE"] = CONF_MGMT_CREATE_PARTICIPANTS_TITLE_EN;
            LangStringsHash["CONF_MGMT_CREATE_SELECT_PHONEBOOK_TEXT"] = CONF_MGMT_CREATE_SELECT_PHONEBOOK_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_PHONEBOOK_TEXT"] = CONF_MGMT_CREATE_PHONEBOOK_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_NEW_CONTACT_TEXT"] = CONF_MGMT_CREATE_NEW_CONTACT_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_PARTICIPANT_NAME_TEXT"] = CONF_MGMT_CREATE_PARTICIPANT_NAME_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_PARTICIPANT_ADDRESS_TEXT"] = CONF_MGMT_CREATE_PARTICIPANT_ADDRESS_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_ADD_TO_PHONEBOOK_TEXT"] = CONF_MGMT_CREATE_ADD_TO_PHONEBOOK_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_ADD_PARTICIPANT_TEXT"] = CONF_MGMT_CREATE_ADD_PARTICIPANT_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_SUBMIT_TEXT"] = CONF_MGMT_CREATE_SUBMIT_TEXT_EN;
            LangStringsHash["CONF_MGMT_CREATE_SAVE_TEXT"] = CONF_MGMT_CREATE_SAVE_TEXT_EN;
            LangStringsHash["CONF_MGMT_LIST_CONFERENCE_LIST"] = CONF_MGMT_LIST_CONFERENCE_LIST_EN;
            LangStringsHash["CONF_MGMT_LIST_CONFERENCE_INFO"] = CONF_MGMT_LIST_CONFERENCE_INFO_EN;
            LangStringsHash["CONF_MGMT_LIST_CONFERENCE_TIME"] = CONF_MGMT_LIST_CONFERENCE_TIME_EN;
            LangStringsHash["CONF_MGMT_LIST_CONF_SEND_TO_SERVER"] = CONF_MGMT_LIST_CONF_SEND_TO_SERVER_EN;
            LangStringsHash["CONF_MGMT_LIST_CONF_STREAM_DEST"] = CONF_MGMT_LIST_CONF_STREAM_DEST_EN;
            LangStringsHash["CONF_MGMT_LIST_CONF_GATEKEEPER"] = CONF_MGMT_LIST_CONF_GATEKEEPER_EN;
            LangStringsHash["CONF_MGMT_LIST_CONF_GATEKEEPER_ADDRESS"] = CONF_MGMT_LIST_CONF_GATEKEEPER_ADDRESS_EN;
            LangStringsHash["CONF_MGMT_LIST_CONF_GATEKEEPER_USERNAME"] = CONF_MGMT_LIST_CONF_GATEKEEPER_USERNAME_EN;
            LangStringsHash["CONF_MGMT_LIST_CONF_GATEKEEPER_PASSWORD"] = CONF_MGMT_LIST_CONF_GATEKEEPER_PASSWORD_EN;
            LangStringsHash["CONF_MGMT_LIST_CONF_SIPSERVER"] = CONF_MGMT_LIST_CONF_SIPSERVER_EN;
            LangStringsHash["CONF_MGMT_LIST_CONF_SIPSERVER_ADDRESS"] = CONF_MGMT_LIST_CONF_SIPSERVER_ADDRESS_EN;
            LangStringsHash["CONF_MGMT_LIST_CONF_SIPSERVER_USERNAME"] = CONF_MGMT_LIST_CONF_SIPSERVER_USERNAME_EN;
            LangStringsHash["CONF_MGMT_LIST_CONF_SIPSERVER_PASSWORD"] = CONF_MGMT_LIST_CONF_SIPSERVER_PASSWORD_EN;
            LangStringsHash["CONF_MGMT_TEMPLATES_TABLE_TITLE"] = CONF_MGMT_TEMPLATES_TABLE_TITLE_EN;
            LangStringsHash["CONF_MGMT_TEMPLATES_INFO_TITLE"] = CONF_MGMT_TEMPLATES_INFO_TITLE_EN;
            LangStringsHash["CONF_MGMT_TEMPLATES_CREATE_TEXT"] = CONF_MGMT_TEMPLATES_CREATE_TEXT_EN;
            LangStringsHash["CONF_MGMT_TEMPLATES_EDIT_TEXT"] = CONF_MGMT_TEMPLATES_EDIT_TEXT_EN;
            LangStringsHash["CONF_MGMT_TEMPLATES_DELETE_TEXT"] = CONF_MGMT_TEMPLATES_DELETE_TEXT_EN;
            LangStringsHash["CONF_MGMT_TEMPLATES_HOLD_TEXT"] = CONF_MGMT_TEMPLATES_HOLD_TEXT_EN;
            LangStringsHash["WINDOW_TITLE_PHONEBOOK"] = WINDOW_TITLE_PHONEBOOK_EN;
            LangStringsHash["CONF_ROOMS_MSG_END_CONF_TITLE"] = CONF_ROOMS_MSG_END_CONF_TITLE_EN;
            LangStringsHash["CONF_ROOMS_MSG_END_CONF_MSG"] = CONF_ROOMS_MSG_END_CONF_MSG_EN;
            LangStringsHash["CONF_ROOMS_CONF_INFO"] = CONF_ROOMS_CONF_INFO_EN;
            LangStringsHash["CONF_ROOMS_CONF_LIST"] = CONF_ROOMS_CONF_LIST_EN;
            LangStringsHash["CONF_ROOMS_CONF_RATE"] = CONF_ROOMS_CONF_RATE_EN;
            LangStringsHash["CONF_ROOMS_E164ID"] = CONF_ROOMS_E164ID_EN;
            LangStringsHash["CONF_ROOMS_MT_INFO"] = CONF_ROOMS_MT_INFO_EN;
            LangStringsHash["CONF_ROOMS_MT_ALIAS"] = CONF_ROOMS_MT_ALIAS_EN;
            LangStringsHash["CONF_ROOMS_IP_ADDR"] = CONF_ROOMS_IP_ADDR_EN;
            LangStringsHash["CONF_ROOMS_CALL_MODE"] = CONF_ROOMS_CALL_MODE_EN;
            LangStringsHash["CONF_ROOMS_TX_RATE"] = CONF_ROOMS_TX_RATE_EN;
            LangStringsHash["CONF_ROOMS_RX_RATE"] = CONF_ROOMS_RX_RATE_EN;
            LangStringsHash["CONF_ROOMS_MT_CALL_RATE"] = CONF_ROOMS_MT_CALL_RATE_EN;
            LangStringsHash["CONF_ROOMS_AUDIO_SRC"] = CONF_ROOMS_AUDIO_SRC_EN;
            LangStringsHash["CONF_ROOMS_VIDEO_SRC"] = CONF_ROOMS_VIDEO_SRC_EN;
            LangStringsHash["CONF_ROOMS_MT_STATUS"] = CONF_ROOMS_MT_STATUS_EN;
            LangStringsHash["CONF_ROOMS_MUTE"] = CONF_ROOMS_MUTE_EN;
            LangStringsHash["CONF_ROOMS_DUMB"] = CONF_ROOMS_DUMB_EN;
            LangStringsHash["CONF_ROOMS_VOL_IN"] = CONF_ROOMS_VOL_IN_EN;
            LangStringsHash["CONF_ROOMS_VOL_OUT"] = CONF_ROOMS_VOL_OUT_EN;
            LangStringsHash["CONF_ROOMS_CHAIRMAN"] = CONF_ROOMS_CHAIRMAN_EN;
            LangStringsHash["CONF_ROOMS_SPEAKER"] = CONF_ROOMS_SPEAKER_EN;
            LangStringsHash["CONF_ROOMS_CONTINUOUS_PRESENCE"] = CONF_ROOMS_CONTINUOUS_PRESENCE_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_1"] = CONF_ROOMS_CP_PICS_1_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_2_LEFT_RIGHT"] = CONF_ROOMS_CP_PICS_2_LEFT_RIGHT_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_2_TOP_BOTTOM"] = CONF_ROOMS_CP_PICS_2_TOP_BOTTOM_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_3_HORIZONTAL"] = CONF_ROOMS_CP_PICS_3_HORIZONTAL_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_3_VERTICAL"] = CONF_ROOMS_CP_PICS_3_VERTICAL_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_4"] = CONF_ROOMS_CP_PICS_4_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_4_ACTIVE_VOICE"] = CONF_ROOMS_CP_PICS_4_ACTIVE_VOICE_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_5"] = CONF_ROOMS_CP_PICS_5_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_6_HORIZONTAL"] = CONF_ROOMS_CP_PICS_6_HORIZONTAL_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_6_VERTICAL"] = CONF_ROOMS_CP_PICS_6_VERTICAL_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_7"] = CONF_ROOMS_CP_PICS_7_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_8"] = CONF_ROOMS_CP_PICS_8_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_9"] = CONF_ROOMS_CP_PICS_9_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_9_ACTIVE_VOICE"] = CONF_ROOMS_CP_PICS_9_ACTIVE_VOICE_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_10"] = CONF_ROOMS_CP_PICS_10_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_11"] = CONF_ROOMS_CP_PICS_11_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_12"] = CONF_ROOMS_CP_PICS_12_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_12_VERTICAL"] = CONF_ROOMS_CP_PICS_12_VERTICAL_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_13"] = CONF_ROOMS_CP_PICS_13_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_14"] = CONF_ROOMS_CP_PICS_14_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_15"] = CONF_ROOMS_CP_PICS_15_EN;
            LangStringsHash["CONF_ROOMS_CP_PICS_16"] = CONF_ROOMS_CP_PICS_16_EN;
            LangStringsHash["CONF_ROOMS_CP_CELL_NO_PIC"] = CONF_ROOMS_CP_CELL_NO_PIC_EN;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_CALL"] = CONF_ROOMS_PRTCPNT_CTX_CALL_EN;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_HANGUP"] = CONF_ROOMS_PRTCPNT_CTX_HANGUP_EN;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_SET_AS_MNGR"] = CONF_ROOMS_PRTCPNT_CTX_SET_AS_MNGR_EN;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_SET_AS_SPK"] = CONF_ROOMS_PRTCPNT_CTX_SET_AS_SPK_EN;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_VIEW"] = CONF_ROOMS_PRTCPNT_CTX_VIEW_EN;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_RM_FROM_CONF"] = CONF_ROOMS_PRTCPNT_CTX_RM_FROM_CONF_EN;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_MUTE_SPK"] = CONF_ROOMS_PRTCPNT_CTX_MUTE_SPK_EN;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_MUTE_MIC"] = CONF_ROOMS_PRTCPNT_CTX_MUTE_MIC_EN;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_RECV_VID"] = CONF_ROOMS_PRTCPNT_CTX_RECV_VID_EN;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_SEND_VID"] = CONF_ROOMS_PRTCPNT_CTX_SEND_VID_EN;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_ADD_TO_ADDR_BOOK"] = CONF_ROOMS_PRTCPNT_CTX_ADD_TO_ADDR_BOOK_EN;
            LangStringsHash["CONF_ROOMS_PRTCPNT_MSG_ERASE_TITLE"] = CONF_ROOMS_PRTCPNT_MSG_ERASE_TITLE_EN;
            LangStringsHash["CONF_ROOMS_PRTCPNT_MSG_ERASE_MSG"] = CONF_ROOMS_PRTCPNT_MSG_ERASE_MSG_EN;
            LangStringsHash["CONF_ROOMS_LEGEND_DISCONNECT"] = CONF_ROOMS_LEGEND_DISCONNECT_EN;
            LangStringsHash["CONF_ROOMS_LEGEND_INCALL"] = CONF_ROOMS_LEGEND_INCALL_EN;
            LangStringsHash["CONF_ROOMS_LEGEND_MANAGER"] = CONF_ROOMS_LEGEND_MANAGER_EN;
            LangStringsHash["CONF_ROOMS_LEGEND_SPEAKER"] = CONF_ROOMS_LEGEND_SPEAKER_EN;
            LangStringsHash["CONF_ROOMS_END_CONF"] = CONF_ROOMS_END_CONF_EN;
            LangStringsHash["CONF_ROOMS_ADD_PARTICIPANT"] = CONF_ROOMS_ADD_PARTICIPANT_EN;
            LangStringsHash["CONF_ROOMS_DLG_ADD_PARTICIPANT_TITLE"] = CONF_ROOMS_DLG_ADD_PARTICIPANT_TITLE_EN;
            break;
            
        case CgiEnv::ELang_Fa:
            LangStringsHash["TEMPO_UNDER_CONSTRUCTION"] = TEMPO_UNDER_CONSTRUCTION_FA;
            LangStringsHash["WARN_NO_SCRIPT"] = WARN_NO_SCRIPT_FA;
            LangStringsHash["LOGIN_TITLE"] = LOGIN_TITLE_FA;
            LangStringsHash["HOME_TITLE"] = HOME_TITLE_FA;
            LangStringsHash["GENERAL_ACTIVE"] = GENERAL_ACTIVE_FA;
            LangStringsHash["GENERAL_INACTIVE"] = GENERAL_INACTIVE_FA;
            LangStringsHash["GENERAL_CONFIRM"] = GENERAL_CONFIRM_FA;
            LangStringsHash["GENERAL_CANCEL"] = GENERAL_CANCEL_FA;
            LangStringsHash["GENERAL_INDEX"] = GENERAL_INDEX_FA;
            LangStringsHash["GENERAL_ERASE"] = GENERAL_ERASE_FA;
            LangStringsHash["GENERAL_EDIT"] = GENERAL_EDIT_FA;
            LangStringsHash["GENERAL_ADD"] = GENERAL_ADD_FA;
            LangStringsHash["GENERAL_ADD_RETURN"] = GENERAL_ADD_RETURN_FA;
            LangStringsHash["GENERAL_RETURN"] = GENERAL_RETURN_FA;
            LangStringsHash["GENERAL_LAYOUT"] = GENERAL_LAYOUT_FA;
            LangStringsHash["LOGIN_FORM_TITLE"] = LOGIN_FORM_TITLE_FA;
            LangStringsHash["LOGIN_FORM_USER_TEXT"] = LOGIN_FORM_USER_TEXT_FA;
            LangStringsHash["LOGIN_FORM_PWD_TEXT"] = LOGIN_FORM_PWD_TEXT_FA;
            LangStringsHash["LOGIN_FORM_CAPTCHA_TEXT"] = LOGIN_FORM_CAPTCHA_TEXT_FA;
            LangStringsHash["LOGIN_FORM_EMAIL_TEXT"] = LOGIN_FORM_EMAIL_TEXT_FA;
            LangStringsHash["LOGIN_FORM_LOGIN_TEXT"] = LOGIN_FORM_LOGIN_TEXT_FA;
            LangStringsHash["LOGIN_FORM_RECOVER_TEXT"] = LOGIN_FORM_RECOVER_TEXT_FA;
            LangStringsHash["LOGIN_FORM_FORGOT_TEXT"] = LOGIN_FORM_FORGOT_TEXT_FA;
            LangStringsHash["LOGIN_FORM_ERR_LOGIN"] = LOGIN_FORM_ERR_LOGIN_FA;
            LangStringsHash["LOGIN_FORM_ERR_FORGOT"] = LOGIN_FORM_ERR_FORGOT_FA;
            LangStringsHash["LOGIN_FORM_MSG_FORGOT"] = LOGIN_FORM_MSG_FORGOT_FA;
            LangStringsHash["HML_WELCOME"] = HML_WELCOME_FA;
            LangStringsHash["HML_SYSMON"] = HML_SYSMON_FA;
            LangStringsHash["HML_USER_MANAGEMENT"] = HML_USER_MANAGEMENT_FA;
            LangStringsHash["HML_SYSTEM_SETTINGS"] = HML_SYSTEM_SETTINGS_FA;
            LangStringsHash["HML_MCU_SETTINGS"] = HML_MCU_SETTINGS_FA;
            LangStringsHash["HML_CONFERENCE_ROOMS"] = HML_CONFERENCE_ROOMS_FA;
            LangStringsHash["HML_CONFERENCE_MANAGEMENT"] = HML_CONFERENCE_MANAGEMENT_FA;
            LangStringsHash["HML_EXIT"] = HML_EXIT_FA;
            LangStringsHash["HML_CONFERENCE_MANAGEMENT_CREATE_CONFERENCE"] = HML_CONFERENCE_MANAGEMENT_CREATE_CONFERENCE_FA;
            LangStringsHash["HML_CONFERENCE_MANAGEMENT_TEMPLATES"] = HML_CONFERENCE_MANAGEMENT_TEMPLATES_FA;
            LangStringsHash["HML_CONFERENCE_MANAGEMENT_CONFERENCE_LIST"] = HML_CONFERENCE_MANAGEMENT_CONFERENCE_LIST_FA;
            LangStringsHash["HML_CONFERENCE_MANAGEMENT_TERMINAL_MANAGEMENT"] = HML_CONFERENCE_MANAGEMENT_TERMINAL_MANAGEMENT_FA;
            LangStringsHash["HML_MCU_SETTINGS_CODEC_SETTINGS"] = HML_MCU_SETTINGS_CODEC_SETTINGS_FA;
            LangStringsHash["HML_MCU_SETTINGS_SIGNALING_SETTINGS"] = HML_MCU_SETTINGS_SIGNALING_SETTINGS_FA;
            LangStringsHash["HML_MCU_SETTINGS_SIP_SERVER_SETTINGS"] = HML_MCU_SETTINGS_SIP_SERVER_SETTINGS_FA;
            LangStringsHash["HML_MCU_SETTINGS_GATE_KEEPER_SETTINGS"] = HML_MCU_SETTINGS_GATE_KEEPER_SETTINGS_FA;
            LangStringsHash["HML_MCU_SETTINGS_STUN_SETTINGS"] = HML_MCU_SETTINGS_STUN_SETTINGS_FA;
            LangStringsHash["HML_MCU_SETTINGS_DSP_SETTINGS"] = HML_MCU_SETTINGS_DSP_SETTINGS_FA;
            LangStringsHash["HML_SYSMON_GENERAL_INFO"] = HML_SYSMON_GENERAL_INFO_FA;
            LangStringsHash["HML_SYSMON_SIGNALING_INFO"] = HML_SYSMON_SIGNALING_INFO_FA;
            LangStringsHash["HML_SYSMON_CODEC_INFO"] = HML_SYSMON_CODEC_INFO_FA;
            LangStringsHash["HML_SYSMON_SERVICES_INFO"] = HML_SYSMON_SERVICES_INFO_FA;
            LangStringsHash["HML_SYSMON_DSP_INFO"] = HML_SYSMON_DSP_INFO_FA;
            LangStringsHash["HML_USER_MANAGEMENT_USER_LOG"] = HML_USER_MANAGEMENT_USER_LOG_FA;
            LangStringsHash["HML_USER_MANAGEMENT_USERS"] = HML_USER_MANAGEMENT_USERS_FA;
            LangStringsHash["WELCOME_GREETING"] = WELCOME_GREETING_FA;
            LangStringsHash["WELCOME_CONFERENCE_LIST"] = WELCOME_CONFERENCE_LIST_FA;
            LangStringsHash["SYS_SETTINGS_CURRENT_DATE_TIME_TITLE"] = SYS_SETTINGS_CURRENT_DATE_TIME_TITLE_FA;
            LangStringsHash["CONF_MGMT_CREATE_TYPE_TITLE"] = CONF_MGMT_CREATE_TYPE_TITLE_FA;
            LangStringsHash["CONF_MGMT_CREATE_TYPE_IMMEDIATE_TEXT"] = CONF_MGMT_CREATE_TYPE_IMMEDIATE_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_TYPE_BOOKED_TEXT"] = CONF_MGMT_CREATE_TYPE_BOOKED_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_NAME_TEXT"] = CONF_MGMT_CREATE_NAME_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_ID_TEXT"] = CONF_MGMT_CREATE_ID_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_SIGNALING_TEXT"] = CONF_MGMT_CREATE_SIGNALING_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_GENERAL_TITLE"] = CONF_MGMT_CREATE_GENERAL_TITLE_FA;
            LangStringsHash["CONF_MGMT_CREATE_MEDIA_TITLE"] = CONF_MGMT_CREATE_MEDIA_TITLE_FA;
            LangStringsHash["CONF_MGMT_CREATE_OTHER_TITLE"] = CONF_MGMT_CREATE_OTHER_TITLE_FA;
            LangStringsHash["CONF_MGMT_CREATE_DATETIME_TITLE"] = CONF_MGMT_CREATE_DATETIME_TITLE_FA;
            LangStringsHash["CONF_MGMT_CREATE_DATE_TEXT"] = CONF_MGMT_CREATE_DATE_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_TIME_TEXT"] = CONF_MGMT_CREATE_TIME_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_GATEKEEPER_TITLE"] = CONF_MGMT_CREATE_GATEKEEPER_TITLE_FA;
            LangStringsHash["CONF_MGMT_CREATE_GK_IP_ADDR_TEXT"] = CONF_MGMT_CREATE_GK_IP_ADDR_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_GK_USER_TEXT"] = CONF_MGMT_CREATE_GK_USER_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_GK_PWD_TEXT"] = CONF_MGMT_CREATE_GK_PWD_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_SIPSERVER_TITLE"] = CONF_MGMT_CREATE_SIPSERVER_TITLE_FA;
            LangStringsHash["CONF_MGMT_CREATE_SIP_IP_ADDR_TEXT"] = CONF_MGMT_CREATE_SIP_IP_ADDR_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_SIP_USER_TEXT"] = CONF_MGMT_CREATE_SIP_USER_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_SIP_PWD_TEXT"] = CONF_MGMT_CREATE_SIP_PWD_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_AUDIO_CODEC_TEXT"] = CONF_MGMT_CREATE_AUDIO_CODEC_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_VIDEO_CODEC_TEXT"] = CONF_MGMT_CREATE_VIDEO_CODEC_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_VIDEO_RES_TEXT"] = CONF_MGMT_CREATE_VIDEO_RES_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_CONF_RATE_TEXT"] = CONF_MGMT_CREATE_CONF_RATE_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_NUM_OF_PARTICIPANTS_TEXT"] = CONF_MGMT_CREATE_NUM_OF_PARTICIPANTS_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_HAS_H239_TEXT"] = CONF_MGMT_CREATE_HAS_H239_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_EXTERNAL_USER_TEXT"] = CONF_MGMT_CREATE_EXTERNAL_USER_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_SEND_TO_SERVER_TEXT"] = CONF_MGMT_CREATE_SEND_TO_SERVER_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_AUTO_ENDING_TEXT"] = CONF_MGMT_CREATE_AUTO_ENDING_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_MANUAL_ENDING_TEXT"] = CONF_MGMT_CREATE_MANUAL_ENDING_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_PARTICIPANTS_TITLE"] = CONF_MGMT_CREATE_PARTICIPANTS_TITLE_FA;
            LangStringsHash["CONF_MGMT_CREATE_SELECT_PHONEBOOK_TEXT"] = CONF_MGMT_CREATE_SELECT_PHONEBOOK_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_PHONEBOOK_TEXT"] = CONF_MGMT_CREATE_PHONEBOOK_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_NEW_CONTACT_TEXT"] = CONF_MGMT_CREATE_NEW_CONTACT_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_PARTICIPANT_NAME_TEXT"] = CONF_MGMT_CREATE_PARTICIPANT_NAME_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_PARTICIPANT_ADDRESS_TEXT"] = CONF_MGMT_CREATE_PARTICIPANT_ADDRESS_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_ADD_TO_PHONEBOOK_TEXT"] = CONF_MGMT_CREATE_ADD_TO_PHONEBOOK_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_ADD_PARTICIPANT_TEXT"] = CONF_MGMT_CREATE_ADD_PARTICIPANT_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_SUBMIT_TEXT"] = CONF_MGMT_CREATE_SUBMIT_TEXT_FA;
            LangStringsHash["CONF_MGMT_CREATE_SAVE_TEXT"] = CONF_MGMT_CREATE_SAVE_TEXT_FA;
            LangStringsHash["CONF_MGMT_LIST_CONFERENCE_LIST"] = CONF_MGMT_LIST_CONFERENCE_LIST_FA;
            LangStringsHash["CONF_MGMT_LIST_CONFERENCE_INFO"] = CONF_MGMT_LIST_CONFERENCE_INFO_FA;
            LangStringsHash["CONF_MGMT_LIST_CONFERENCE_TIME"] = CONF_MGMT_LIST_CONFERENCE_TIME_FA;
            LangStringsHash["CONF_MGMT_LIST_CONF_SEND_TO_SERVER"] = CONF_MGMT_LIST_CONF_SEND_TO_SERVER_FA;
            LangStringsHash["CONF_MGMT_LIST_CONF_STREAM_DEST"] = CONF_MGMT_LIST_CONF_STREAM_DEST_FA;
            LangStringsHash["CONF_MGMT_LIST_CONF_GATEKEEPER"] = CONF_MGMT_LIST_CONF_GATEKEEPER_FA;
            LangStringsHash["CONF_MGMT_LIST_CONF_GATEKEEPER_ADDRESS"] = CONF_MGMT_LIST_CONF_GATEKEEPER_ADDRESS_FA;
            LangStringsHash["CONF_MGMT_LIST_CONF_GATEKEEPER_USERNAME"] = CONF_MGMT_LIST_CONF_GATEKEEPER_USERNAME_FA;
            LangStringsHash["CONF_MGMT_LIST_CONF_GATEKEEPER_PASSWORD"] = CONF_MGMT_LIST_CONF_GATEKEEPER_PASSWORD_FA;
            LangStringsHash["CONF_MGMT_LIST_CONF_SIPSERVER"] = CONF_MGMT_LIST_CONF_SIPSERVER_FA;
            LangStringsHash["CONF_MGMT_LIST_CONF_SIPSERVER_ADDRESS"] = CONF_MGMT_LIST_CONF_SIPSERVER_ADDRESS_FA;
            LangStringsHash["CONF_MGMT_LIST_CONF_SIPSERVER_USERNAME"] = CONF_MGMT_LIST_CONF_SIPSERVER_USERNAME_FA;
            LangStringsHash["CONF_MGMT_LIST_CONF_SIPSERVER_PASSWORD"] = CONF_MGMT_LIST_CONF_SIPSERVER_PASSWORD_FA;
            LangStringsHash["CONF_MGMT_TEMPLATES_TABLE_TITLE"] = CONF_MGMT_TEMPLATES_TABLE_TITLE_FA;
            LangStringsHash["CONF_MGMT_TEMPLATES_INFO_TITLE"] = CONF_MGMT_TEMPLATES_INFO_TITLE_FA;
            LangStringsHash["CONF_MGMT_TEMPLATES_CREATE_TEXT"] = CONF_MGMT_TEMPLATES_CREATE_TEXT_FA;
            LangStringsHash["CONF_MGMT_TEMPLATES_EDIT_TEXT"] = CONF_MGMT_TEMPLATES_EDIT_TEXT_FA;
            LangStringsHash["CONF_MGMT_TEMPLATES_DELETE_TEXT"] = CONF_MGMT_TEMPLATES_DELETE_TEXT_FA;
            LangStringsHash["CONF_MGMT_TEMPLATES_HOLD_TEXT"] = CONF_MGMT_TEMPLATES_HOLD_TEXT_FA;
            LangStringsHash["WINDOW_TITLE_PHONEBOOK"] = WINDOW_TITLE_PHONEBOOK_FA;
            LangStringsHash["CONF_ROOMS_MSG_END_CONF_TITLE"] = CONF_ROOMS_MSG_END_CONF_TITLE_FA;
            LangStringsHash["CONF_ROOMS_MSG_END_CONF_MSG"] = CONF_ROOMS_MSG_END_CONF_MSG_FA;
            LangStringsHash["CONF_ROOMS_CONF_INFO"] = CONF_ROOMS_CONF_INFO_FA;
            LangStringsHash["CONF_ROOMS_CONF_LIST"] = CONF_ROOMS_CONF_LIST_FA;
            LangStringsHash["CONF_ROOMS_CONF_RATE"] = CONF_ROOMS_CONF_RATE_FA;
            LangStringsHash["CONF_ROOMS_E164ID"] = CONF_ROOMS_E164ID_FA;
            LangStringsHash["CONF_ROOMS_MT_INFO"] = CONF_ROOMS_MT_INFO_FA;
            LangStringsHash["CONF_ROOMS_MT_ALIAS"] = CONF_ROOMS_MT_ALIAS_FA;
            LangStringsHash["CONF_ROOMS_IP_ADDR"] = CONF_ROOMS_IP_ADDR_FA;
            LangStringsHash["CONF_ROOMS_CALL_MODE"] = CONF_ROOMS_CALL_MODE_FA;
            LangStringsHash["CONF_ROOMS_TX_RATE"] = CONF_ROOMS_TX_RATE_FA;
            LangStringsHash["CONF_ROOMS_RX_RATE"] = CONF_ROOMS_RX_RATE_FA;
            LangStringsHash["CONF_ROOMS_MT_CALL_RATE"] = CONF_ROOMS_MT_CALL_RATE_FA;
            LangStringsHash["CONF_ROOMS_AUDIO_SRC"] = CONF_ROOMS_AUDIO_SRC_FA;
            LangStringsHash["CONF_ROOMS_VIDEO_SRC"] = CONF_ROOMS_VIDEO_SRC_FA;
            LangStringsHash["CONF_ROOMS_MT_STATUS"] = CONF_ROOMS_MT_STATUS_FA;
            LangStringsHash["CONF_ROOMS_MUTE"] = CONF_ROOMS_MUTE_FA;
            LangStringsHash["CONF_ROOMS_DUMB"] = CONF_ROOMS_DUMB_FA;
            LangStringsHash["CONF_ROOMS_VOL_IN"] = CONF_ROOMS_VOL_IN_FA;
            LangStringsHash["CONF_ROOMS_VOL_OUT"] = CONF_ROOMS_VOL_OUT_FA;
            LangStringsHash["CONF_ROOMS_CHAIRMAN"] = CONF_ROOMS_CHAIRMAN_FA;
            LangStringsHash["CONF_ROOMS_SPEAKER"] = CONF_ROOMS_SPEAKER_FA;
            LangStringsHash["CONF_ROOMS_CONTINUOUS_PRESENCE"] = CONF_ROOMS_CONTINUOUS_PRESENCE_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_1"] = CONF_ROOMS_CP_PICS_1_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_2_LEFT_RIGHT"] = CONF_ROOMS_CP_PICS_2_LEFT_RIGHT_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_2_TOP_BOTTOM"] = CONF_ROOMS_CP_PICS_2_TOP_BOTTOM_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_3_HORIZONTAL"] = CONF_ROOMS_CP_PICS_3_HORIZONTAL_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_3_VERTICAL"] = CONF_ROOMS_CP_PICS_3_VERTICAL_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_4"] = CONF_ROOMS_CP_PICS_4_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_4_ACTIVE_VOICE"] = CONF_ROOMS_CP_PICS_4_ACTIVE_VOICE_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_5"] = CONF_ROOMS_CP_PICS_5_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_6_HORIZONTAL"] = CONF_ROOMS_CP_PICS_6_HORIZONTAL_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_6_VERTICAL"] = CONF_ROOMS_CP_PICS_6_VERTICAL_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_7"] = CONF_ROOMS_CP_PICS_7_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_8"] = CONF_ROOMS_CP_PICS_8_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_9"] = CONF_ROOMS_CP_PICS_9_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_9_ACTIVE_VOICE"] = CONF_ROOMS_CP_PICS_9_ACTIVE_VOICE_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_10"] = CONF_ROOMS_CP_PICS_10_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_11"] = CONF_ROOMS_CP_PICS_11_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_12"] = CONF_ROOMS_CP_PICS_12_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_12_VERTICAL"] = CONF_ROOMS_CP_PICS_12_VERTICAL_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_13"] = CONF_ROOMS_CP_PICS_13_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_14"] = CONF_ROOMS_CP_PICS_14_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_15"] = CONF_ROOMS_CP_PICS_15_FA;
            LangStringsHash["CONF_ROOMS_CP_PICS_16"] = CONF_ROOMS_CP_PICS_16_FA;
            LangStringsHash["CONF_ROOMS_CP_CELL_NO_PIC"] = CONF_ROOMS_CP_CELL_NO_PIC_FA;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_CALL"] = CONF_ROOMS_PRTCPNT_CTX_CALL_FA;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_HANGUP"] = CONF_ROOMS_PRTCPNT_CTX_HANGUP_FA;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_SET_AS_MNGR"] = CONF_ROOMS_PRTCPNT_CTX_SET_AS_MNGR_FA;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_SET_AS_SPK"] = CONF_ROOMS_PRTCPNT_CTX_SET_AS_SPK_FA;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_VIEW"] = CONF_ROOMS_PRTCPNT_CTX_VIEW_FA;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_RM_FROM_CONF"] = CONF_ROOMS_PRTCPNT_CTX_RM_FROM_CONF_FA;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_MUTE_SPK"] = CONF_ROOMS_PRTCPNT_CTX_MUTE_SPK_FA;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_MUTE_MIC"] = CONF_ROOMS_PRTCPNT_CTX_MUTE_MIC_FA;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_RECV_VID"] = CONF_ROOMS_PRTCPNT_CTX_RECV_VID_FA;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_SEND_VID"] = CONF_ROOMS_PRTCPNT_CTX_SEND_VID_FA;
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_ADD_TO_ADDR_BOOK"] = CONF_ROOMS_PRTCPNT_CTX_ADD_TO_ADDR_BOOK_FA;
            LangStringsHash["CONF_ROOMS_PRTCPNT_MSG_ERASE_TITLE"] = CONF_ROOMS_PRTCPNT_MSG_ERASE_TITLE_FA;
            LangStringsHash["CONF_ROOMS_PRTCPNT_MSG_ERASE_MSG"] = CONF_ROOMS_PRTCPNT_MSG_ERASE_MSG_FA;
            LangStringsHash["CONF_ROOMS_LEGEND_DISCONNECT"] = CONF_ROOMS_LEGEND_DISCONNECT_FA;
            LangStringsHash["CONF_ROOMS_LEGEND_INCALL"] = CONF_ROOMS_LEGEND_INCALL_FA;
            LangStringsHash["CONF_ROOMS_LEGEND_MANAGER"] = CONF_ROOMS_LEGEND_MANAGER_FA;
            LangStringsHash["CONF_ROOMS_LEGEND_SPEAKER"] = CONF_ROOMS_LEGEND_SPEAKER_FA;
            LangStringsHash["CONF_ROOMS_END_CONF"] = CONF_ROOMS_END_CONF_FA;
            LangStringsHash["CONF_ROOMS_ADD_PARTICIPANT"] = CONF_ROOMS_ADD_PARTICIPANT_FA;
            LangStringsHash["CONF_ROOMS_DLG_ADD_PARTICIPANT_TITLE"] = CONF_ROOMS_DLG_ADD_PARTICIPANT_TITLE_FA;
            break;
            
        default:
            LangStringsHash["TEMPO_UNDER_CONSTRUCTION"] = L"";
            LangStringsHash["WARN_NO_SCRIPT"] =  L"";
            LangStringsHash["LOGIN_TITLE"] = L"";
            LangStringsHash["HOME_TITLE"] = L"";
            LangStringsHash["GENERAL_ACTIVE"] = L"";
            LangStringsHash["GENERAL_INACTIVE"] = L"";
            LangStringsHash["GENERAL_CONFIRM"] = L"";
            LangStringsHash["GENERAL_CANCEL"] = L"";
            LangStringsHash["GENERAL_INDEX"] = L"";
            LangStringsHash["GENERAL_ERASE"] = L"";
            LangStringsHash["GENERAL_EDIT"] = L"";
            LangStringsHash["GENERAL_ADD"] = L"";
            LangStringsHash["GENERAL_ADD_RETURN"] = L"";
            LangStringsHash["GENERAL_RETURN"] = L"";
            LangStringsHash["GENERAL_LAYOUT"] = L"";
            LangStringsHash["LOGIN_FORM_TITLE"] = L"";
            LangStringsHash["LOGIN_FORM_USER_TEXT"] = L"";
            LangStringsHash["LOGIN_FORM_PWD_TEXT"] = L"";
            LangStringsHash["LOGIN_FORM_CAPTCHA_TEXT"] = L"";
            LangStringsHash["LOGIN_FORM_EMAIL_TEXT"] = L"";
            LangStringsHash["LOGIN_FORM_LOGIN_TEXT"] = L"";
            LangStringsHash["LOGIN_FORM_RECOVER_TEXT"] = L"";
            LangStringsHash["LOGIN_FORM_FORGOT_TEXT"] = L"";
            LangStringsHash["LOGIN_FORM_ERR_LOGIN"] = L"";
            LangStringsHash["LOGIN_FORM_ERR_FORGOT"] = L"";
            LangStringsHash["LOGIN_FORM_MSG_FORGOT"] = L"";
            LangStringsHash["HML_WELCOME"] = L"";
            LangStringsHash["HML_SYSMON"] = L"";
            LangStringsHash["HML_USER_MANAGEMENT"] = L"";
            LangStringsHash["HML_SYSTEM_SETTINGS"] = L"";
            LangStringsHash["HML_MCU_SETTINGS"] = L"";
            LangStringsHash["HML_CONFERENCE_ROOMS"] = L"";
            LangStringsHash["HML_CONFERENCE_MANAGEMENT"] = L"";
            LangStringsHash["HML_EXIT"] = L"";
            LangStringsHash["HML_CONFERENCE_MANAGEMENT_CREATE_CONFERENCE"] = L"";
            LangStringsHash["HML_CONFERENCE_MANAGEMENT_TEMPLATES"] = L"";
            LangStringsHash["HML_CONFERENCE_MANAGEMENT_CONFERENCE_LIST"] = L"";
            LangStringsHash["HML_CONFERENCE_MANAGEMENT_TERMINAL_MANAGEMENT"] = L"";
            LangStringsHash["HML_MCU_SETTINGS_CODEC_SETTINGS"] = L"";
            LangStringsHash["HML_MCU_SETTINGS_SIGNALING_SETTINGS"] = L"";
            LangStringsHash["HML_MCU_SETTINGS_SIP_SERVER_SETTINGS"] = L"";
            LangStringsHash["HML_MCU_SETTINGS_GATE_KEEPER_SETTINGS"] = L"";
            LangStringsHash["HML_MCU_SETTINGS_STUN_SETTINGS"] = L"";
            LangStringsHash["HML_MCU_SETTINGS_DSP_SETTINGS"] = L"";
            LangStringsHash["HML_SYSMON_GENERAL_INFO"] = L"";
            LangStringsHash["HML_SYSMON_SIGNALING_INFO"] = L"";
            LangStringsHash["HML_SYSMON_CODEC_INFO"] = L"";
            LangStringsHash["HML_SYSMON_SERVICES_INFO"] = L"";
            LangStringsHash["HML_SYSMON_DSP_INFO"] = L"";
            LangStringsHash["HML_USER_MANAGEMENT_USER_LOG"] = L"";
            LangStringsHash["HML_USER_MANAGEMENT_USERS"] = L"";
            LangStringsHash["WELCOME_GREETING"] = L"";
            LangStringsHash["WELCOME_CONFERENCE_LIST"] = L"";
            LangStringsHash["SYS_SETTINGS_CURRENT_DATE_TIME_TITLE"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_TYPE_TITLE"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_TYPE_IMMEDIATE_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_TYPE_BOOKED_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_NAME_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_ID_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_SIGNALING_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_GENERAL_TITLE"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_MEDIA_TITLE"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_OTHER_TITLE"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_DATETIME_TITLE"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_DATE_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_TIME_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_GATEKEEPER_TITLE"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_GK_IP_ADDR_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_GK_USER_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_GK_PWD_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_SIPSERVER_TITLE"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_SIP_IP_ADDR_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_SIP_USER_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_SIP_PWD_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_AUDIO_CODEC_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_VIDEO_CODEC_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_VIDEO_RES_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_CONF_RATE_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_NUM_OF_PARTICIPANTS_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_HAS_H239_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_EXTERNAL_USER_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_SEND_TO_SERVER_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_AUTO_ENDING_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_MANUAL_ENDING_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_PARTICIPANTS_TITLE"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_SELECT_PHONEBOOK_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_PHONEBOOK_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_NEW_CONTACT_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_PARTICIPANT_NAME_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_PARTICIPANT_ADDRESS_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_ADD_TO_PHONEBOOK_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_ADD_PARTICIPANT_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_SUBMIT_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_CREATE_SAVE_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_LIST_CONFERENCE_LIST"] = L"";
            LangStringsHash["CONF_MGMT_LIST_CONFERENCE_INFO"] = L"";
            LangStringsHash["CONF_MGMT_LIST_CONFERENCE_TIME"] = L"";
            LangStringsHash["CONF_MGMT_LIST_CONF_SEND_TO_SERVER"] = L"";
            LangStringsHash["CONF_MGMT_LIST_CONF_STREAM_DEST"] = L"";
            LangStringsHash["CONF_MGMT_LIST_CONF_GATEKEEPER"] = L"";
            LangStringsHash["CONF_MGMT_LIST_CONF_GATEKEEPER_ADDRESS"] = L"";
            LangStringsHash["CONF_MGMT_LIST_CONF_GATEKEEPER_USERNAME"] = L"";
            LangStringsHash["CONF_MGMT_LIST_CONF_GATEKEEPER_PASSWORD"] = L"";
            LangStringsHash["CONF_MGMT_LIST_CONF_SIPSERVER"] = L"";
            LangStringsHash["CONF_MGMT_LIST_CONF_SIPSERVER_ADDRESS"] = L"";
            LangStringsHash["CONF_MGMT_LIST_CONF_SIPSERVER_USERNAME"] = L"";
            LangStringsHash["CONF_MGMT_LIST_CONF_SIPSERVER_PASSWORD"] = L"";
            LangStringsHash["CONF_MGMT_TEMPLATES_TABLE_TITLE"] = L"";
            LangStringsHash["CONF_MGMT_TEMPLATES_INFO_TITLE"] = L"";
            LangStringsHash["CONF_MGMT_TEMPLATES_CREATE_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_TEMPLATES_EDIT_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_TEMPLATES_DELETE_TEXT"] = L"";
            LangStringsHash["CONF_MGMT_TEMPLATES_HOLD_TEXT"] = L"";
            LangStringsHash["WINDOW_TITLE_PHONEBOOK"] = L"";
            LangStringsHash["CONF_ROOMS_MSG_END_CONF_TITLE"] = L"";
            LangStringsHash["CONF_ROOMS_MSG_END_CONF_MSG"] = L"";
            LangStringsHash["CONF_ROOMS_CONF_INFO"] = L"";
            LangStringsHash["CONF_ROOMS_CONF_LIST"] = L"";
            LangStringsHash["CONF_ROOMS_CONF_RATE"] = L"";
            LangStringsHash["CONF_ROOMS_E164ID"] = L"";
            LangStringsHash["CONF_ROOMS_MT_INFO"] = L"";
            LangStringsHash["CONF_ROOMS_MT_ALIAS"] = L"";
            LangStringsHash["CONF_ROOMS_IP_ADDR"] = L"";
            LangStringsHash["CONF_ROOMS_CALL_MODE"] = L"";
            LangStringsHash["CONF_ROOMS_TX_RATE"] = L"";
            LangStringsHash["CONF_ROOMS_RX_RATE"] = L"";
            LangStringsHash["CONF_ROOMS_MT_CALL_RATE"] = L"";
            LangStringsHash["CONF_ROOMS_AUDIO_SRC"] = L"";
            LangStringsHash["CONF_ROOMS_VIDEO_SRC"] = L"";
            LangStringsHash["CONF_ROOMS_MT_STATUS"] = L"";
            LangStringsHash["CONF_ROOMS_MUTE"] = L"";
            LangStringsHash["CONF_ROOMS_DUMB"] = L"";
            LangStringsHash["CONF_ROOMS_VOL_IN"] = L"";
            LangStringsHash["CONF_ROOMS_VOL_OUT"] = L"";
            LangStringsHash["CONF_ROOMS_CHAIRMAN"] = L"";
            LangStringsHash["CONF_ROOMS_SPEAKER"] = L"";
            LangStringsHash["CONF_ROOMS_CONTINUOUS_PRESENCE"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_1"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_2_LEFT_RIGHT"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_2_TOP_BOTTOM"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_3_HORIZONTAL"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_3_VERTICAL"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_4"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_4_ACTIVE_VOICE"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_5"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_6_HORIZONTAL"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_6_VERTICAL"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_7"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_8"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_9"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_9_ACTIVE_VOICE"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_10"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_11"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_12"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_12_VERTICAL"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_13"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_14"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_15"] = L"";
            LangStringsHash["CONF_ROOMS_CP_PICS_16"] = L"";
            LangStringsHash["CONF_ROOMS_CP_CELL_NO_PIC"] = L"";
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_CALL"] = L"";
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_HANGUP"] = L"";
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_SET_AS_MNGR"] = L"";
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_SET_AS_SPK"] = L"";
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_VIEW"] = L"";
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_RM_FROM_CONF"] = L"";
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_MUTE_SPK"] = L"";
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_MUTE_MIC"] = L"";
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_RECV_VID"] = L"";
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_SEND_VID"] = L"";
            LangStringsHash["CONF_ROOMS_PRTCPNT_CTX_ADD_TO_ADDR_BOOK"] = L"";
            LangStringsHash["CONF_ROOMS_PRTCPNT_MSG_ERASE_TITLE"] = L"";
            LangStringsHash["CONF_ROOMS_PRTCPNT_MSG_ERASE_MSG"] = L"";
            LangStringsHash["CONF_ROOMS_LEGEND_DISCONNECT"] = L"";
            LangStringsHash["CONF_ROOMS_LEGEND_INCALL"] = L"";
            LangStringsHash["CONF_ROOMS_LEGEND_MANAGER"] = L"";
            LangStringsHash["CONF_ROOMS_LEGEND_SPEAKER"] = L"";
            LangStringsHash["CONF_ROOMS_END_CONF"] = L"";
            LangStringsHash["CONF_ROOMS_ADD_PARTICIPANT"] = L"";
            LangStringsHash["CONF_ROOMS_DLG_ADD_PARTICIPANT_TITLE"] = L"";
            break;
        }
    }
};


const wstring Lang::Impl::TEMPO_UNDER_CONSTRUCTION_EN = L"<center><span style=\"color: #666; font-weight: bolder; font-style: oblique; border-top: 1px solid #666;  border-bottom: 1px solid #666;\">This feature is under construction...</span></center>";
const wstring Lang::Impl::TEMPO_UNDER_CONSTRUCTION_FA = L"<center><span style=\"color: #666; font-weight: bolder; font-style: oblique; border-top: 1px solid #666;  border-bottom: 1px solid #666;\">این ویژگی در دست ساخت می باشد...</span></center>";

const wstring Lang::Impl::GENERAL_ACTIVE_EN = L"On";
const wstring Lang::Impl::GENERAL_ACTIVE_FA = L"فعال";
const wstring Lang::Impl::GENERAL_INACTIVE_EN = L"Off";
const wstring Lang::Impl::GENERAL_INACTIVE_FA = L"غیر غعال";

const wstring Lang::Impl::GENERAL_CONFIRM_EN = L"OK";
const wstring Lang::Impl::GENERAL_CONFIRM_FA = L"تائید";
const wstring Lang::Impl::GENERAL_CANCEL_EN = L"Cancel";
const wstring Lang::Impl::GENERAL_CANCEL_FA = L"لغو";

const wstring Lang::Impl::GENERAL_INDEX_EN = L"No.";
const wstring Lang::Impl::GENERAL_INDEX_FA = L"ردیف";

const wstring Lang::Impl::GENERAL_ERASE_EN = L"Erase";
const wstring Lang::Impl::GENERAL_ERASE_FA = L"حذف";
const wstring Lang::Impl::GENERAL_EDIT_EN = L"Edit";
const wstring Lang::Impl::GENERAL_EDIT_FA = L"ویرایش";

const wstring Lang::Impl::GENERAL_ADD_EN = L"Add";
const wstring Lang::Impl::GENERAL_ADD_FA = L"افزودن";
const wstring Lang::Impl::GENERAL_ADD_RETURN_EN = L"Add & Return";
const wstring Lang::Impl::GENERAL_ADD_RETURN_FA = L"افزودن و بازگشت";
const wstring Lang::Impl::GENERAL_RETURN_EN = L"Return";
const wstring Lang::Impl::GENERAL_RETURN_FA = L"بازگشت";

const wstring Lang::Impl::GENERAL_LAYOUT_EN = L"Layout";
const wstring Lang::Impl::GENERAL_LAYOUT_FA = L"طرح بندی";

const wstring Lang::Impl::WARN_NO_SCRIPT_EN = L"<noscript>"
                                      "<div class=\"dvNoScript\">"
                                      "Sorry, It looks like that either you have turned off "
                                      "the browser's javascript feature or your browser originally "
                                      "didn't support javascript feature at all. Some functions "
                                      "will not behave correctly unless you fix it."
                                      "</div>"
                                      "</noscript>";
const wstring Lang::Impl::WARN_NO_SCRIPT_FA = L"<noscript>"
                                      "<div class=\"dvNoScript\">"
                                      "كاربر گرامي مرورگر شما از جاوا اسكريپت پشتيباني نمي نمايد، "
                                      "و يا اينكه جاوا اسكريپت در مرورگر شما غیر فعال مي باشد؛ "
                                      "تا زمانیکه اقدام به رفع این مسئله ننمائید "
                                      "ممکن است برخی از قابلیت ها به درستی عمل ننمایند."
                                      "</div>"
                                      "</noscript>";

const wstring Lang::Impl::LOGIN_TITLE_EN = L".:: Login ::.";
const wstring Lang::Impl::LOGIN_TITLE_FA = L".:: ورود ::.";

const wstring Lang::Impl::HOME_TITLE_EN = L"Server Conference Management";
const wstring Lang::Impl::HOME_TITLE_FA = L"مدیریت سرور کنفرانس";

const wstring Lang::Impl::LOGIN_FORM_TITLE_EN = L"<h3>Login to Conference Panel</h3>";
const wstring Lang::Impl::LOGIN_FORM_TITLE_FA = L"<h3>ورود به پنل کنفرانس</h3>";
const wstring Lang::Impl::LOGIN_FORM_USER_TEXT_EN = L"Username";
const wstring Lang::Impl::LOGIN_FORM_USER_TEXT_FA = L"نام کاربری";
const wstring Lang::Impl::LOGIN_FORM_PWD_TEXT_EN = L"Password";
const wstring Lang::Impl::LOGIN_FORM_PWD_TEXT_FA = L"گذر واژه";
const wstring Lang::Impl::LOGIN_FORM_CAPTCHA_TEXT_EN = L"Captcha";
const wstring Lang::Impl::LOGIN_FORM_CAPTCHA_TEXT_FA = L"کد امنیتی";
const wstring Lang::Impl::LOGIN_FORM_EMAIL_TEXT_EN = L"Email";
const wstring Lang::Impl::LOGIN_FORM_EMAIL_TEXT_FA = L"ایمیل";
const wstring Lang::Impl::LOGIN_FORM_LOGIN_TEXT_EN = L"Login";
const wstring Lang::Impl::LOGIN_FORM_LOGIN_TEXT_FA = L"ورود";
const wstring Lang::Impl::LOGIN_FORM_RECOVER_TEXT_EN = L"Recover";
const wstring Lang::Impl::LOGIN_FORM_RECOVER_TEXT_FA = L"یادآوری";
const wstring Lang::Impl::LOGIN_FORM_FORGOT_TEXT_EN = L"Forgot Password";
const wstring Lang::Impl::LOGIN_FORM_FORGOT_TEXT_FA = L"کلمه عبور را فراموش کرده ام";
    
const wstring Lang::Impl::LOGIN_FORM_ERR_LOGIN_EN = L"Invalid username or password.";
const wstring Lang::Impl::LOGIN_FORM_ERR_LOGIN_FA = L"نام کاربری یا کلمه عبور نامعتبر می باشد";
const wstring Lang::Impl::LOGIN_FORM_ERR_FORGOT_EN = L"Invalid user.";
const wstring Lang::Impl::LOGIN_FORM_ERR_FORGOT_FA = L"نام کاربری نا معتبر می باشد";
const wstring Lang::Impl::LOGIN_FORM_MSG_FORGOT_EN = L"Password recovered successfully, Please check your email.";
const wstring Lang::Impl::LOGIN_FORM_MSG_FORGOT_FA = L"کلمه عبور با موفقیت بازیابی شد، لطفا ایمیل تان را چک نمائید";   

const wstring Lang::Impl::HML_WELCOME_EN = L"Home";
const wstring Lang::Impl::HML_WELCOME_FA = L"صفحه اصلی";
const wstring Lang::Impl::HML_SYSMON_EN = L"System Monitor";
const wstring Lang::Impl::HML_SYSMON_FA = L"مشاهده وضعیت سیستم";
const wstring Lang::Impl::HML_USER_MANAGEMENT_EN = L"User Management";
const wstring Lang::Impl::HML_USER_MANAGEMENT_FA = L"مدیریت کاربران";
const wstring Lang::Impl::HML_SYSTEM_SETTINGS_EN = L"System Settings";
const wstring Lang::Impl::HML_SYSTEM_SETTINGS_FA = L"تنظیمات سیستم";
const wstring Lang::Impl::HML_MCU_SETTINGS_EN = L"MCU Settings";
const wstring Lang::Impl::HML_MCU_SETTINGS_FA = L"تنظیمات سرور پردازشگر رسانه";
const wstring Lang::Impl::HML_CONFERENCE_ROOMS_EN = L"Conference Rooms";
const wstring Lang::Impl::HML_CONFERENCE_ROOMS_FA = L"اتاق های کنفرانس";
const wstring Lang::Impl::HML_CONFERENCE_MANAGEMENT_EN = L"Conference Management";
const wstring Lang::Impl::HML_CONFERENCE_MANAGEMENT_FA = L"مدیریت کنفرانس";
const wstring Lang::Impl::HML_EXIT_EN = L"Exit";
const wstring Lang::Impl::HML_EXIT_FA = L"خروج";

const wstring Lang::Impl::HML_CONFERENCE_MANAGEMENT_CREATE_CONFERENCE_EN = L"Create Conference";
const wstring Lang::Impl::HML_CONFERENCE_MANAGEMENT_CREATE_CONFERENCE_FA = L"ایجاد کنفرانس";
const wstring Lang::Impl::HML_CONFERENCE_MANAGEMENT_TEMPLATES_EN = L"Templates";
const wstring Lang::Impl::HML_CONFERENCE_MANAGEMENT_TEMPLATES_FA = L"قالب ها";
const wstring Lang::Impl::HML_CONFERENCE_MANAGEMENT_CONFERENCE_LIST_EN = L"Conference List";
const wstring Lang::Impl::HML_CONFERENCE_MANAGEMENT_CONFERENCE_LIST_FA = L"لیست کنفرانس ها";
const wstring Lang::Impl::HML_CONFERENCE_MANAGEMENT_TERMINAL_MANAGEMENT_EN = L"Terminal Management";
const wstring Lang::Impl::HML_CONFERENCE_MANAGEMENT_TERMINAL_MANAGEMENT_FA = L"مدیریت ترمینال ها";

const wstring Lang::Impl::HML_MCU_SETTINGS_CODEC_SETTINGS_EN = L"Codec Settings";
const wstring Lang::Impl::HML_MCU_SETTINGS_CODEC_SETTINGS_FA = L"تنظیمات Codec";
const wstring Lang::Impl::HML_MCU_SETTINGS_SIGNALING_SETTINGS_EN = L"Signaling Settings";
const wstring Lang::Impl::HML_MCU_SETTINGS_SIGNALING_SETTINGS_FA = L"تنظیمات Signaling";
const wstring Lang::Impl::HML_MCU_SETTINGS_SIP_SERVER_SETTINGS_EN = L"SIP-Server Settings";
const wstring Lang::Impl::HML_MCU_SETTINGS_SIP_SERVER_SETTINGS_FA = L"تنظیمات SIP-Server";
const wstring Lang::Impl::HML_MCU_SETTINGS_GATE_KEEPER_SETTINGS_EN = L"Gake-Keeper Settings";
const wstring Lang::Impl::HML_MCU_SETTINGS_GATE_KEEPER_SETTINGS_FA = L"تنظیمات Gate-Keeper";
const wstring Lang::Impl::HML_MCU_SETTINGS_STUN_SETTINGS_EN = L"STUN Settings";
const wstring Lang::Impl::HML_MCU_SETTINGS_STUN_SETTINGS_FA = L"تنظیمات STUN";
const wstring Lang::Impl::HML_MCU_SETTINGS_DSP_SETTINGS_EN = L"DSP Settings";
const wstring Lang::Impl::HML_MCU_SETTINGS_DSP_SETTINGS_FA = L"تنظیمات DSP";

const wstring Lang::Impl::HML_SYSMON_GENERAL_INFO_EN = L"General Info";
const wstring Lang::Impl::HML_SYSMON_GENERAL_INFO_FA = L"گزارشات عمومی";
const wstring Lang::Impl::HML_SYSMON_SIGNALING_INFO_EN = L"Signaling Info";
const wstring Lang::Impl::HML_SYSMON_SIGNALING_INFO_FA = L"گزارشات Signaling";
const wstring Lang::Impl::HML_SYSMON_CODEC_INFO_EN = L"Codec Info";
const wstring Lang::Impl::HML_SYSMON_CODEC_INFO_FA = L"گزارشات Codec";
const wstring Lang::Impl::HML_SYSMON_SERVICES_INFO_EN = L"Services Info";
const wstring Lang::Impl::HML_SYSMON_SERVICES_INFO_FA = L"گزارشات Service ها";
const wstring Lang::Impl::HML_SYSMON_DSP_INFO_EN = L"DSP Info";
const wstring Lang::Impl::HML_SYSMON_DSP_INFO_FA = L"گزارشات DSP";

const wstring Lang::Impl::HML_USER_MANAGEMENT_USER_LOG_EN = L"User Log";
const wstring Lang::Impl::HML_USER_MANAGEMENT_USER_LOG_FA = L"گزارشات کاربری";
const wstring Lang::Impl::HML_USER_MANAGEMENT_USERS_EN = L"Users";
const wstring Lang::Impl::HML_USER_MANAGEMENT_USERS_FA = L"کاربران";

const wstring Lang::Impl::WELCOME_GREETING_EN = L"Welcome to Hiva Rayan MCU";
const wstring Lang::Impl::WELCOME_GREETING_FA = L"به سامانه سرور پردازشگر هیوا خوش آمدید";
const wstring Lang::Impl::WELCOME_CONFERENCE_LIST_EN = L"Currently running conferences";
const wstring Lang::Impl::WELCOME_CONFERENCE_LIST_FA = L"لیست کنفرانس های در حال اجرا";

const wstring Lang::Impl::SYS_SETTINGS_CURRENT_DATE_TIME_TITLE_EN = L"Current System Date and Time";
const wstring Lang::Impl::SYS_SETTINGS_CURRENT_DATE_TIME_TITLE_FA = L"تاریخ و ساعت فعلی سیستم";

const wstring Lang::Impl::CONF_MGMT_CREATE_TYPE_TITLE_EN = L"Conference Type";
const wstring Lang::Impl::CONF_MGMT_CREATE_TYPE_TITLE_FA = L"نوع کنفرانس";
const wstring Lang::Impl::CONF_MGMT_CREATE_TYPE_IMMEDIATE_TEXT_EN = L"Immediate";
const wstring Lang::Impl::CONF_MGMT_CREATE_TYPE_IMMEDIATE_TEXT_FA = L"بلافاصله";
const wstring Lang::Impl::CONF_MGMT_CREATE_TYPE_BOOKED_TEXT_EN = L"Booked";
const wstring Lang::Impl::CONF_MGMT_CREATE_TYPE_BOOKED_TEXT_FA = L"زمان بندی شده";
const wstring Lang::Impl::CONF_MGMT_CREATE_NAME_TEXT_EN = L"Conference Name";
const wstring Lang::Impl::CONF_MGMT_CREATE_NAME_TEXT_FA = L"نام کنفرانس";
const wstring Lang::Impl::CONF_MGMT_CREATE_ID_TEXT_EN = L"Conference ID";
const wstring Lang::Impl::CONF_MGMT_CREATE_ID_TEXT_FA = L"شناسه کنفرانس";
const wstring Lang::Impl::CONF_MGMT_CREATE_SIGNALING_TEXT_EN = L"Signaling";
const wstring Lang::Impl::CONF_MGMT_CREATE_SIGNALING_TEXT_FA = L"سیگنالینگ";

const wstring Lang::Impl::CONF_MGMT_CREATE_GENERAL_TITLE_EN = L"General Info";
const wstring Lang::Impl::CONF_MGMT_CREATE_GENERAL_TITLE_FA = L"مشخصات عمومی";
const wstring Lang::Impl::CONF_MGMT_CREATE_MEDIA_TITLE_EN = L"Media Info";
const wstring Lang::Impl::CONF_MGMT_CREATE_MEDIA_TITLE_FA = L"مشخصات رسانه";
const wstring Lang::Impl::CONF_MGMT_CREATE_OTHER_TITLE_EN = L"Other Info";
const wstring Lang::Impl::CONF_MGMT_CREATE_OTHER_TITLE_FA = L"سایر مشخصات";
    
const wstring Lang::Impl::CONF_MGMT_CREATE_DATETIME_TITLE_EN = L"Date & Time";
const wstring Lang::Impl::CONF_MGMT_CREATE_DATETIME_TITLE_FA = L"ساعت و تاریخ";
const wstring Lang::Impl::CONF_MGMT_CREATE_DATE_TEXT_EN = L"Date";
const wstring Lang::Impl::CONF_MGMT_CREATE_DATE_TEXT_FA = L"تاریخ";
const wstring Lang::Impl::CONF_MGMT_CREATE_TIME_TEXT_EN = L"Time";
const wstring Lang::Impl::CONF_MGMT_CREATE_TIME_TEXT_FA = L"زمان";
        
const wstring Lang::Impl::CONF_MGMT_CREATE_GATEKEEPER_TITLE_EN = L"Gatekeeper Settings";
const wstring Lang::Impl::CONF_MGMT_CREATE_GATEKEEPER_TITLE_FA = L"تنظیمات Gatekeeper";
const wstring Lang::Impl::CONF_MGMT_CREATE_GK_IP_ADDR_TEXT_EN = L"IP Address";
const wstring Lang::Impl::CONF_MGMT_CREATE_GK_IP_ADDR_TEXT_FA = L"آدرس IP";
const wstring Lang::Impl::CONF_MGMT_CREATE_GK_USER_TEXT_EN = L"Username";
const wstring Lang::Impl::CONF_MGMT_CREATE_GK_USER_TEXT_FA = L"نام کاربری";
const wstring Lang::Impl::CONF_MGMT_CREATE_GK_PWD_TEXT_EN = L"Password";
const wstring Lang::Impl::CONF_MGMT_CREATE_GK_PWD_TEXT_FA = L"کلمه عبور";
    
const wstring Lang::Impl::CONF_MGMT_CREATE_SIPSERVER_TITLE_EN = L"SIP-Server Settings";
const wstring Lang::Impl::CONF_MGMT_CREATE_SIPSERVER_TITLE_FA = L"تنظیمات SIP-Server";
const wstring Lang::Impl::CONF_MGMT_CREATE_SIP_IP_ADDR_TEXT_EN = L"IP Address";
const wstring Lang::Impl::CONF_MGMT_CREATE_SIP_IP_ADDR_TEXT_FA = L"آدرس IP";
const wstring Lang::Impl::CONF_MGMT_CREATE_SIP_USER_TEXT_EN = L"Username";
const wstring Lang::Impl::CONF_MGMT_CREATE_SIP_USER_TEXT_FA = L"نام کاربری";
const wstring Lang::Impl::CONF_MGMT_CREATE_SIP_PWD_TEXT_EN = L"Password";
const wstring Lang::Impl::CONF_MGMT_CREATE_SIP_PWD_TEXT_FA = L"کلمه عبور";
    
const wstring Lang::Impl::CONF_MGMT_CREATE_AUDIO_CODEC_TEXT_EN = L"Audio Codec";
const wstring Lang::Impl::CONF_MGMT_CREATE_AUDIO_CODEC_TEXT_FA = L"کدک صدا";
const wstring Lang::Impl::CONF_MGMT_CREATE_VIDEO_CODEC_TEXT_EN = L"Video Codec";
const wstring Lang::Impl::CONF_MGMT_CREATE_VIDEO_CODEC_TEXT_FA = L"کدک تصویر";
const wstring Lang::Impl::CONF_MGMT_CREATE_VIDEO_RES_TEXT_EN = L"Video Resolution";
const wstring Lang::Impl::CONF_MGMT_CREATE_VIDEO_RES_TEXT_FA = L"اندازه تصویر";
const wstring Lang::Impl::CONF_MGMT_CREATE_CONF_RATE_TEXT_EN = L"Conference Rate";
const wstring Lang::Impl::CONF_MGMT_CREATE_CONF_RATE_TEXT_FA = L"نرخ کنفرانس";
const wstring Lang::Impl::CONF_MGMT_CREATE_NUM_OF_PARTICIPANTS_TEXT_EN = L"Number of Participants";
const wstring Lang::Impl::CONF_MGMT_CREATE_NUM_OF_PARTICIPANTS_TEXT_FA = L"تعداد شرکت کنندگان";

const wstring Lang::Impl::CONF_MGMT_CREATE_HAS_H239_TEXT_EN = L"Content Transfer";
const wstring Lang::Impl::CONF_MGMT_CREATE_HAS_H239_TEXT_FA = L"ارسال محتوا";
const wstring Lang::Impl::CONF_MGMT_CREATE_EXTERNAL_USER_TEXT_EN = L"Accept joining participants";
const wstring Lang::Impl::CONF_MGMT_CREATE_EXTERNAL_USER_TEXT_FA = L"اتصال شرکت کننده از بیرون کنفرانس";
const wstring Lang::Impl::CONF_MGMT_CREATE_SEND_TO_SERVER_TEXT_EN = L"Send conference to stream server at";
const wstring Lang::Impl::CONF_MGMT_CREATE_SEND_TO_SERVER_TEXT_FA = L"ارسال کنفرانس به سرور استریم به آدرس";
const wstring Lang::Impl::CONF_MGMT_CREATE_AUTO_ENDING_TEXT_EN = L"Conference automatically ends after";
const wstring Lang::Impl::CONF_MGMT_CREATE_AUTO_ENDING_TEXT_FA = L"پایان خودکار بعد از مدت (به ساعت)";
const wstring Lang::Impl::CONF_MGMT_CREATE_MANUAL_ENDING_TEXT_EN = L"End the conference manually";
const wstring Lang::Impl::CONF_MGMT_CREATE_MANUAL_ENDING_TEXT_FA = L"پایان کنفرانس توسط کاربر";

const wstring Lang::Impl::CONF_MGMT_CREATE_PARTICIPANTS_TITLE_EN = L"Participants";
const wstring Lang::Impl::CONF_MGMT_CREATE_PARTICIPANTS_TITLE_FA = L"شرکت کنندگان";
const wstring Lang::Impl::CONF_MGMT_CREATE_SELECT_PHONEBOOK_TEXT_EN = L"Add from phonebook";
const wstring Lang::Impl::CONF_MGMT_CREATE_SELECT_PHONEBOOK_TEXT_FA = L"انتخاب از دفترچه تلفن";
const wstring Lang::Impl::CONF_MGMT_CREATE_PHONEBOOK_TEXT_EN = L"Phonebook";
const wstring Lang::Impl::CONF_MGMT_CREATE_PHONEBOOK_TEXT_FA = L"دفترچه تلفن...";
const wstring Lang::Impl::CONF_MGMT_CREATE_NEW_CONTACT_TEXT_EN = L"New Contact";
const wstring Lang::Impl::CONF_MGMT_CREATE_NEW_CONTACT_TEXT_FA = L"شماره جدید";
const wstring Lang::Impl::CONF_MGMT_CREATE_PARTICIPANT_NAME_TEXT_EN = L"Name";
const wstring Lang::Impl::CONF_MGMT_CREATE_PARTICIPANT_NAME_TEXT_FA = L"نام";
const wstring Lang::Impl::CONF_MGMT_CREATE_PARTICIPANT_ADDRESS_TEXT_EN = L"IP Address";
const wstring Lang::Impl::CONF_MGMT_CREATE_PARTICIPANT_ADDRESS_TEXT_FA = L"آدرس IP";
const wstring Lang::Impl::CONF_MGMT_CREATE_ADD_TO_PHONEBOOK_TEXT_EN = L"Add to phonebook";
const wstring Lang::Impl::CONF_MGMT_CREATE_ADD_TO_PHONEBOOK_TEXT_FA = L"به دفترچه تلفن افزوده شود";
const wstring Lang::Impl::CONF_MGMT_CREATE_ADD_PARTICIPANT_TEXT_EN = L"Add";
const wstring Lang::Impl::CONF_MGMT_CREATE_ADD_PARTICIPANT_TEXT_FA = L"اضافه شود";

const wstring Lang::Impl::CONF_MGMT_CREATE_SUBMIT_TEXT_EN = L"Submit";
const wstring Lang::Impl::CONF_MGMT_CREATE_SUBMIT_TEXT_FA = L"ثبت شود";
const wstring Lang::Impl::CONF_MGMT_CREATE_SAVE_TEXT_EN = L"Save as Template";
const wstring Lang::Impl::CONF_MGMT_CREATE_SAVE_TEXT_FA = L"ذخیره برای استفاده مجدد";

const wstring Lang::Impl::CONF_MGMT_LIST_CONFERENCE_LIST_EN = L"Scheduled Conferences";
const wstring Lang::Impl::CONF_MGMT_LIST_CONFERENCE_LIST_FA = L"کنفرانس های برنامه ریزی شده";
const wstring Lang::Impl::CONF_MGMT_LIST_CONFERENCE_INFO_EN = L"Conference Information";
const wstring Lang::Impl::CONF_MGMT_LIST_CONFERENCE_INFO_FA = L"اطلاعات کنفرانس";
const wstring Lang::Impl::CONF_MGMT_LIST_CONFERENCE_TIME_EN = L"Conference Time and Date";
const wstring Lang::Impl::CONF_MGMT_LIST_CONFERENCE_TIME_FA = L"تاریخ و زمان کنفرانس";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_SEND_TO_SERVER_EN = L"Send conference to stream server";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_SEND_TO_SERVER_FA = L"ارسال کنفرانس به سرور استریم";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_STREAM_DEST_EN = L"Server stream IP address";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_STREAM_DEST_FA = L"آدرس سرور استریم";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_GATEKEEPER_EN = L"Connect to Gatekeeper";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_GATEKEEPER_FA = L"اتصال به Gatekeeper";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_GATEKEEPER_ADDRESS_EN = L"Gatekeeper IP address";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_GATEKEEPER_ADDRESS_FA = L"آدرس Gatekeeper";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_GATEKEEPER_USERNAME_EN = L"Gatekeeper Username";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_GATEKEEPER_USERNAME_FA = L"نام کاربری Gatekeeper";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_GATEKEEPER_PASSWORD_EN = L"Gatekeeper Password";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_GATEKEEPER_PASSWORD_FA = L"کلمه عبور Gatekeeper";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_SIPSERVER_EN = L"Connect to SIP server";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_SIPSERVER_FA = L"اتصال به سرور SIP";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_SIPSERVER_ADDRESS_EN = L"SIP server address";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_SIPSERVER_ADDRESS_FA = L"آدرس سرور SIP";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_SIPSERVER_USERNAME_EN = L"SIP server username";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_SIPSERVER_USERNAME_FA = L"نام کاربری سرور SIP";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_SIPSERVER_PASSWORD_EN = L"SIP server password";
const wstring Lang::Impl::CONF_MGMT_LIST_CONF_SIPSERVER_PASSWORD_FA = L"کلمه عبور سرور SIP";

const wstring Lang::Impl::CONF_MGMT_TEMPLATES_TABLE_TITLE_EN = L"Templates";
const wstring Lang::Impl::CONF_MGMT_TEMPLATES_TABLE_TITLE_FA = L"قالب ها";
const wstring Lang::Impl::CONF_MGMT_TEMPLATES_INFO_TITLE_EN = L"Template Information";
const wstring Lang::Impl::CONF_MGMT_TEMPLATES_INFO_TITLE_FA = L"اطلاعات قالب";
const wstring Lang::Impl::CONF_MGMT_TEMPLATES_CREATE_TEXT_EN = L"Create";
const wstring Lang::Impl::CONF_MGMT_TEMPLATES_CREATE_TEXT_FA = L"قالب جدید";
const wstring Lang::Impl::CONF_MGMT_TEMPLATES_EDIT_TEXT_EN = L"Edit";
const wstring Lang::Impl::CONF_MGMT_TEMPLATES_EDIT_TEXT_FA = L"ویرایش قالب";
const wstring Lang::Impl::CONF_MGMT_TEMPLATES_DELETE_TEXT_EN = L"Delete";
const wstring Lang::Impl::CONF_MGMT_TEMPLATES_DELETE_TEXT_FA = L"حذف قالب";
const wstring Lang::Impl::CONF_MGMT_TEMPLATES_HOLD_TEXT_EN = L"Hold Conference";
const wstring Lang::Impl::CONF_MGMT_TEMPLATES_HOLD_TEXT_FA = L"برگزاری";

const wstring Lang::Impl::WINDOW_TITLE_PHONEBOOK_EN = L"Phonebook";
const wstring Lang::Impl::WINDOW_TITLE_PHONEBOOK_FA = L"دفترچه تلفن";

const wstring Lang::Impl::CONF_ROOMS_MSG_END_CONF_TITLE_EN = L"Terminate Conference";
const wstring Lang::Impl::CONF_ROOMS_MSG_END_CONF_TITLE_FA = L"خاتمه کنفرانس";
const wstring Lang::Impl::CONF_ROOMS_MSG_END_CONF_MSG_EN = L"Do you want to terminate the running conference?";
const wstring Lang::Impl::CONF_ROOMS_MSG_END_CONF_MSG_FA = L"آیا مایل به خاتمه کنفرانس در حال اجرا می باشید؟";

const wstring Lang::Impl::CONF_ROOMS_CONF_INFO_EN = L"Conference Information";
const wstring Lang::Impl::CONF_ROOMS_CONF_INFO_FA = L"اطلاعات کنفرانس";
const wstring Lang::Impl::CONF_ROOMS_CONF_LIST_EN = L"Conference Name";
const wstring Lang::Impl::CONF_ROOMS_CONF_LIST_FA = L"نام کنفرانس";
const wstring Lang::Impl::CONF_ROOMS_CONF_RATE_EN = L"Conference Rate";
const wstring Lang::Impl::CONF_ROOMS_CONF_RATE_FA = L"نرخ کنفرانس";
const wstring Lang::Impl::CONF_ROOMS_E164ID_EN = L"E 164 ID";
const wstring Lang::Impl::CONF_ROOMS_E164ID_FA = L"شناسه کنفرانس";
const wstring Lang::Impl::CONF_ROOMS_MT_INFO_EN = L"MT Information";
const wstring Lang::Impl::CONF_ROOMS_MT_INFO_FA = L"اطلاعات ترمینال";
const wstring Lang::Impl::CONF_ROOMS_MT_ALIAS_EN = L"MT Alias";
const wstring Lang::Impl::CONF_ROOMS_MT_ALIAS_FA = L"نام ترمینال";
const wstring Lang::Impl::CONF_ROOMS_IP_ADDR_EN = L"IP Address";
const wstring Lang::Impl::CONF_ROOMS_IP_ADDR_FA = L"آدرس ترمینال";
const wstring Lang::Impl::CONF_ROOMS_CALL_MODE_EN = L"Call Mode";
const wstring Lang::Impl::CONF_ROOMS_CALL_MODE_FA = L"نوع تماس";
const wstring Lang::Impl::CONF_ROOMS_TX_RATE_EN = L"Tx Rate";
const wstring Lang::Impl::CONF_ROOMS_TX_RATE_FA = L"نرخ ارسال";
const wstring Lang::Impl::CONF_ROOMS_RX_RATE_EN = L"Rx Rate";
const wstring Lang::Impl::CONF_ROOMS_RX_RATE_FA = L"نرخ دریافت";
const wstring Lang::Impl::CONF_ROOMS_MT_CALL_RATE_EN = L"MT Call Rate";
const wstring Lang::Impl::CONF_ROOMS_MT_CALL_RATE_FA = L"نرخ تماس ترمینال";
const wstring Lang::Impl::CONF_ROOMS_AUDIO_SRC_EN = L"Audio Source";
const wstring Lang::Impl::CONF_ROOMS_AUDIO_SRC_FA = L"منبع صدا";
const wstring Lang::Impl::CONF_ROOMS_VIDEO_SRC_EN = L"Video Source";
const wstring Lang::Impl::CONF_ROOMS_VIDEO_SRC_FA = L"منبع تصویر";
const wstring Lang::Impl::CONF_ROOMS_MT_STATUS_EN = L"MT Status";
const wstring Lang::Impl::CONF_ROOMS_MT_STATUS_FA = L"وضعیت ترمینال";
const wstring Lang::Impl::CONF_ROOMS_MUTE_EN = L"Mute";
const wstring Lang::Impl::CONF_ROOMS_MUTE_FA = L"دریافت صدا";
const wstring Lang::Impl::CONF_ROOMS_DUMB_EN = L"Dumb";
const wstring Lang::Impl::CONF_ROOMS_DUMB_FA = L"ارسال صدا";
const wstring Lang::Impl::CONF_ROOMS_VOL_IN_EN = L"In Volume";
const wstring Lang::Impl::CONF_ROOMS_VOL_IN_FA = L"صدای ورودی";
const wstring Lang::Impl::CONF_ROOMS_VOL_OUT_EN = L"Out Volume";
const wstring Lang::Impl::CONF_ROOMS_VOL_OUT_FA = L"صدای خروجی";
const wstring Lang::Impl::CONF_ROOMS_CHAIRMAN_EN = L"Chairman";
const wstring Lang::Impl::CONF_ROOMS_CHAIRMAN_FA = L"مدیر کنفرانس";
const wstring Lang::Impl::CONF_ROOMS_SPEAKER_EN = L"Speaker";
const wstring Lang::Impl::CONF_ROOMS_SPEAKER_FA = L"سخنران";
const wstring Lang::Impl::CONF_ROOMS_CONTINUOUS_PRESENCE_EN = L"Continuous Presence";
const wstring Lang::Impl::CONF_ROOMS_CONTINUOUS_PRESENCE_FA = L"مدیریت لایه بندی";

const wstring Lang::Impl::CONF_ROOMS_CP_PICS_1_EN = L"1 Pics";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_1_FA = L"۱ تصویر";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_2_LEFT_RIGHT_EN = L"2 Pics - Left/Right";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_2_LEFT_RIGHT_FA = L"۲ تصویر - چپ/راست";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_2_TOP_BOTTOM_EN = L"2 Pics - Top/Bottom";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_2_TOP_BOTTOM_FA = L"۲ تصویر - بالا/پائین";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_3_HORIZONTAL_EN = L"3 Pics - Horizontal";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_3_HORIZONTAL_FA = L"۳ تصویر - افقی";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_3_VERTICAL_EN = L"3 Pics - Vertical";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_3_VERTICAL_FA = L"۳ تصویر - عمودی";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_4_EN = L"4 Pics";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_4_FA = L"۴ تصویر";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_4_ACTIVE_VOICE_EN = L"4 Pics - Active Voice";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_4_ACTIVE_VOICE_FA = L"۴ تصویر - صدای فعال";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_5_EN = L"5 Pics";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_5_FA = L"۵ تصویر";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_6_HORIZONTAL_EN = L"6 Pics - Horizontal";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_6_HORIZONTAL_FA = L"۶ تصویر - افقی";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_6_VERTICAL_EN = L"6 Pics - Vertical";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_6_VERTICAL_FA = L"۶ تصویر - عمودی";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_7_EN = L"7 Pics";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_7_FA = L"۷ تصویر";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_8_EN = L"8 Pics";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_8_FA = L"۸ تصویر";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_9_EN = L"9 Pics";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_9_FA = L"۹ تصویر";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_9_ACTIVE_VOICE_EN = L"9 Pics - Active Voice";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_9_ACTIVE_VOICE_FA = L"۹ تصویر - صدای فعال";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_10_EN = L"10 Pics";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_10_FA = L"۱۰ تصویر";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_11_EN = L"11 Pics";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_11_FA = L"۱۱ تصویر";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_12_EN = L"12 Pics";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_12_FA = L"۱۲ تصویر";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_12_VERTICAL_EN = L"12 Pics - Vertical";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_12_VERTICAL_FA = L"۱۲ تصویر - صدای فعال";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_13_EN = L"13 Pics";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_13_FA = L"۱۳ تصویر";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_14_EN = L"14 Pics";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_14_FA = L"۱۴ تصویر";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_15_EN = L"15 Pics";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_15_FA = L"۱۵ تصویر";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_16_EN = L"16 Pics";
const wstring Lang::Impl::CONF_ROOMS_CP_PICS_16_FA = L"۱۶ تصویر";

const wstring Lang::Impl::CONF_ROOMS_CP_CELL_NO_PIC_EN = L"No Pic";
const wstring Lang::Impl::CONF_ROOMS_CP_CELL_NO_PIC_FA = L"تصویر ندارد";

const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_CALL_EN = L"Call";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_CALL_FA = L"برقراری تماس";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_HANGUP_EN = L"Hangup";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_HANGUP_FA = L"قطع تماس";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_SET_AS_MNGR_EN = L"Set As Manager";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_SET_AS_MNGR_FA = L"انتخاب به عنوان مدیر";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_SET_AS_SPK_EN = L"Set As Speaker";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_SET_AS_SPK_FA = L"انتخاب به عنوان سخنران";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_VIEW_EN = L"View";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_VIEW_FA = L"نمایش تصویر";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_RM_FROM_CONF_EN = L"Remove From Conference";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_RM_FROM_CONF_FA = L"حذف از کنفرانس";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_MUTE_SPK_EN = L"Mute Speaker";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_MUTE_SPK_FA = L"صدا دریافت کند";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_MUTE_MIC_EN = L"Mute Microphone";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_MUTE_MIC_FA = L"صدا ارسال کند";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_RECV_VID_EN = L"Recieve Video";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_RECV_VID_FA = L"تصویر دریافت کند";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_SEND_VID_EN = L"Send Video";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_SEND_VID_FA = L"تصویر ارسال کند";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_ADD_TO_ADDR_BOOK_EN = L"Add to Address-Book";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_CTX_ADD_TO_ADDR_BOOK_FA = L"به دفترچه تلفن اضافه شود";

const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_MSG_ERASE_TITLE_EN = L"Remove From Conference";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_MSG_ERASE_TITLE_FA = L"حذف از کنفرانس";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_MSG_ERASE_MSG_EN = L"Do you want to remove <strong>"
                        + REPLACE_KEY_TERMINAL_ID + L"</strong> terminal from conference? Are you sure?";
const wstring Lang::Impl::CONF_ROOMS_PRTCPNT_MSG_ERASE_MSG_FA = L"آیا مایل به حذف ترمینال <strong>"
                        + REPLACE_KEY_TERMINAL_ID + L"</strong> از کنفرانس می باشید؟";

const wstring Lang::Impl::CONF_ROOMS_LEGEND_DISCONNECT_EN = L"Disconnected";
const wstring Lang::Impl::CONF_ROOMS_LEGEND_DISCONNECT_FA = L"تماس برقرار نیست";
const wstring Lang::Impl::CONF_ROOMS_LEGEND_INCALL_EN = L"Connected";
const wstring Lang::Impl::CONF_ROOMS_LEGEND_INCALL_FA = L"تماس برقرار است";
const wstring Lang::Impl::CONF_ROOMS_LEGEND_MANAGER_EN = L"Manager";
const wstring Lang::Impl::CONF_ROOMS_LEGEND_MANAGER_FA = L"مدیر";
const wstring Lang::Impl::CONF_ROOMS_LEGEND_SPEAKER_EN = L"Speaker";
const wstring Lang::Impl::CONF_ROOMS_LEGEND_SPEAKER_FA = L"سخنران";

const wstring Lang::Impl::CONF_ROOMS_END_CONF_EN = L"Terminate Conference";
const wstring Lang::Impl::CONF_ROOMS_END_CONF_FA = L"خاتمه کنفرانس";
const wstring Lang::Impl::CONF_ROOMS_ADD_PARTICIPANT_EN = L"Add Terminal";
const wstring Lang::Impl::CONF_ROOMS_ADD_PARTICIPANT_FA = L"افزودن ترمینال";

const wstring Lang::Impl::CONF_ROOMS_DLG_ADD_PARTICIPANT_TITLE_EN = L"Add Terminal";
const wstring Lang::Impl::CONF_ROOMS_DLG_ADD_PARTICIPANT_TITLE_FA = L"افزودن ترمینال";


/**********************************
*    = Constructos =
**********************************/

Lang::Lang(const CgiEnv::ELang &lang) : m_pimpl(new Impl(lang))
{
}


/**********************************
*    = Destructor =
**********************************/

/**********************************
*    = Public Methods =
**********************************/

wstring Lang::GetString(const char *stringId)
{
    return m_pimpl->LangStringsHash[stringId];
}


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

/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


