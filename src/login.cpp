/**********************************
*    = Header File Inclusion =
**********************************/
#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WGridLayout>
#include <Wt/WImage>
#include <Wt/WIntValidator>
#include <Wt/WLengthValidator>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WRegExpValidator>
#include <Wt/WText>
#include <Wt/WSignalMapper>
#include <Wt/WWidget>
#include "login.hpp"
#include "base.hpp"
#include "home.hpp"
#include "ipc/logincommand.h"


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

Login::Login(CgiRoot *cgi) : BaseWidget(cgi)
{
    this->clear();
    this->addWidget(Layout());
}


/**********************************
*    = Destructor =
**********************************/

Login::~Login()
{
}


/**********************************
*    = Public Methods =
**********************************/

/**********************************
*    = Event Handlers =
**********************************/

void Login::ForgotForm()
{
    if (!m_forgotFormFlag) {
        Div *dvForgotForm = new Div(m_dvForgot, "dvForgotForm", "form");
        WGridLayout *dvForgotFormLayout = new WGridLayout();

        m_forgotEmailEdit = new WLineEdit();
        m_forgotCaptchaEdit = new WLineEdit();

        dvForgotFormLayout->addWidget(new WText(m_lang->GetString("LOGIN_FORM_EMAIL_TEXT")),
                                      0, 0);
        dvForgotFormLayout->addWidget(m_forgotEmailEdit, 0, 1);

        dvForgotFormLayout->addWidget(new WText(m_lang->GetString("LOGIN_FORM_CAPTCHA_TEXT")),
                                      1, 0);
        dvForgotFormLayout->addWidget(m_forgotCaptchaEdit, 1, 1);

        dvForgotFormLayout->setVerticalSpacing(11);
        dvForgotFormLayout->setColumnStretch(0, 100);
        dvForgotFormLayout->setColumnStretch(1, 200);
        dvForgotForm->resize(300, WLength::Auto);
        dvForgotForm->setLayout(dvForgotFormLayout);

        m_errForgotText = new WText(m_dvForgot);
        WPushButton *btnForgot = new WPushButton(m_lang->GetString("LOGIN_FORM_RECOVER_TEXT"),
                                                 m_dvForgot);
        btnForgot->setStyleClass("formButton");

        WRegExpValidator *forgotEmailValidator = new WRegExpValidator(Base::REGEX_EMAIL);
        forgotEmailValidator->setMandatory(true);

        m_forgotCaptchaValidator = new WIntValidator(m_captcha->Result, m_captcha->Result);
        m_forgotCaptchaValidator->setMandatory(true);

        m_forgotEmailEdit->setValidator(forgotEmailValidator);
        m_forgotCaptchaEdit->setValidator(m_forgotCaptchaValidator);

        m_forgotEmailEdit->enterPressed().connect(this, &Login::ForgotOK);
        m_forgotCaptchaEdit->enterPressed().connect(this, &Login::ForgotOK);
        btnForgot->clicked().connect(this, &Login::ForgotOK);

        m_forgotFormFlag = true;
    } else {
        m_dvForgot->clear();
        m_forgotFormFlag = false;
    }
}

void Login::ForgotOK()
{
    if (Validate(m_forgotCaptchaEdit)) {
        if(!Validate(m_forgotEmailEdit)) {
            GenCap();
            return;
        }
    } else {
        GenCap();
        return;
    }

    /*CmdRecoverPassword recoverPassword(m_forgotEmailEdit->text().toUTF8());

    if (!recoverPassword.IsValidEmail()) {
        HtmlError(m_lang->GetString("LOGIN_FORM_ERR_FORGOT"), m_errForgotText);
        m_forgotEmailEdit->setFocus();
        GenCap();
        return;
    }*/

    HtmlInfo(m_lang->GetString("LOGIN_FORM_MSG_FORGOT"), m_errForgotText);
    GenCap();
    m_loginUserEdit->setFocus();
}

void Login::LoginOK()
{
    if (Validate(m_loginCaptchaEdit)) {
        if(!Validate(m_loginUserEdit) || !Validate(m_loginPwdEdit)) {
            GenCap();
            return;
        }
    } else {
        GenCap();
        return;
    }
    
    LoginCommand cmd(Base::MCU_MANAGER_URL,
                     m_loginUserEdit->text().toUTF8(),
                     m_loginPwdEdit->text().toUTF8());
    if (!cmd.Send())
        return;

    if (!cmd.IsValid()) {
        HtmlError(m_lang->GetString("LOGIN_FORM_ERR_LOGIN"), m_errLoginText);
        m_loginUserEdit->setFocus();
        GenCap();
        return;
    }

    new Home(m_cgiRoot);
}


/**********************************
*    = Protected Methods =
**********************************/

/**********************************
*    = Private Methods =
**********************************/

