//THis will create a prompt 
#include<iostream>
#include<string>
#include<cstdlib>
#include"data_entry.h"

#define TER_COMMAND "ter"
#define VAR_COMMAND "var"
#define PRO_COMMAND "pro"
#define GEN_COMMAND "gen"
#define CLEAR_COMMAND "clear"
#define HELP "help"
#define ENTER ""
#define EXIT_COMMAND "exit"
#define PRINT_PRO_COMMAND "list pro"
#define PRINT_TER_COMMAND "list ter"
#define PRINT_VAR_COMMAND "list var"
#define PRINT_CONFIG_COMMAND "show config"

#define TERCODE 1
#define VARCODE 2
#define PROCODE 3
#define GENCODE 4
#define EXITCODE 5
#define ENTERCODE 6
#define HELPCODE 7
#define CLEARCODE 8
#define PRINTPCODE 9
#define PRINTTCODE 10
#define PRINTVCODE 11
#define PRINTCONFIGCODE 12
#define YPROMPT "yamrec>"

extern void createFile();
extern void parseProductions();
extern void closeFile();
extern void makeExe();


int getCode(string command)
{
	if(command == TER_COMMAND)
		return TERCODE; 
	else if(command == VAR_COMMAND)
	       return VARCODE;	
	else if(command == PRO_COMMAND)
		return PROCODE;
	else if(command == GEN_COMMAND)
		return GENCODE;
	else if(command == EXIT_COMMAND)
		return EXITCODE;
	else if(command == ENTER)
		return ENTERCODE;
	else if(command == HELP)
		return HELPCODE;
	else if(command == CLEAR_COMMAND)
		return CLEARCODE;
	else if(command == PRINT_PRO_COMMAND)
		return PRINTPCODE;
	else if(command == PRINT_VAR_COMMAND)
		return PRINTVCODE;
	else if(command == PRINT_TER_COMMAND)
		return PRINTTCODE;
	else if(command == PRINT_CONFIG_COMMAND)
		return PRINTCONFIGCODE;
	return -1;
}
int prompt()
{
	string uinput;
for(;;)
{	
	cout<<YPROMPT;
	getline(cin,uinput);
		switch(getCode(uinput))
		{
			case TERCODE:
				enterTerminals();
				break;
			case VARCODE:
				enterVariables();
				break;
			case PROCODE:
				enterProductions();
				break;
			case PRINTPCODE:
				printProductions();
				break;
			case PRINTTCODE:
				printTerminals();
				break;
			case PRINTVCODE:
				printVariables();
				break;
			case PRINTCONFIGCODE:
				printTerminals();
				printVariables();
				printProductions();
				break;
			case GENCODE:
				createFile();
				parseProductions();
				closeFile();
				makeExe();
				break;

			case CLEARCODE:
				system("clear");
				break;

			case HELPCODE:
				cout<<"ter : Input a list of terminals\nvar: Input a list of variables\npro: Input list of productions\ngen: Generate the parser\nprint <pro|ter|var>: Display\nshow config: Display parser configuration\nexit: Quit \nhelp: Print this help text\n";
				
				break;
			case ENTERCODE:
				break;
			case EXITCODE:
				return 0;
				break;

			default:
				cout<<"Unrecognized command: "<<uinput<<"\n";
			break;
		}
}
}

void menu(int en_prompt=0)
{
	if(en_prompt==1)
		prompt();
	else
	{
	enterTerminals();
	enterVariables();
	enterProductions();
	
	createFile();
	parseProductions();
	closeFile();
	makeExe();
	}
}


