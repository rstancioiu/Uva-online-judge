// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/122/12250.html
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	int nb=0;
	while(getline(cin,s) && s!="#")
	{
		nb++;
		if(s=="HELLO")
			cout<<"Case "<<nb<<": ENGLISH"<<endl;
		else if(s=="HOLA")
			cout<<"Case "<<nb<<": SPANISH"<<endl;
		else if(s=="HALLO")
			cout<<"Case "<<nb<<": GERMAN"<<endl;
		else if(s=="BONJOUR")
			cout<<"Case "<<nb<<": FRENCH"<<endl;
		else if(s=="CIAO")
			cout<<"Case "<<nb<<": ITALIAN"<<endl;
		else if(s=="ZDRAVSTVUJTE")
			cout<<"Case "<<nb<<": RUSSIAN"<<endl;
		else 
			cout<<"Case "<<nb<<": UNKNOWN"<<endl;
	}
	return 0;
}