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
	string cmd;
	while(TRUE) {
		string line;
		getline(cin,line);
		Parsing* p = new Parsing(line);  
		p->readCommands();
/*
		if(fork()!=0){
			waitpid(-1,&status,0);
		} else {
			int i = 0;
			do{
				execvp(p->getCommandArray(i).c_str(), p->getParameterArray(i));
			}while(p->getConnectorArray(i).empty());
		}
*/
		for(int i = 0; p->getCommandArray(i, cmd)!=0; i++){
			char** argv;
			argv = (char**)malloc(sizeof(char *)*(1024+2));
			for(int j = 0 ; p->getParameter(i,j,argv[j])!=0; j++) {
				//argv[j] = p->getParameter(i,j);
				cout<<argv[j]<<endl;
			}		
			execvp(cmd.c_str(), argv);
			cout<<"end"<<endl;
		}
			
	}
}

