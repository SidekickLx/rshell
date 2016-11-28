#include "main.h"
#define TRUE 1

using namespace std;


const int max_name_len = 256;
const int max_path_len = 1024;

void getprompt(char *prompt)
{
    struct passwd *pwd;
    char hostname[max_name_len];
    char pathname[max_path_len];
    int length;
    pwd = getpwuid(getuid());
    getcwd(pathname, max_path_len);
    if(gethostname(hostname, max_name_len)==0)
        sprintf(prompt,"[Rshell]%s@%s:",pwd->pw_name,hostname);
    else
        sprintf(prompt,"[Rshell]%s@unknown:",pwd->pw_name);
    length = strlen(prompt);
    if(strlen(pathname) < strlen(pwd->pw_dir) || strncmp(pathname,pwd->pw_dir,strlen(pwd->pw_dir))!=0)
        sprintf(prompt + length,"%s",pathname);
    else
        sprintf(prompt + length,"~%s", pathname+strlen(pwd->pw_dir));
    length = strlen(prompt);
    if(geteuid() == 0)
        sprintf(prompt + length,"#");
    else
        sprintf(prompt + length,"$");
    return;
}



int main(int argc, char* argv[]){
	int status = 0;
	char prompt[128];
	char cmd[32];
	char connector[10];
	while(TRUE) {
		int rslt = 0;
		char* parameter[1024];
		char buffer[32];
		string line;
		getprompt(prompt);
		cout<<prompt<<">>";
		getline(cin,line);
		Parsing* p = new Parsing(line);  
		p->readCommands();
		for(int i = 0; p->getCommandArray(i, cmd); i++){
			for(int j = 0; p->getParameter(i,j,buffer); j++){
				parameter[j] = (char*)malloc(1024*sizeof(char));
				strcpy(parameter[j],buffer);
			}
			Built_in* b = new Built_in(cmd,parameter);
			if(!(strcmp(cmd, "exit"))) exit(0);
			else if(!(strcmp(cmd, "cd"))){
				b->cd();
			}else if(!(strcmp(cmd,"test"))){
				b->test();
			}else if(fork()!=0){
				waitpid(-1,&status,0);
			} else {	
				rslt = execvp(cmd, parameter);
				perror("execvp failed"); 
				exit(0);
			}
			free(b);
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

