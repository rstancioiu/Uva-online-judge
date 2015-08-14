#include <bits/stdc++.h>
#define N 128

using namespace std;
int n,m;
int a[N][N];
int c[N]={0};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
	for(int i=1;i<=m;++i)
	{
		int maximum=-1;
		int pos=-1;
		for(int j=1;j<=n;++j)
		{
			if(a[i][j]>maximum)
			{
				maximum=a[i][j];
				pos=j;
			}
		}
		c[pos]++;
	}
	int maximum=-1;
	int ans=0;
	for(int i=0;i<N;++i)
	{
		if(c[i]>maximum)
		{
			maximum=c[i];
			ans=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}