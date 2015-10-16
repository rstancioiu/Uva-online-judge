#include <bits/stdc++.h>
#define N 1000

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int c[N];
int n,m,a,b,d;
vector<iii> e;

int find(int x){return (x==c[x])?x:find(c[x]);}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>m && !(n==0 && m==0))
	{
		for(int i=0;i<n;++i)
			c[i]=i;
		for(int i=0;i<m;++i)
		{
			cin>>a>>b>>d;
			e.push_back(make_pair(d,ii(a,b)));
		}
		sort(e.begin(),e.end());
		int cnt=0;
		for(int i=0;i<m;++i)
		{
			int p1=find(e[i].second.first);
			int p2=find(e[i].second.second);
			if(p1!=p2)
			{
				c[p1]=p2;
			}
			else
			{
				if(!cnt)
					cout<<e[i].first;
				else
					cout<<" "<<e[i].first;
				cnt++;
			}
		}
		if(!cnt)
			cout<<"forest";
		cout<<"\n";
		e.clear();
	}
	return 0;
}