#include <bits/stdc++.h>

using namespace std;
int n;
string s;
set<string> tab;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.length();++i)
	{
		for(int j=0;j<26;++j)
		{
			string t=s.substr(0,i);
			t+=('a'+j);
			t+=s.substr(i);
			set<string>::iterator it=tab.find(t);
			if(it==tab.end())
				tab.insert(t);
		}
	}
	for(int i=0;i<26;++i)
	{
		string t=s;
		t+=('a'+i);
		set<string>::iterator it=tab.find(t);
		if(it==tab.end())
			tab.insert(t);
	}
	cout<<tab.size()<<endl;
	return 0;
}