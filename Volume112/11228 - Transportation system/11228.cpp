#include <bits/stdc++.h>
#define N 1001

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int c[N];
int x[N],y[N];
int n,r;
vector<iii> e;

int Find(int x){return (x==c[x])?x:Find(c[x]);}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;++t)
	{
		cin>>n>>r;
		for(int i=1;i<=n;++i)
		{
			cin>>x[i]>>y[i];
			c[i]=i;
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=i+1;j<=n;++j)
			{
				int d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				e.push_back(make_pair(d,ii(i,j)));
			}
		}
		sort(e.begin(),e.end());
		double ans1=0,ans2=0;
		int cnt=n;
		r*=r;
		for(int i=0;i<e.size();++i)
		{
			int p1=Find(e[i].second.first);
			int p2=Find(e[i].second.second);
			if(p1!=p2)
			{
				c[p1]=p2;
				int d=e[i].first;
				if(d<=r)
				{
					ans1+=sqrt(d);
					cnt--;
				}
				else
				{
					ans2+=sqrt(d);
				}
			}
		}
		cout<<"Case #"<<t<<": "<<cnt<<" "<<ll(ans1+0.5)<<" "<<ll(ans2+0.5)<<"\n";
		e.clear();
	}
}