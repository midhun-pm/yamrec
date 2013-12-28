#include<iostream>
#include<string.h>
 using namespace std;
char *str;
int i=0;

bool S();
bool S() { 
 int pos=i; 
 return(( str[i++]=='1' && S()) ||  
		 (i=pos, str[i++]=='2' && S()) ||  
		 (i=pos, str[i++]=='3' && S()) ||  
		 (i=pos, str[i++]=='1') ||  
		 (i=pos, str[i++]=='2') ||  
		 (i=pos, str[i++]=='3') );
}

int main(int argc, char* argv[])
{
	str = new char[1000];
	str = argv[1];
	if(S() && i==strlen(str))
	cout<<"VALID";
	else
	cout<<"INVALID";
}
