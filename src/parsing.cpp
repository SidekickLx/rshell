#include "parsing.h"
using namespace std;


Parsing::Parsing(string line){
	this->line = line;
}

void Parsing::readCommands(){
	vector<string>temp;
	stringstream ss(line);
	string str;
	int l,m,n = 0;
	while(ss>>str){
		temp.push_back(str);
	}
	for(unsigned int j = 0; j<temp.size(); j++){
		if (j == 0) {
			this->command[l] = temp[j];
			parameter[l][n] = temp[j];
			n++;	
			l++; 
			continue;

		}
		if ((temp[j] == ";") || (temp[j] == "&&") || (temp[j] == "||")) {
			connector[m] = temp[j];	
			m++;	
			n = 0;
			continue;
	
		}
		if ((temp[j-1] == ";") || (temp[j-1] == "&&") || (temp[j-1] == "||")) {
			command[l] = temp[j];
			parameter[l][n]=temp[j];
			n++;	
			l++; 
			continue;
		}
			parameter[l-1][n]=temp[j];
			n++;	
	}

}

int Parsing::getCommandArray(int i, char* str){
	int length, str_len = 0;
	if(command[i].empty())	return 0;
	else{
		length = this->command[i].length();
		str_len = this->command[i].copy(str, length, 0);
		str[str_len] = '\0';
		return 1;
	}
}
int Parsing::getParameter(int i, int j, char* argv){
	if(parameter[i][j].empty()) {
		return 0;
	}else{
		int len = parameter[i][j].length();
		int argv_size = (parameter[i][j]).copy(argv,len,0);
		argv[argv_size] = '\0';
		return 1;
	}
}

char** Parsing::getParameters(int i){
	for(int j=0 ; !(parameter[i][j].empty()); j++)
		parameter[i][j].copy(this->para_of_one_cmd[j],parameter[i][j].length(),0);
	return para_of_one_cmd;
}


string Parsing::getConnectorArray(int i){
	return this->connector[i];
}
