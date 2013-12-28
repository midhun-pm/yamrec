#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include"data_entry.h"

using namespace std;

extern bool start_symbol_set;

bool correct_conf = true;

ofstream fobj;
const char *filename = "./output.cpp";

void createFile()
{
	string program_begin_section = 	
					
"#include<iostream>\n\
#include<string>\n\
#include<sstream>\n\
 using namespace std;\n\
\
string str[1000];\n\
int i;\n\
int input_len;\n\
"				
;
	fobj.open(filename,ios::out);
	fobj<<program_begin_section;

	list<string> :: iterator var;
	var = group_variables.begin();

	while(var!=group_variables.end())
	{
		fobj<<"\nbool "<<*var<<"();";
		var++;
	}
}

void closeFile()
{
	string program_end_section="\n\n\
int main(int argc, char* argv[])\n\
{\n\
	i=0;\n\
	input_len=0;\n\
	string input;\n\
	int j=0;\n\
	if(argc != 1)\n\
	{\n\
		input_len = argc-1;\n\
	for(;j<argc-1;j++)\n\
	str[j] = argv[j+1];\n\
	}\n\
	else\n\
	{\n\
	cout<<\">\";\n\
	getline(cin,input);\n\
	stringstream strm(input);\n\
	while(strm >> input)\n\
	{\n\
		str[j++]=input;\n\
		input_len++;\n\
	}\n\
	}\n \
	if(S() && i==input_len)\n\
	cout<<\"VALID\\n\";\n\
	else\n\
	cout<<\"INVALID\"<<\" FAULT AT POSITION: \"<<i+1<<\"\\n\";\n\
}\n\
";
	fobj<<program_end_section;
	fobj.close();
}

void correctConfig()
{
	if(!start_symbol_set || group_variables.size()==0 || group_terminals.size()==0 || group_productions.size()==0 )correct_conf = false;

}

void makeExe()
{
	correctConfig();

	if(!correct_conf)
		cout<<"ERROR IN CONFIGURATION\n";

/*	else if(leftRecursive())
	{


	}
*/
	else 
	{
	system("g++ -o validator output.cpp");
	cout<<"validator creation success!\n";
	}
}

void makeClean()
{
	system("rm output.cpp");
}
