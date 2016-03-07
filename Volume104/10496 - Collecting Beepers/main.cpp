#include <bits/stdc++.h>
#define N 22
#define INF 0x7fffffff
#define F first
#define S second

using namespace std;
inline int ABS(int a){return (a>0)?a:-a;}
typedef pair<int,int> ii;
ii tab[N];
int t,ans,n,r,c,x,y;

void compute(int i,int sum)
{
	if(i==n)
	{
		int dist1 = ABS(x-tab[0].F)+ABS(y-tab[0].S);
		int dist2 = ABS(x-tab[n-1].F)+ABS(y-tab[n-1].S);
		sum+=dist1+dist2;
		if(sum<ans)
			ans=sum;
		return;
	}
	for(int j=i;j<n;++j)
	{
		swap(tab[i],tab[j]);
		if(i>0)
		{
			int dist1=ABS(tab[i].F-tab[i-1].F)+ABS(tab[i].S-tab[i-1].S);
			if(dist1+sum<ans)
				compute(i+1,sum+dist1);
		}
		else
			compute(i+1,sum);
	}
}

void solve()
{
	ans=INF;
	compute(0,0);
	cout<<"The shortest path has length "<<ans<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>r>>c;
		cin>>x>>y;
		cin>>n;
		for(int i=0;i<n;++i)
			cin>>tab[i].F>>tab[i].S;
		solve();
	}

	return 0;
}