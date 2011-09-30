#ifndef TMSYSMONSMGENERALINFO_HPP
#define TMSYSMONSMGENERALINFO_HPP


#include <list>
#include <map>
#include "basewidget.hpp"

namespace ControlConference {
    class TMSysMonSMGeneralInfo;
}

class ControlConference::TMSysMonSMGeneralInfo : public ControlConference::BaseWidget
{
private:
    #define CPU_SEC_MAX 60
    #define MEM_SEC_MAX 60

    enum ECPUTypes {
        ECPUTypes_User,
        ECPUTypes_Kernel,
        ECPUTypes_IOWait,
        ECPUTypes_Swap,
        ECPUTypes_Nice,
        ECPUTypes_Idle
    };

    enum EMemTypes {
        EMemTypes_Total,
        EMemTypes_Used,
        EMemTypes_Cache,
        EMemTypes_Free,
        EMemTypes_SwapTotal,
        EMemTypes_SwapUsed,
        EMemTypes_SwapFree,
        EMemTypes_TotalVMUsage
    };
    
private:
    Wt::WText *m_txtMachineNodeName;
    Wt::WText *m_txtMachineUptime;

    std::list< std::map < ECPUTypes, float > > m_cacheCpuUsage;
    Wt::WStandardItemModel *m_modelCpuUsage;

    std::list< std::map < EMemTypes, float > > m_cacheMemUsage;
    Wt::WStandardItemModel *m_modelMemUsage;

    Wt::WContainerWidget *m_dvSysMonDiskInfo;
    Wt::WContainerWidget *m_dvSysMonNetInfo;

public:
    TMSysMonSMGeneralInfo(CgiRoot *cgi);
    ~TMSysMonSMGeneralInfo();

private:
    void RefreshSysResourceUsage();

protected:
    Wt::WWidget *Layout();

private:
    void Init();
};


#endif /* TMSYSMONSMGENERALINFO_HPP */


