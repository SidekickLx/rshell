#include "parsing.h"
using namespace std;


Parsing::Parsing(string line){
	this->line = line;
}

void Parsing::readCommands(){
	vector<string>temp;
	stringstream ss(line);
	string str;
	char* c = new char[32];
	int l=0,m=0,n = 0;
	while(ss>>str){
		temp.push_back(str);
	}
	for(unsigned int j = 0; j<temp.size(); j++){
		strcpy(c,temp[j].c_str());
		if (j == 0) {
			command[l] = (char*)malloc(sizeof(c));
			parameter[l][n] = (char*)malloc(sizeof(c));
			strcpy(command[l], c);
			strcpy(parameter[l][n], c);
			n++;	
			l++; 
			continue;

		}
		if ((!strcmp(c, ";")) || (!strcmp(c, "&&")) ||(!strcmp(c, "||"))) {
			connector[m] = (char*)malloc(sizeof(c));
			strcpy(connector[m], c);	
			m++;	
			n = 0;
			continue;
	
		}
		if ((temp[j-1] == ";") || (temp[j-1] == "&&") || (temp[j-1] == "||")){
			command[l] = (char*)malloc(sizeof(c));
			parameter[l][n] = (char*)malloc(sizeof(c));
			strcpy(command[l], c);
			strcpy(parameter[l][n], c);
			n++;	
			l++; 
			continue;
		}

		parameter[l-1][n] = (char*)malloc(sizeof(c));
		strcpy(parameter[l-1][n],c);
		n++;	

	}
}

int Parsing::getCommandArray(int i, char* str){
	if(!command[i])	return 0;
	else{
		strcpy(str,command[i]);
		return 1;
	}
}
int Parsing::getParameter(int i, int j, char* argv){
	if(!parameter[i][j]) {
		return 0;
	}else{
		strcpy(argv,parameter[i][j]);
		return 1;
	}
}

char** Parsing::getParameters(int i){
	for(int j=0 ; !(parameter[i][j]); j++)
		strcpy(para_of_one_cmd[j],parameter[i][j]);
	return para_of_one_cmd;
}


int Parsing::getConnectorArray(int i, char* con){
	if(!this->connector[i]){
		return 0;
	}else{
		strcpy(con,connector[i]);
		return 1;
	}
}
