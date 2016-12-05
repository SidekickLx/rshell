#include "built_in.h"

using namespace std;

Built_in::Built_in(char* command, char** parameters){
	this->command = command;
	this->parameters = parameters;
}


int Built_in::cd(){
	char* cd_path = NULL;
	char* main_path = getenv("HOME");
	if(parameters[1] == NULL){
		cd_path = (char*)malloc(2*strlen(main_path));
		if(cd_path==NULL) return -1;
		strcpy(cd_path,main_path);
	}else if(!strcmp(parameters[1], "-")){
		parameters[1] = (char*)malloc(3 * sizeof(char));
           	parameters[1][0]= '.';
            	parameters[1][1]= '.';
		parameters[1][2]= '\0';
	}else if(parameters[1][0] == '~'){
		cd_path = (char*)malloc(strlen(main_path)+strlen(parameters[1]));
		if(cd_path==NULL) return -1;
		strcpy(cd_path,main_path);
		strncpy(cd_path+strlen(main_path),parameters[1]+1,strlen(parameters[1]));
	}else{
		cd_path =(char*) malloc(strlen(parameters[1]+1));
           if(cd_path == NULL) return -1;
		strcpy(cd_path,parameters[1]);
	}
	chdir(cd_path);
	free(cd_path);
	return 0;
}

int Built_in::test(){
	char* path = NULL;
	char* main_path = getenv("HOME");
	char* option = (char*)malloc(sizeof(parameters[1]));
	strcpy(option,parameters[1]);
	if((!parameters[2])||(!strcmp(parameters[2],"]"))){
		strcpy(option,"-e");
		parameters[2] = (char*)malloc(sizeof(parameters[1]));
		strcpy(parameters[2],parameters[1]);
	}
	if(parameters[2][0] == '~'){
		path = (char*)malloc(strlen(main_path)+strlen(parameters[2]));
		if(path==NULL) return -1;
		strcpy(path,main_path);
		strncpy(path+strlen(main_path),parameters[2]+1,strlen(parameters[2]));
	}else{
		path =(char*) malloc(strlen(parameters[2]+1));
           if(path == NULL) return -1;
		strcpy(path,parameters[2]);

	}
	if(access(path, F_OK) == 0){
		if(!(strcmp(option,"-e"))){
			cout<<"True"<<endl;
		}else if(!(strcmp(option,"-d"))){
			if(opendir(path) == NULL)
				cout<<"False"<<endl;
			else
				cout<<"True"<<endl;
		}else if(!(strcmp(option,"-f"))){
			if(opendir(path) == NULL)
				cout<<"True"<<endl;
			else
				cout<<"False"<<endl;
		}		
	}else{
		cout<<"False"<<endl;
	}
	return 0;
}
