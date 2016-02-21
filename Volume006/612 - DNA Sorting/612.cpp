#include <bits/stdc++.h>
#define N 128
#define F first
#define S second

using namespace std;
int t,n,m;
string s;
vector<pair<pair<int,int>,string> > tab; 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	int c=0;
	while(t--)
	{
		if(c++)
			cout<<"\n";
		cin>>m>>n;
		for(int i=0;i<n;++i)
		{
			cin>>s;
			tab.push_back(make_pair(make_pair(0,i),s));
		}
		for(int i=0;i<n;++i)
		{
			string s = tab[i].S;
			sort(s.begin(),s.end());
			string p = tab[i].S;
			int cnt=0;
			for(int j=0;j<m;++j)
			{
				string t1="",t2="";
				bool first=false;
				int pos=0;
				for(int k=0;k<p.length();++k)
				{
					if(s[j]==p[k] && !first)
					{
						first=true;
						pos=k;
					}
					else if(!first)
						t1+=p[k];
					else if(first)
						t2+=p[k];
				}
				p = t1+t2;
				cnt+=pos;
			}
			tab[i].F.F=cnt;
		}	
		sort(tab.begin(),tab.end());
		for(int i=0;i<n;++i)
			cout<<tab[i].S<<"\n";
		tab.clear();
	}


	return 0;
}