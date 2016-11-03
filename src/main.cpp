#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "parsing.h"

#define TRUE 1

using namespace std;

int main(int argc, char* argv[]){
	int status = 0;
	char cmd[32];
	char* parameter[1024];
	char connector[10];
	char buffer[32];
	while(TRUE) {
		int rslt = 0;
		string line;
		getline(cin,line);
		Parsing* p = new Parsing(line);  
		p->readCommands();
		p->getCommandArray(0, cmd);
		if(!(strcmp(cmd, "exit"))) exit(0);
		for(int i = 0; p->getCommandArray(i, cmd); i++){
			for(int j = 0; p->getParameter(i,j,buffer); j++)
				parameter[j] = buffer;
			if(fork()!=0){
				waitpid(-1,&status,0);
			} else {	
				rslt = execvp(cmd, parameter);
				perror("execvp failed"); 
				exit(0);
			}
			if(p->getConnectorArray(i,connector)){
				if(!strcmp(connector,";")) continue;
				else if((!strcmp(connector,"&&"))&&(rslt==0)) continue;
				else if((!strcmp(connector,"||"))&&(rslt==-1)) continue;
				else break;
			}else{
				break;
			}
			
		}
		free(p);
			
	}
	return 0;
}

