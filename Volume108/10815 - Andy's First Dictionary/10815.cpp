#include <bits/stdc++.h>

using namespace std;

set<string> tab;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while(getline(cin,s))
	{
		string t="";
		for(int i=0;i<s.length();++i)
		{
			if(s[i]>='a' && s[i]<='z')
			{
				t+=s[i];
			}
			else if(s[i]>='A' && s[i]<='Z')
			{
				t+=s[i]+32;
			}
			else
			{
				if(t!="" && tab.find(t)==tab.end())
					tab.insert(t);
				t="";
			}
		}
		if(t!="" && tab.find(t)==tab.end())
			tab.insert(t);
		t="";
	}
	for(set<string>::iterator i=tab.begin();i!=tab.end();++i)
		cout<<*i<<endl;
	return 0;
}