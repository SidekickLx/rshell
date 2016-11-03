#include "built_in.h"

using namespace std;

Built_in::Built_in(char* command, char** parameters){
	this->command = command;
	this->parameters = parameters;
}


int Built_in::cd(){
	char* cd_path = NULL;
	if(parameters[1] == NULL){
		parameters[1] = (char*)malloc(3 * sizeof(char));
           	parameters[1][0]= '.';
            	parameters[1][1]= '.';
		parameters[1][2]= '\0';
	}
	if(parameters[1][0] == '~'){
		cd_path = (char*)malloc(strlen(pwd->pw_dir)+strlen(parameters[1]));
		if(cd_path==NULL) return -1;
		strcpy(cd_path,pwd->pw_dir);
		strncpy(cd_path+strlen(pwd->pw_dir),parameters[1]+1,strlen(parameters[1]));
	}else{
		cd_path =(char*) malloc(strlen(parameters[1]+1));
            	if(cd_path == NULL) return -1;
		strcpy(cd_path,parameters[1]);

	}
	chdir(cd_path);
	free(cd_path);
	return 0;
}
