#ifndef CGIROOT_HPP
#define CGIROOT_HPP


#include <string>
#include <memory>

namespace Wt {
    class WApplication;
    class WEnvironment;
    class WContainerWidget;
    class WWidget;
}

namespace ControlConference {
    class Captcha;
    class CgiEnv;
    class CgiRoot;
    class Lang;
}

typedef std::shared_ptr<ControlConference::Captcha> Captcha_ptr;
typedef std::shared_ptr<ControlConference::CgiEnv> CgiEnv_ptr;
typedef std::shared_ptr<ControlConference::Lang> Lang_ptr;

class ControlConference::CgiRoot : public Wt::WApplication
{
private:
    static const std::size_t LANG_COOKIE_LIFETIME;

public:
    Wt::WContainerWidget *HtmlRoot;

    Captcha_ptr CaptchaInstance;
    CgiEnv_ptr CgiEnvInstance;
    Lang_ptr LangInstance;
    
public:
    CgiRoot(const Wt::WEnvironment &env);
    ~CgiRoot();

public:
    static Wt::WApplication *CreateApplication(const Wt::WEnvironment &env);

    void Redirect(const std::string &url);
    void Exit(const std::string &url);
    void Exit();
    
private:
    void SayError(const std::string &err) const;

    Wt::WWidget *InitHome();
};


#endif /* CGIROOT_HPP */

