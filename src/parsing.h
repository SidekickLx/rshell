#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Parsing{
    public:
        Parsing(string );
	void readCommands();
	int getCommandArray(int, char*);
	int getParameter(int, int, char* );
	char** getParameters(int );
	string getConnectorArray(int);
	~Parsing(){free(command);free(parameter);free(connector);};
    private:
	string line;
	string command[200];
	string parameter[200][100];
	string connector[200];
	char* para_of_one_cmd[100];
};
