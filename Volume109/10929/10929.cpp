// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/109/10929.html
#include <iostream>
#include <string>

using namespace std;

int modulo(string s,int mod)
{
	int t=0;
	for(int i=0;i<s.length();++i)
	{
		t*=10;
		t+=s[i]-'0'+mod;
		t%=mod;
	}
	return t;
}


int main()
{
	string s;
	while(cin>>s)
	{
		if(s=="0")
			break;
		if(modulo(s,11)==0)
			cout<<s<<" is a multiple of 11."<<endl;
		else
			cout<<s<<" is not a multiple of 11."<<endl;
	}
	return 0;
}