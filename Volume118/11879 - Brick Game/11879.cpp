// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/118/11879.html
#include <iostream>
#include <string>
#define MOD 17

using namespace std;

bool Divide(string a)
{
	int t=0;
	for(int i=0;i<a.length();++i)
	{
		t*=10;
		t+=a[i]-'0';
		t%=MOD;
	}
	if(t==0)
		return true;
	else return false;
}


int main()
{
	string s;
	while(cin>>s && s!="0")
	{
		cout<<Divide(s)<<endl;
	}
	return 0;
}