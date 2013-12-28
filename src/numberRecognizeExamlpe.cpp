#include<iostream>
#include<string.h>
 using namespace std;
char *str;
int i=0;
bool S() { 
 int pos=i; 
 return(( str[i++]=='0' && S()) ||  
		 (i=pos, str[i++]=='1' && S()) ||  
		 (i=pos, str[i++]=='2' && S()) ||  
		 (i=pos, str[i++]=='3' && S()) ||  
		 (i=pos, str[i++]=='4' && S()) ||  
		 (i=pos, str[i++]=='5' && S()) ||  
		 (i=pos, str[i++]=='6' && S()) ||  
		 (i=pos, str[i++]=='7' && S()) ||  
		 (i=pos, str[i++]=='8' && S()) ||  
		 (i=pos, str[i++]=='9' && S()) ||  
		 (i=pos, str[i++]=='0') ||  
		 (i=pos, str[i++]=='1') ||  
		 (i=pos, str[i++]=='2') ||  
		 (i=pos, str[i++]=='3') ||  
		 (i=pos, str[i++]=='4') ||  
		 (i=pos, str[i++]=='5') ||  
		 (i=pos, str[i++]=='6') ||  
		 (i=pos, str[i++]=='7') ||  
		 (i=pos, str[i++]=='8') ||  
		 (i=pos, str[i++]=='9') );
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
