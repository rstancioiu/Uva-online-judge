#include <bits/stdc++.h>
#define N 22

using namespace std;
int a,b,c,t,T;
long long mat[N][N][N]={0};
long long sum[N][N][N]={0};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	t=0;
	while(T--)
	{
		if(t++)	cout<<"\n";
		cin>>a>>b>>c;
		for(int i=1;i<=a;++i)
			for(int j=1;j<=b;++j)
				for(int k=1;k<=c;++k)
					cin>>mat[i][j][k];

		for(int i=1;i<=a;++i)
			for(int j=1;j<=b;++j)
				for(int k=1;k<=c;++k)
					sum[i][j][k]=sum[i-1][j][k]+sum[i][j][k-1]+sum[i][j-1][k]-sum[i-1][j-1][k]-sum[i][j-1][k-1]-sum[i-1][j][k-1]+sum[i-1][j-1][k-1]+mat[i][j][k];
		long long maximum = mat[1][1][1];
		for(int t1=1;t1<=a;++t1)
		{
			for(int t2=1;t2<=b;++t2)
			{
				for(int t3=1;t3<=c;++t3)
				{
					for(int t4=t1;t4<=a;++t4)
					{
						for(int t5=t2;t5<=b;++t5)
						{
							for(int t6=t3;t6<=c;++t6)
							{
								long long s = sum[t4][t5][t6]-(sum[t1-1][t5][t6]+sum[t4][t2-1][t6]+sum[t4][t5][t3-1]-sum[t1-1][t2-1][t6]-sum[t1-1][t5][t3-1]-sum[t4][t2-1][t3-1]+sum[t1-1][t2-1][t3-1]);
								if(s>maximum)
									maximum=s;
							}
						}
					}
				}
			}
		}		
		cout<<maximum<<"\n";
	}
	return 0;
}