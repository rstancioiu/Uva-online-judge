// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/109/10943.html
#include <bits/stdc++.h>
#define MOD 1000000
#define N 101

using namespace std;
int tab[N][N];
int n,k;

void Compute()
{
	for(int i=0;i<N;++i)
	{
		tab[i][0]=0;
		tab[i][1]=1;
		tab[0][i]=1;
	}
	for(int i=1;i<N;++i)
	{
		for(int j=2;j<N;++j)
		{
			int a=0;
			for(int k=0;k<=i;++k)
			{
				a=(a+tab[k][j-1])%MOD;
			}
			tab[i][j]=a;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Compute();
	while(cin>>n>>k && !(n==0 && k==0))
	{
		cout<<tab[n][k]<<endl;
	}

	return 0;
}