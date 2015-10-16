#include <bits/stdc++.h>
#define N 512

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<iii> e;
int x[N],y[N],c[N];
int n,m,t;

int find(int x){return (x==c[x])?x:find(c[x]);}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<m;++i)
		{
			cin>>x[i]>>y[i];
			c[i]=i;
		}
		for(int i=0;i<m;++i)
		{
			for(int j=i+1;j<m;++j)
			{
				int d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				e.push_back(make_pair(d,ii(i,j)));
			}
		}
		int cnt=m;
		sort(e.begin(),e.end());
		for(int i=0;i<e.size();++i)
		{
			int p1=find(e[i].second.first);
			int p2=find(e[i].second.second);
			if(p1!=p2)
			{
				c[p1]=p2;
				cnt--;
				if(cnt==n)
				{
					cout<<fixed<<setprecision(2)<<sqrt(e[i].first)<<"\n";
					break;
				}
			}
		}
		e.clear();
	}
	return 0;
}