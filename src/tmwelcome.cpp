/**********************************
*    = Header File Inclusion =
**********************************/

#include <Wt/WApplication>
#include <Wt/WCheckBox>
#include <Wt/WComboBox>
#include <Wt/WContainerWidget>
#include <Wt/WDialog>
#include <Wt/WGridLayout>
#include <Wt/WGroupBox>
#include <Wt/WImage>
#include <Wt/WLineEdit>
#include <Wt/WMenuItem>
#include <Wt/WPopupMenu>
#include <Wt/WPushButton>
#include <Wt/WSignalMapper>
#include <Wt/WSpinBox>
#include <Wt/WStackedWidget>
#include <Wt/WText>
#include <Wt/WTextArea>
#include <Wt/WWidget>
#include "tmwelcome.hpp"


/**********************************
*    = PreProcessor Directives =
**********************************/

/**********************************
*    = Importing NameSpaces =
**********************************/

using namespace std;
using namespace Wt;
using namespace ControlConference;


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

class TMWelcome::Impl
{
public:
};


/**********************************
*    = Constructos =
**********************************/

TMWelcome::TMWelcome(CgiRoot *cgi) : BaseWidget(cgi), m_pimpl(new Impl())
{
    this->clear();
    this->addWidget(Layout());
}


/**********************************
*    = Destructor =
**********************************/

TMWelcome::~TMWelcome()
{
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

WWidget *TMWelcome::Layout()
{
    Div *root = new Div("TMWelcome");

    Div *dvContents = new Div(root, "dvContents");
    WStackedWidget *dvContentsInner = new WStackedWidget(dvContents);
    dvContentsInner->setId("dvContentsInner");

    Div *dvWelcomeMessage = new Div(dvContentsInner, "dvWelcomeMessage");
    new WBreak(dvWelcomeMessage);
    new WBreak(dvWelcomeMessage);
    new WText(L"<center><h3>" + m_lang->GetString("WELCOME_GREETING")
              + L"</h3></center>", dvWelcomeMessage);

    new WBreak(dvWelcomeMessage);
    new WText(L"<center><h4>" + m_lang->GetString("WELCOME_CONFERENCE_LIST")
              + L"</h4></center>", dvWelcomeMessage);
    new WText(m_lang->GetString("TEMPO_UNDER_CONSTRUCTION"), dvWelcomeMessage);

    return root;
}


/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


