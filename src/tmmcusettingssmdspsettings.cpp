/**********************************
*    = Header File Inclusion =
**********************************/

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WText>
#include <Wt/WWidget>
#include "tmmcusettingssmdspsettings.hpp"


/**********************************
*    = PreProcessor Directives =
**********************************/

using namespace std;
using namespace Wt;
using namespace ControlConference;


/**********************************
*    = Importing NameSpaces =
**********************************/

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

TMMCUSettingsSMDSPSettings::TMMCUSettingsSMDSPSettings(CgiRoot *cgi) : BaseWidget(cgi)
{
    this->clear();
    this->addWidget(Layout());
}


/**********************************
*    = Destructor =
**********************************/

TMMCUSettingsSMDSPSettings::~TMMCUSettingsSMDSPSettings()
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

WWidget *TMMCUSettingsSMDSPSettings::Layout()
{
    Div *root = new Div("TMMCUSettingsSMDSPSettings");

    new WText(m_lang->GetString("TEMPO_UNDER_CONSTRUCTION"), root);

    return root;
}


/**********************************
*    = Utility Methods =
**********************************/

/**********************************
*    = Debug Methods =
**********************************/


