#include <bits/stdc++.h>
#define N 10
#define M 80

using namespace std;
typedef pair<int,int> ii;
vector<ii> ans[M];
int cnt[N];

void compute()
{
	int minimum = 0;
	int maximum = 100000;
	for(int k=2;k<M;++k)
	{
		for(int i=minimum;i*k<maximum;++i)
		{
			for(int j=0;j<N;++j)
				cnt[j]=0;
			int p1 = i*k;
			int p2 = i;
			int t=1;
			while(t<maximum)
			{
				cnt[(p1/t)%10]++;
				cnt[(p2/t)%10]++;
				t=(t<<1)+(t<<3);
			}
			int j;
			for(j=0;j<N;++j)
			{
				if(cnt[j]!=1)
					break;
			}	
			if(j==N)
			{
				ans[k].push_back(ii(p1,p2));
			}
		}
		sort(ans[k].begin(),ans[k].end());
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	compute();
	int n;
	int p=0;
	while(scanf("%d",&n) && n!=0)
	{
		if(p++)
			printf("\n");
		if(ans[n].size()==0)
		{
			printf("There are no solutions for %d.\n",n);
		}
		else
		{
			for(int i=0;i<ans[n].size();++i)
				printf("%.5d / %.5d = %d\n",ans[n][i].first,ans[n][i].second,n);
		}
	}
	return 0;
}