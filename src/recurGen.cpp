/*
   
   S->AB | aS
   A->a
   B->b


   S() { int pos = i; return(A() && B() || (i=pos, str[i++]==c && S()));}

   A() { *no need of pos because single production on RHS* return(str[i++]=='a')}

   B() { *no need of pos because single production on RHS* return(str[i++]=='b')}

   

   So basically the structure is like this
   <func>() { int pos = i; return(str[i++]==<ter1> && <func>()); }
   
   */


#include<iostream>
using namespace std;
char func_names[100][100];
char variables[100][100];
char terminals[100][100];

class Generator
{
	
	//Function takes the list of terminals and variables from the user.
	//and stores it in a searchable datastructure
	void makeSpecs();


	//Will read the production and classify the RHS as terminals or variables with help of the specs generated
	void classifyTerminalsVars()
		

	// Generate the source code for the productions
	// Core logic lies here
	void makeSourceCode()

	//Will generate the executable from the source file
	void makeProgram()
	       	
};


// class to handle all source code making
class SourceMaker
{
	//functions to handle file creation 
	//functions for changing the configuration for the Generator (change the static strings)
};
