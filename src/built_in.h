#include <iostream>
#include <pwd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> 
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;
class Built_in {
    public:
        Built_in(char*, char**);
        int cd();
        int about(){};
    private:
	struct passwd *pwd;
        char* command;
        char** parameters;

};
