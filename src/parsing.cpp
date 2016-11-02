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
		cout<<"temp: "<< temp[j] << endl;
		if (j == 0) {
			cout<<"j == 0"<<endl;
			this->command[l] = temp[j];
			cout<<command[l]<<endl;
			l++; 
			continue;

		}
		if ((temp[j] == ";") || (temp[j] == "&&") || (temp[j] == "||")) {
			cout<<"temp[j] == ; ||"<<endl;
			connector[m] = temp[j];	
			cout<<connector[m]<<endl;
			m++;	
			n = 0;
			continue;
	
		}
		if ((temp[j-1] == ";") || (temp[j-1] == "&&") || (temp[j-1] == "||")) {
			cout << "cmd" << endl;
			command[l] = temp[j];
			cout<<command[l]<<endl;
			l++; 
			continue;

		}
			cout << "parameter"<<endl;
			parameter[l-1][n]=temp[j];
			cout<<parameter[l-1][n]<<endl;
			n++;	
	}

}

int Parsing::getCommandArray(int i, string str){
	if(command[i].empty())	return 0;
	else{
		str = this->command[i];
		return 1;
	}
}
int Parsing::getParameter(int i, int j, char* argv){
	//char* argv[1024];
	//for(unsigned int j = 0; !(parameter[i][j].empty()); j++){
	//	parameter[i][j].copy(argv[j],parameter[i][j].length(),0);	
	//}
	//return argv;
	if(parameter[i][j].empty()) {
		cout<<"out of range"<<endl;
		return 0;
	}else{
		cout<<"in range"<<endl;
		int len = parameter[i][j].length();
		cout<<len<<"paramater"<<parameter[i][j]<<endl;
		parameter[i][j].copy(argv,len,0);
		cout<<"argv = "<<argv<<endl;
		return 1;
	}
}

char** Parsing::getParameters(int i){
	for(int j=0 ; !(parameter[i][j].empty()); j++)
		parameter[i][j].copy(this->para_of_one_cmd[j],parameter[i][j].length(),0);
	cout<<para_of_one_cmd[0]<<endl;
	return para_of_one_cmd;
}


string Parsing::getConnectorArray(int i){
	return this->connector[i];
}
