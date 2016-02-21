#include <bits/stdc++.h>
#define N 128

using namespace std;
typedef long long ll;
int t,n,m,k;
ll mat[N][N];
ll sum[N][N]={0};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int c=1;c<=t;++c)
	{
		cin>>n>>m>>k;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				cin>>mat[i][j];
		for(int i=1;i<=n;++i)
		{
			ll partial_sum=0;
			for(int j=1;j<=m;++j)
			{
				partial_sum+=mat[i][j];
				sum[i][j]=partial_sum+sum[i-1][j];
			}
		}
		ll max_area=0;
		int price = 0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				for(int a=i;a<=n;++a)
				{
					for(int b=j;b<=m;++b)
					{
						ll s = sum[a][b]+sum[i-1][j-1]-sum[a][j-1]-sum[i-1][b];
						if(s>k)
							break;
						int area = (a-i+1)*(b-j+1);
						if(area<max_area)
							continue;
						if(s<=k && area>max_area)
						{
							max_area=area;
							price = s;
						} 
						else if(area==max_area && s<price)
							price = s;
					}
				}
			}
		}
		cout<<"Case #"<<c<<": "<<max_area<<" "<<price<<"\n";
	}

	return 0;
}