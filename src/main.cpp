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
//	int status = 0;
	char cmd[32];
	char* parameter[1024];
	char buffer[32];
	while(TRUE) {
		string line;
		getline(cin,line);
		Parsing* p = new Parsing(line);  
		p->readCommands();
/*
		if(fork()!=0){
			waitpid(-1,&status,0);
		} else {

*/
		for(int i = 0; p->getCommandArray(i, cmd); i++){
			for(int j = 0; p->getParameter(i,j,buffer); j++) {
				parameter[j] = buffer;

			}	
			execvp(cmd, parameter);
		}
			
	}
}

