// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/7/729.html
#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

set<string> res;

void generateString(string s,int n,int h)
{
	if(h==0)
	{
		for(int i=0;i<n;++i)
			s+='0';
		res.insert(s);
		return;
	}
	if(n==h)
	{
		for(int i=0;i<n;++i)
			s+='1';
		res.insert(s);
		return;
	}
	string p=s;
	s+='0';
	generateString(s,n-1,h);
	p+='1';
	generateString(p,n-1,h-1);
}


int main()
{
	int t,n,h;
	string s;
	getline(cin,s);
	istringstream iss(s);
	iss>>t;
	while(t--)
	{	
		getline(cin,s);
		getline(cin,s);
		istringstream iss(s);
		iss>>n>>h;
		string k="";
		generateString(k,n,h);
		set<string>::iterator it;
		for(it=res.begin();it!=res.end();++it)
		{
			cout<<*it<<endl;
		}
		res.clear();
		if(t!=0) cout<<endl;
	}	
	return 0;
}