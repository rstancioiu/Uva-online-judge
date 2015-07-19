// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/6/686.html
#include <iostream>
#include <vector>
#include <algorithm>
#define N 33000

using namespace std;
vector<int> primes;
char v[N];

void GeneratePrimes()
{
	int i,k,j;
	for(i = 1; ((i * i) << 1) + (i << 1) <= N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
		{
			primes.push_back((i<<1)+1);
			for(j=((i*i)<<1)+(i<<1),k=(i<<1)+1;(j<<1)+1<=N;j+=k)
			{
				v[j>>3]|=1<<(j&7);
			}
		}
	}
	for(;(i<<1)+1<=N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
			primes.push_back((i<<1)+1);
	}
}

int main()
{
	primes.push_back(2);
	GeneratePrimes();
	int n,cnt;
	vector<int>::iterator it; 
	while(cin>>n)
	{
		if(n==0)
			break;
		cnt=0;
		for(it=primes.begin();it!=primes.end()&&((*it)<<1)<=n;++it)
		{
			if(binary_search(primes.begin(),primes.end(),n-(*it)))
				cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}