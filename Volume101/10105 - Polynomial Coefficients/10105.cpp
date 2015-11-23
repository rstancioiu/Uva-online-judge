// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/101/10105.html
// Description: dynamic programming / maths 
#include <bits/stdc++.h>
#define N 16

using namespace std;

int comb[N][N]={0};

void GenerateComb()
{
	for(int i=0;i<N;++i)
	{
		comb[i][1]=i;
		comb[i][0]=1;
	}
	for(int i=1;i<N;++i)
	{
		for(int j=2;j<=i;++j)
		{
			comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	GenerateComb();
	int k,n,a;
	while(cin>>n>>k)
	{
		int sum=n;
        int ans=1;
		for(int i=0;i<k;++i)
		{
			cin>>a;
			ans=ans*comb[sum][a];
			sum-=a;
		}
		cout<<ans<<endl;
	}
	return 0;
}
