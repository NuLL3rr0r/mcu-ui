#include <fstream>
#include <iostream>
#include <map>
#include <csignal>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int fdLock;
int GetLock();
void Terminate(int signo);

string Exec(const char *cmd);

map<string, string> apps;
void ReadApps();
void ReSpawn();

int main(int argc, char **argv, char **envp) {
    std::string path(argv[0]);
    path = path.substr(0, path.rfind("/") + 1);
    if (chdir(path.c_str()) == -1)
		return -2;

	if(!GetLock()) {
		cerr << "Process already running!" << endl;
		return -1;
	}

    void (*prev_fn)(int);
    prev_fn = signal(SIGTERM, Terminate);
    if (prev_fn == SIG_IGN)
        signal(SIGTERM, SIG_IGN);

	ReadApps();

	while (true) {
		ReSpawn();
		sleep(1);
	}

	return 0;
}

int GetLock() {
	struct flock fl;

	fl.l_type = F_WRLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len = 1;

	if((fdLock = open("spawn.lock", O_WRONLY|O_CREAT, 0666)) == -1)
		return 0;

	if(fcntl(fdLock, F_SETLK, &fl) == -1)
		return 0;

	return 1;
}

void Terminate(int signo) {
    clog << "Terminating...." << endl;
    exit(1);
}

string Exec(const char *cmd) {
	FILE *pipe = popen(cmd, "r");

	if (!pipe)
		return "3rr0r";

	string result;
	char buffer[128];

	while (!feof(pipe))
		if (fgets(buffer, 128, pipe) != NULL)
			result += buffer;

	pclose(pipe);

	return result;
}

void ReadApps() {
	ifstream file("spawn.db");

	int i = 0;
	if (file.is_open()) {
		while (file.good()) {
			string line;
			getline(file, line);
			++i;

			if (line.length() != 0) {
				size_t pos = line.find(":");
			
				if (pos != string::npos &&
						pos != 0 && pos != line.length() - 1) {
					string bin = line.substr(0, pos);
					string port = line.substr(pos + 1);

					apps[port] = bin;
				}
				else
					cerr << i << ": " << "Bad format!" << endl;
			}
		}

		file.close();
	}
	else
		cerr << "Unable to open file!" << endl;
}

void ReSpawn() {
	for (std::map<std::string, std::string>::const_iterator it = apps.begin();
			it != apps.end(); ++it) {
		if (Exec(("/usr/bin/netstat -an | /usr/bin/grep " + it->first).c_str()).find("LISTEN") == string::npos) {
			clog << endl << "  * RESPAWNING ==>  " + it->first + " : " + it->second << endl << endl;
			system(("cd " + it->second.substr(0, it->second.rfind("/") + 1) +
					" && "
					"/usr/local/bin/spawn-fcgi -n -f " + it->second + " -a 0.0.0.0 -p " + it->first + " -u www -g www &").c_str());
		}
	}
}


