#ifndef CGIENV_HPP
#define CGIENV_HPP


#include <string>
#include <unordered_map>

namespace Wt {
    class WEnvironment;
}

namespace ControlConference {
    class CgiEnv;
}

class ControlConference::CgiEnv
{
public:
    struct ClientInfoTag {
        std::string country_code;
        std::string country_code3;
        std::string country_name;
        std::string region;
        std::string city;
        std::string postal_code;
        std::string latitude;
        std::string longitude;
        std::string metro_code;
        std::string dma_code;
        std::string area_code;
        std::string charset;
        std::string continent_code;
        std::string country_conf;
        std::string region_conf;
        std::string city_conf;
        std::string postal_conf;
        std::string accuracy_radius;
    } ClientInfoRecord;

    enum ELang {
        ELang_None,
        ELang_Invalid,
        ELang_En,
        ELang_Fa
    };

    enum EClientInfo {
        EClientInfo_IP,
        EClientInfo_Browser,
        EClientInfo_Referer,
        EClientInfo_Location
    };

    enum EServerInfo {
        EServerInfo_Host,
        EServerInfo_URL,
        EServerInfo_NoReplyAddr
    };

    std::unordered_map<std::string, std::string> HttpGet;
    ELang CurrentLang;

private:
    std::string m_clientInfoIP;
    std::string m_clientInfoBrowser;
    std::string m_clientInfoReferer;
    std::string m_clientInfoLocation;

    std::string m_serverInfoHost;
    std::string m_serverInfoURL;
    std::string m_serverInfoNoReplyAddr;

public:
    CgiEnv(const Wt::WEnvironment &env);
    
    std::string GetClientInfo(const EClientInfo &key) const;
    std::string GetServerInfo(const EServerInfo &key) const;

private:
	void ExtractClientInfoDetail();
    
    inline static std::string CStrToStr(const char *cstr);
};


#endif /* CGIENV_HPP */

