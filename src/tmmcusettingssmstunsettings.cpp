/**********************************
*    = Header File Inclusion =
**********************************/

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WText>
#include <Wt/WWidget>
#include "tmmcusettingssmstunsettings.hpp"


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
*    = Constructos =
**********************************/

TMMCUSettingsSMSTUNSettings::TMMCUSettingsSMSTUNSettings(CgiRoot *cgi) : BaseWidget(cgi)
{
    this->clear();
    this->addWidget(Layout());
}


/**********************************
*    = Destructor =
**********************************/

TMMCUSettingsSMSTUNSettings::~TMMCUSettingsSMSTUNSettings()
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

WWidget *TMMCUSettingsSMSTUNSettings::Layout()
{
    Div *root = new Div("TMMCUSettingsSMSTUNSettings");

    new WText(m_lang->GetString("TEMPO_UNDER_CONSTRUCTION"), root);

    return root;
}


/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


