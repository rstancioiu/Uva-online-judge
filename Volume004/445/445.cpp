// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/4/445.html
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string s;
	while(getline(cin,s))
	{
		int nb=0;
		for(int i=0;i<s.length();++i)
		{
			if(s[i]>='0'&&s[i]<='9')
				nb+=s[i]-'0';
			else if(s[i]=='b')
			{
				for(int j=0;j<nb;++j)
					cout<<" ";
				nb=0;
			}
			else if(s[i]=='!')
			{
				cout<<endl;
			}
			else
			{
				for(int j=0;j<nb;++j)
				{
					cout<<s[i];
				}
				nb=0;
			}
		}
		cout<<endl;
	}
	return 0;
}