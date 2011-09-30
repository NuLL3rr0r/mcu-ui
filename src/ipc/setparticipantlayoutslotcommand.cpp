#include "setparticipantlayoutslotcommand.hpp"
#include "command.h"
#include "boost/lexical_cast.hpp"

using namespace Commands;

SetParticipantLayoutSlotCommand::SetParticipantLayoutSlotCommand(std::string responderIP,
                                                                 std::string participantAddress,
                                                                 std::string conferenceName,
                                                                 int slotNumber)
    :BaseCommand("SetParticipantLayoutSlot",responderIP)
{
    m_participantAddress = participantAddress;
    m_conferenceName = conferenceName;
    m_slotNumber = slotNumber;

    m_command->AddArgument("ParticipantAddress", m_participantAddress);
    m_command->AddArgument("conferenceName", m_conferenceName);
    m_command->AddArgument("SlotNumber", boost::lexical_cast<std::string>(m_slotNumber));
}

bool SetParticipantLayoutSlotCommand::Send()
{
    bool result;

    if (TwoWaySendCommand())
        result = true;
    else
        result = false;

    return result;
}


