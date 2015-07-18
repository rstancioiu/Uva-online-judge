// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/5/575.html
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	while(cin>>s)
	{
		if(s=="0")
			break;
		int res=0;
		int k=2;
		for(int i=s.length()-1;i>=0;--i)
		{
			res+=(k-1)*(s[i]-'0');
			k*=2;
		}
		cout<<res<<endl;
	}
	return 0;
}