// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/124/12403.html
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t,donation,account;
	string s;
	account=0;
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(s=="donate")
		{
			cin>>donation;
			account+=donation;
		}
		if(s=="report")
		{
			cout<<account<<"\n";
		}
	}
	return 0;
}