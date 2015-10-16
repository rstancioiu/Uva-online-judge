#include <bits/stdc++.h>
#define N 200100

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long ll;
int n,m,a,b,d;
vector<iii> e;
int c[N];

int Find(int x){return (c[x]==x)?x:Find(c[x]);}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>m && !(n==0 && m==0))
	{
		for(int i=0;i<n;++i)
			c[i]=i;
		ll sum=0;
		for(int i=0;i<m;++i)
		{
			cin>>a>>b>>d;
			e.push_back(make_pair(d,ii(a,b)));
			sum+=d;
		}
		ll ans=0;
		sort(e.begin(),e.end());
		for(int i=0;i<e.size();++i)
		{
			int p1=Find(e[i].second.first);
			int p2=Find(e[i].second.second);
			if(p1!=p2)
			{
				c[p2]=p1;
				ans+=e[i].first;
			}
		}
		cout<<sum-ans<<"\n";
		e.clear();
	}
	return 0;
}