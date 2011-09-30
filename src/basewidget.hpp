#ifndef BASEWIDGET_HPP
#define BASEWIDGET_HPP


#include <string>
#include <memory>

#include "base.hpp"
#include "captcha.hpp"
#include "cgienv.hpp"
#include "cgiroot.hpp"
#include "div.hpp"
#include "error.hpp"
#include "lang.hpp"

namespace Wt {
    namespace Chart {
        class WCartesianChart;
    }
    class WAnchor;
    class WApplication;
    class WBreak;
    class WButtonGroup;
    class WCheckBox;
	class WComboBox;
    class WContainerWidget;
    class WDatePicker;
    class WDateValidator;
    class WDialog;
    class WEnvironment;    
    class WFileUpload;
    class WFormWidget;
    class WGridLayout;
    class WGroupBox;
    class WHBoxLayout;
    class WImage;
	class WInPlaceEdit;
    class WIntValidator;
    class WLengthValidator;
    class WLineEdit;
    class WMenuItem;
    class WMessageBox;
    class WPopupMenu;
    class WPushButton;
    class WRadioButton;
    class WRegExpValidator;
    class WScrollArea;
    class WSpinBox;
    class WStackedWidget;
    class WStandardItem;
    class WStandardItemModel;
    class WString;
    class WTable;
    class WTableView;
    class WText;
    class WTextArea;
    class WTextEdit;
    class WVBoxLayout;
    class WWidget;
}

namespace ControlConference {
    class BaseWidget;
}

class ControlConference::BaseWidget : public Wt::WContainerWidget 
{
protected:
    CgiRoot *m_cgiRoot;
    Wt::WContainerWidget *m_htmlRoot;

    Captcha_ptr m_captcha;
    CgiEnv_ptr m_cgiEnv;
    Lang_ptr m_lang;

public:
    BaseWidget(CgiRoot *cgi);
    virtual ~BaseWidget() = 0;

protected:
    void Redirect(const std::string &url);
    void Exit(const std::string &url);
    void Exit();

    bool Validate(Wt::WFormWidget *widget);
    void HtmlError(const std::string &err, Wt::WText *txt);
    void HtmlError(const std::wstring &err, Wt::WText *txt);
    void HtmlInfo(const std::string &msg, Wt::WText *txt);
    void HtmlInfo(const std::wstring &msg, Wt::WText *txt);
    
    virtual WWidget *Layout() = 0;
};


#endif /* BASEWIDGET_HPP */

