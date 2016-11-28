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
		int getConnectorArray(int, char*);
		~Parsing(){free(command);free(parameter);free(connector);};
    private:
	string line;
	char* command[200];
	char* parameter[200][100];
	char* connector[200];
	char* para_of_one_cmd[100];
};
