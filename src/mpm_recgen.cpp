/*
YAMREC	--- Yet Another Amrita's Recursive descent parser generator

--By 
*/
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include"program_handler.h"
#include"prompt.h"
#include"data_entry.h"

#define TERMINAL_INDICATOR 0
#define VARIABLE_INDICATOR 1
#define SEPARATOR " "  // Used to separate symbols in production input

using namespace std;

int variable_count;
int terminal_count;
int production_count;
bool start_symbol_set = false;

void init()
{
	terminal_count = variable_count = 0;
}

void makeFunction(string lhs, list<string> rhs)
{
	fobj<<"\nbool "<<lhs<<"() { \n int pos=i; \n return(";
	list<string>::iterator itr = rhs.begin();
	bool ampsand_print = true;


	itr=rhs.begin();

		if(classify[*itr]==TERMINAL_INDICATOR)
			fobj<<"( str[i++]=="<<"\""<<*itr<<"\"";
		
		else if(classify[*itr]==VARIABLE_INDICATOR)
			fobj<<"( "<< *itr<<"()";
		
		else if(*itr=="|")
			{fobj<<") ||  \n\t\t"<<"(i=pos, "; ampsand_print = false;}
	itr++;

	for(;itr!=rhs.end();itr++)
	{
		if(*itr=="|")
		{
		fobj<<") ||  \n\t\t ("<<"i=pos, ";
		ampsand_print = false;
		continue;
		}
		else if(ampsand_print)
		fobj<<" && ";

		if(classify[*itr]==TERMINAL_INDICATOR)
			fobj<<"str[i++]=="<<"\""<<*itr<<"\"";
		
		else if(classify[*itr]==VARIABLE_INDICATOR)
			fobj<<*itr<<"()";

		ampsand_print = true;
	}

	fobj<<") );";
	fobj<<"\n}";
}

	//REQUIREMENT:  no prefixed <space> at starting of production
void makeProdFunction(string pstring)
{
	pstring=pstring+SEPARATOR;
	list<string> symbol_list;

	int lastpos=0;
       	int store_last = 0;
	int length=pstring.length();
	string symbol;

	lastpos = pstring.find(SEPARATOR,lastpos);
	string fun_name = pstring.substr(0,lastpos);
	if (fun_name=="S") start_symbol_set=true;
	store_last = lastpos+1;

	lastpos = pstring.find(SEPARATOR,lastpos+1);
	symbol = pstring.substr(store_last,lastpos-store_last);
	if(symbol!="->")correct_conf = false;
	store_last = lastpos+1;

	while(store_last<length)
	{
	lastpos = pstring.find(SEPARATOR,lastpos+1);
	symbol = pstring.substr(store_last,lastpos-store_last);
	store_last = lastpos+1;
	if(symbol!="")
		//TODO: Check if the symbol is a valid variable or terminal mentioned before
		symbol_list.push_back(symbol);
	}
	
	makeFunction(fun_name,symbol_list);
}

void parseProductions()
{
	list <string> :: iterator pd;
	pd=group_productions.begin();
	while(pd!=group_productions.end())
	{
		makeProdFunction(*pd);
		pd++;
	}
}


int main(int argc, char *argv[])
// ADD functionality for multi letter string entry
{
	init();

	if(argc == 1)
		menu(1);
	else
	{
		if(!strcmp(argv[1],"-config"))
		{
			generateConfigFile();		
			return 0;
		}
		else
		{
		readFile(argv[1]);
		createFile();
		parseProductions();
		closeFile();
		makeExe();
		}
	}

	//createFile();
//	parseProductions();
//	closeFile();
//	makeExe();
	return 0;
}
