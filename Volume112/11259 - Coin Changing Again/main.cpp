#include <bits/stdc++.h>
#define M 4
#define N 100100

using namespace std;
int n,q,v;
int c[M],d[M];
long long dp[N];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		for(int i=0;i<M;++i)
			cin>>c[i];
		cin>>q;
		for(int i=0;i<N;++i)
			dp[i]=0;
		dp[0]=1;
		for(int j=0;j<M;++j)
			for(int i=c[j];i<N;++i)
				dp[i]+=dp[i-c[j]];
		while(q--)
		{
			for(int i=0;i<M;++i)
				cin>>d[i];
			cin>>v;
			long long ans=0;
			for(int i=0;i<16;++i)
			{
				int sign=1,tmp=v;
				for(int j=0;j<M;++j)
				{
					if(i&(1<<j))
					{
						tmp-=(d[j]+1)*c[j];
						sign*=-1;
					}
				}
				if(tmp>=0)
					ans+=dp[tmp]*sign;
			}
			cout<<ans<<"\n";
		}	
	}

	return 0;
}