#include <bits/stdc++.h>

using namespace std; 
typedef pair<int,int> ii;
int t,n,m,a,b;
string s;
map<string,ii> tab;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int c=0;c<t;++c)
	{
		if(c)
			cout<<"\n";
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>s>>a>>b;
			tab[s]=ii(a,b);
		}
		cin>>m;
		for(int i=0;i<m;++i)
		{
			cin>>a;
			map<string,ii>::iterator it;
			string ans;
			int cnt=0;
			for(it=tab.begin();it!=tab.end();++it)
			{
				if(it->second.first<=a && it->second.second>=a)
				{
					cnt++;
					ans=it->first;
				}
			}
			if(cnt==1)
			{
				cout<<ans<<"\n";
			}
			else cout<<"UNDETERMINED\n";
		}
		tab.clear();
	}

	return 0;
}