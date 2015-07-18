// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/4/458.html
#include <iostream>
#include <string>

using namespace std;



int main()
{
	int t=-7;
	string s;
	while(getline(cin,s))
	{
		for(int i=0;i<s.length();++i)
		{
			s[i]=(char)(s[i]+t);
		}
		cout<<s<<endl;
	}
	return 0;
}