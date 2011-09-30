#include <string>
#include <csignal>
#include <cstdlib>
#include <boost/format.hpp>
#include <Wt/WServer>
#include <GraphicsMagick/Magick++.h>
#include "base.hpp"
#include "cgiroot.hpp"
#include "error.hpp"
#include "exception.hpp"

void Terminate(int signo);

int main(int argc, char **argv)
{
    try {
        /*! Gracefully handling SIGTERM */
        void (*prev_fn)(int);
        prev_fn = signal(SIGTERM, Terminate);
        if (prev_fn == SIG_IGN)
            signal(SIGTERM, SIG_IGN);

        /*! Changing CurDir to executable path */
        if (argc > 0) {
            if (argv[0] != NULL) {
                std::string path(argv[0]);
                path = path.substr(0, path.rfind("/") + 1);
                if (chdir(path.c_str()) == -1) {
                    throw ControlConference::Exception(
                            (boost::format("Cannot change current working directory to %1%")
                             % path).str());
                }
            } else {
                throw ControlConference::Exception("The program name is not obvious (argv[0] is NULL)");
            }
        } else {
            throw ControlConference::Exception("The program name is not obvious (argc is ZERO)");
        }

        /*! Initializing Magick++ */
        Magick::InitializeMagick(*argv);
        
        /*! Starting web server, otherwise going down */
        Wt::WServer server(argv[0]);
        server.setServerConfiguration(argc, argv, WTHTTP_CONFIGURATION);
        server.addEntryPoint(Wt::Application, ControlConference::CgiRoot::CreateApplication, "", "favicon.ico");
        if (server.start()) {
            Wt::WServer::waitForShutdown();
            server.stop();
        }
    }
    
    catch (ControlConference::Exception &ex) {
        ControlConference::Error::Log(ex.what());
    }

    catch (Wt::WServer::Exception &ex) {
        ControlConference::Error::Log(ex.what());
    }

    catch (boost::exception &ex) {
        ControlConference::Error::Log(boost::diagnostic_information(ex));
    }
    
    catch (std::exception &ex) {
        ControlConference::Error::Log(ex.what());
    }

    catch (...) {
        ControlConference::Error::Log(ControlConference::Base::ERR_UNKNOWN);
    }

    return 0;
}

void Terminate(int signo)
{
    ControlConference::Error::Log(
            (boost::format("Terminating by signal %1%...") % signo).str());
    exit(1);
}


