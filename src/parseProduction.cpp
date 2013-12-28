#include<string>
#include<iostream>
#define TOKEN " " 
using namespace std;
void makeProdFunction(string pstring)
{

	//REQUIREMENT:  no prefixed <space> at starting of production
//	string pstring ="S ->      Af    pstring    |  END    sdf  ";
	pstring=pstring+TOKEN;
	list<string> symbol_list;

	int lastpos=0;
       	int store_last = 0;
	int length=pstring.length();
	string symbol;


	lastpos = pstring.find(TOKEN,lastpos);
	string fun_name = pstring.substr(0,lastpos);
	store_last = lastpos+1;


	while(store_last<length)
	{
	lastpos = pstring.find(TOKEN,lastpos+1);
	symbol = pstring.substr(store_last,lastpos-store_last);
	store_last = lastpos+1;
	if(symbol!="")
		symbol_list.push_back(symbol);
	}



}
