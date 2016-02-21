#include <bits/stdc++.h>
#define N 10001

using namespace std;
vector<int> primes;
int vis[N]={0};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i=2;i<N;++i)
	{
		if(!vis[i])
		{
			primes.push_back(i);
			for(int j=i+i;j<N;j+=i)
				vis[j]=1;
		}
	}
	int n;
	while(cin>>n && n>0)
	{
		int cnt=0;
		int p = n;
		int root =sqrt(n);
		for(int i=0;primes[i]<=root;++i)
		{
			if(n%primes[i]==0)
			{
				cnt++;
				while(n%primes[i]==0)
					n/=primes[i];
			}
		}
		if(n>1)
			cnt++;
		cout<<p<<" : "<<cnt<<"\n";
	}

	return 0;
}