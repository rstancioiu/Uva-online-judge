#include <bits/stdc++.h>
#define N 50

using namespace std;
int primes[N]={0};
vector<int> tab;
int vis[N]={0};
int n;

void compute(int j)
{
	if(j==n)
	{
		int p=tab[0]+tab[n-1];
		if(primes[p]==1)
		{
			for(int i=0;i<n-1;++i)
				cout<<tab[i]<<" ";
			cout<<tab[n-1]<<"\n";
		}
	}
	int p = (tab[j-1]+1)%2;
	for(int i=2+p;i<=n;i+=2)
	{
		if(!vis[i])
		{
			int p = i+tab[j-1];
			if(primes[p]==1)
			{
				tab[j]=i;
				vis[i]=1;
				compute(j+1);
				vis[i]=0;
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i=2;i<N;++i)
	{
		if(primes[i]==0)
		{
			primes[i]=1;
			for(int j=i+i;j<N;j+=i)
				primes[j]=2;
		}
	}
	int c=1;
	while(cin>>n)
	{
		for(int i=1;i<=n;++i)
			tab.push_back(i);
		for(int i=1;i<=n;++i)
			vis[i]=0;
		if(c!=1)
			cout<<"\n";
		cout<<"Case "<<c++<<":\n";
		compute(1);
		tab.clear();
	}
	return 0;
}