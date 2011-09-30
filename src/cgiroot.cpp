/**********************************
*    = Header File Inclusion =
**********************************/

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WEnvironment>
#include <Wt/WText>
#include <Wt/WWidget>
#include "cgiroot.hpp"
#include "base.hpp"
#include "captcha.hpp"
#include "cgienv.hpp"
#include "error.hpp"
#include "exception.hpp"
#include "home.hpp"
#include "lang.hpp"
#include "login.hpp"
#include "system.hpp"


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

const size_t CgiRoot::LANG_COOKIE_LIFETIME = 31536000;


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

CgiRoot::CgiRoot(const WEnvironment &env) : WApplication(env)
{
    try {
        CgiEnvInstance = CgiEnv_ptr(new CgiEnv(env));

        srand(System::RandSeed());

        root()->clear();
        HtmlRoot = root();

        CaptchaInstance = Captcha_ptr(new Captcha());
        LangInstance = Lang_ptr(new Lang(CgiEnvInstance->CurrentLang));

        switch(CgiEnvInstance->CurrentLang) {
        case CgiEnv::ELang_None:
            try {
                Exit("?lang=" + (env.getCookie("lang")));
            }
            catch (...) {
                Exit("?lang=fa");
            }
            break;

        case CgiEnv::ELang_Invalid:
            Exit("?lang=fa");
            break;

        case CgiEnv::ELang_Fa:
            setLayoutDirection(Wt::RightToLeft);
            // Fall through
        case CgiEnv::ELang_En:
        default:
            if (env.supportsCookies()) {
                setCookie("lang", CgiEnvInstance->HttpGet["lang"], LANG_COOKIE_LIFETIME);
            }
            break;
        }

        root()->addWidget(InitHome());
    }

    catch (Exception &ex) {
        root()->clear();
        root()->addWidget(new WText(ex.what()));
    }

    catch (std::exception &ex) {
        SayError(ex.what());
    }

    catch (...) {
        SayError(Base::ERR_UNKNOWN);
    }
}


/**********************************
*    = Destructor =
**********************************/

CgiRoot::~CgiRoot()
{
}


/**********************************
*    = Public Methods =
**********************************/

WApplication *CgiRoot::CreateApplication(const WEnvironment &env)
{
    return new CgiRoot(env);
}

void CgiRoot::Redirect(const string &url)
{
    redirect(url);
}

void CgiRoot::Exit(const std::string &url)
{
    redirect(url);
    quit();
}

void CgiRoot::Exit()
{
    quit();
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

void CgiRoot::SayError(const string &err) const
{
    Error::Log(err);
    root()->clear();
    root()->addWidget(new WText(Base::ERR_CRITICAL));
}

WWidget *CgiRoot::InitHome()
{
    useStyleSheet("home.css");

    switch(CgiEnvInstance->CurrentLang) {

    case CgiEnv::ELang_En:
        useStyleSheet("home-ltr.css");
        break;

    case CgiEnv::ELang_Fa:
        useStyleSheet("home-rtl.css");
        break;

    default:
        break;
    }

    setTitle(LangInstance->GetString("LOGIN_TITLE"));

    //return new Login(const_cast<CgiRoot *>(this));
    return new Home(const_cast<CgiRoot *>(this));
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


