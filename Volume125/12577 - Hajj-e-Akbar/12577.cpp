// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/125/12577.html
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string s;
	int nb=0;
	while(cin>>s)
	{
		if(s=="*")
			break;
		nb++;
		if(s=="Hajj")
			cout<<"Case "<<nb<<": Hajj-e-Akbar\n";
		if(s=="Umrah")
			cout<<"Case "<<nb<<": Hajj-e-Asghar\n";
	}
	return 0;
}