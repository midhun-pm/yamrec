#ifndef _DATA_ENTRY_H
#define _DATA_ENTRY_H

#include<fstream>
#include<list>
#include<map>
#include<string>
using namespace std;
extern void enterTerminals();
extern void enterVariables();
extern void enterProductions();

extern void addTerminal();
extern void addVariable();
extern void addProduction();

extern void printTerminals();
extern void printVariables();
extern void printProductions();

extern void generateConfigFile();
extern void readFile(string);



extern list<string> group_terminals;
extern list<string> group_variables;
extern list<string> group_productions;
extern map<string, int> classify;



extern list<string> group_productions;
#endif
