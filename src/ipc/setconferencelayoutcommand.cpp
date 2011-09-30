#include "setconferencelayoutcommand.hpp"
#include "command.h"
#include "boost/lexical_cast.hpp"

using namespace Commands;

SetConferenceLayoutCommand::SetConferenceLayoutCommand(std::string responderIP,
                                                       std::string conferenceName,
                                                       int layout)
    :BaseCommand("SetConferenceLayout",responderIP)
{
    m_conferenceName = conferenceName;
    m_layout = layout;

    m_command->AddArgument("conferenceName", m_conferenceName);
    m_command->AddArgument("LayoutID", boost::lexical_cast<std::string>(m_layout));
}

bool SetConferenceLayoutCommand::Send()
{
    bool result;

    if (TwoWaySendCommand())
        result = true;
    else
        result = false;

    return result;
}
