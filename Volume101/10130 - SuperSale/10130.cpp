#include <bits/stdc++.h>
#define X first
#define Y second
#define ii pair<int,int> 
#define M 32
#define N 1024

using namespace std;

int t,n,a,b;
vector<ii> prod;
vector<int> mem;
int dp[M];
int ans;

void compute()
{
	ans=0;
	sort(mem.begin(),mem.end());
	for(int i=0;i<M;++i)
		dp[i]=0;
	for(int i=0;i<prod.size();++i)
	{
		int price = prod[i].X;
		int weight = prod[i].Y;
		for(int j=M-weight-1;j>=0;--j)
		{
			if(dp[j]>0 && dp[j+weight]<dp[j]+price)
			{
				dp[j+weight]=dp[j]+price;
			}
		}
		if(price>dp[weight])
		{
			dp[weight]=price;
		}		
	}
	for(int member=0;member<mem.size();++member)
	{
		int k = mem[member];
		int maximum = 0;
		int pos=0;
		for(int i=1;i<=k;++i)
		{
			if(dp[i]>maximum)
			{
				maximum = dp[i];
				pos= i ;
			}
		}
		ans+=maximum;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>a>>b;
			prod.push_back(ii(a,b));
		}
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>a;
			mem.push_back(a);
		}
		compute();
		cout<<ans<<"\n";
		prod.clear();
		mem.clear();
	}
	return 0;
}