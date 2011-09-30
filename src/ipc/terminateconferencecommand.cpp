#include "terminateconferencecommand.hpp"
#include "command.h"

using namespace Commands;

TerminateConferenceCommand::TerminateConferenceCommand(std::string responderIP,
                                                       std::string conferenceName)
    :BaseCommand("TerminateConference",responderIP)
{
    m_conferenceName = conferenceName;

    m_command->AddArgument("conferenceName", m_conferenceName);
}

bool TerminateConferenceCommand::Send()
{
    bool result;

    if (TwoWaySendCommand())
        result = true;
    else
        result = false;

    return result;
}