void Login::GenCap()
{
    m_loginCaptchaImage->setImageRef(m_captcha->GenCap()->imageRef());
    m_loginCaptchaValidator->setRange(m_captcha->Result, m_captcha->Result);

    if (m_forgotFormFlag) {
        m_forgotCaptchaValidator->setRange(m_captcha->Result, m_captcha->Result);
    }
}


/**********************************
*    = Base Class Overrides =
**********************************/

WWidget *Login::Layout()
{
    Div *root = new Div("Login");

    Div *dvNoScript = new Div(root, "dvNoScript");
    new WText(m_lang->GetString("WARN_NO_SCRIPT"), dvNoScript);

    Div *dvLogin = new Div(root, "dvLogin");
    new WText(m_lang->GetString("LOGIN_FORM_TITLE"), dvLogin);

    Div *dvLangBar = new Div(dvLogin, "dvLangBar");
    new WText(L"<a href=\"?lang=en\"><img src=\"lang_en.png\" alt=\"English\" title=\"English\" /></a>"
              "<a href=\"?lang=fa\"><img src=\"lang_fa.png\" alt=\"فارسی\" title=\"فارسی\" /></a>", dvLangBar);

    Div *dvLoginForm = new Div(dvLogin, "dvLoginForm", "form");
    WGridLayout *dvLoginFormLayout = new WGridLayout();

    m_loginUserEdit = new WLineEdit();
    m_loginPwdEdit = new WLineEdit();
    m_loginPwdEdit->setEchoMode(WLineEdit::Password);
    m_loginCaptchaEdit = new WLineEdit();

    dvLoginFormLayout->addWidget(new WText(m_lang->GetString("LOGIN_FORM_USER_TEXT")),
                                 0, 0);
    dvLoginFormLayout->addWidget(m_loginUserEdit, 0, 1);

    dvLoginFormLayout->addWidget(new WText(m_lang->GetString("LOGIN_FORM_PWD_TEXT")),
                                 1, 0);
    dvLoginFormLayout->addWidget(m_loginPwdEdit, 1, 1);

    dvLoginFormLayout->addWidget(new WText(m_lang->GetString("LOGIN_FORM_CAPTCHA_TEXT")),
                                 2, 0);
    dvLoginFormLayout->addWidget(m_loginCaptchaEdit, 2, 1);

    dvLoginFormLayout->setVerticalSpacing(11);
    dvLoginFormLayout->setColumnStretch(0, 100);
    dvLoginFormLayout->setColumnStretch(1, 200);
    dvLoginForm->resize(300, WLength::Auto);
    dvLoginForm->setLayout(dvLoginFormLayout);

    m_loginCaptchaImage = m_captcha->GenCap();
    dvLogin->addWidget(m_loginCaptchaImage);

    m_errLoginText = new WText(dvLogin);
    WPushButton *loginBtn = new WPushButton(m_lang->GetString("LOGIN_FORM_LOGIN_TEXT"),
                                            dvLogin);
    loginBtn->setStyleClass("formButton");

    WText *forgotLink = new WText(
            L"<p style=\"text-align: right !important; margin-top: 25px;\">"
            + m_lang->GetString("LOGIN_FORM_FORGOT_TEXT") + L"</p>",
            dvLogin);
    forgotLink->setStyleClass("link");

    m_dvForgot = new Div(dvLogin, "dvForgot");
    m_forgotFormFlag = false;

    Div *dvCopyright = new Div(root, "dvCopyright");
    new WText(Base::Copyright(), dvCopyright);

    WSignalMapper<WText *> *forgotMap = new WSignalMapper<WText *>(this);
    forgotMap->mapped().connect(this, &Login::ForgotForm);
    forgotMap->mapConnect(forgotLink->clicked(), forgotLink);

    WLengthValidator *loginUserValidator = new WLengthValidator(Base::MIN_USERNAME_LENGTH,
                                                                Base::MAX_USERNAME_LENGTH);
    loginUserValidator->setMandatory(true);
    m_loginUserEdit->setValidator(loginUserValidator);

    WLengthValidator *loginPwValidator = new WLengthValidator(Base::MIN_PASSWORD_LENGTH,
                                                              Base::MAX_PASSWORD_LENGTH);
    loginPwValidator->setMandatory(true);
    m_loginPwdEdit->setValidator(loginPwValidator);

    m_loginCaptchaValidator = new WIntValidator(m_captcha->Result, m_captcha->Result);
    m_loginCaptchaValidator->setMandatory(true);
    m_loginCaptchaEdit->setValidator(m_loginCaptchaValidator);

    m_loginUserEdit->enterPressed().connect(this, &Login::LoginOK);
    m_loginPwdEdit->enterPressed().connect(this, &Login::LoginOK);
    m_loginCaptchaEdit->enterPressed().connect(this, &Login::LoginOK);
    loginBtn->clicked().connect(this, &Login::LoginOK);


    return root;
}


/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/

