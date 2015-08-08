#include <bits/stdc++.h>

using namespace std;
map<string,int> dict;
string s;
int n,d,t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>n;
		for(int j=0;j<n;++j)
		{
			cin>>s>>d;
			map<string,int>::iterator it=dict.find(s);
			if(it==dict.end())
				dict.insert(make_pair(s,d));
			else
				it->second=(d>it->second)?it->second:d;
		}
		cin>>d>>s;
		map<string,int>::iterator it=dict.find(s);
		if(it==dict.end() || it->second>d+5)
			cout<<"Case "<<i<<": Do your own homework!\n";
		else if(it->second <= d)
			cout<<"Case "<<i<<": Yesss\n";
		else if(it->second <=d+5)
			cout<<"Case "<<i<<": Late\n";
		dict.clear();
	}
	return 0;
}