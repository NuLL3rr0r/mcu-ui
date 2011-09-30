#ifndef LOGIN_HPP
#define LOGIN_HPP


#include "basewidget.hpp"

namespace ControlConference {
    class Login;
}

class ControlConference::Login : public ControlConference::BaseWidget
{
private:
    Wt::WLineEdit *m_loginUserEdit;
    Wt::WLineEdit *m_loginPwdEdit;
    Wt::WLineEdit *m_loginCaptchaEdit;
    Wt::WImage *m_loginCaptchaImage;
    Wt::WText *m_errLoginText;
    Wt::WIntValidator *m_loginCaptchaValidator;

    bool m_forgotFormFlag;
    Div *m_dvForgot;
    Wt::WLineEdit *m_forgotEmailEdit;
    Wt::WLineEdit *m_forgotCaptchaEdit;
    Wt::WText *m_errForgotText;
    Wt::WIntValidator *m_forgotCaptchaValidator;

public:
    Login(CgiRoot *cgi);
    ~Login();

private:
    void ForgotForm();
    void ForgotOK();
    void LoginOK();

private:
    void GenCap();

private:
    Wt::WWidget *Layout();
};


#endif /* LOGIN_HPP */
