#include <iostream>
#include <vector>
#include <algorithm>
#define N 1000000

using namespace std;

vector<int> primes;
char v[N/2/8];

void prime()
{
	int i,j,k;
	for(i=1;((i*i)<<1)+(i<<1)<=N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
		{
			primes.push_back((i<<1)+1);
			for(j=((i*i)<<1)+(i<<1),k=(i<<1)+1;(j<<1)+1<=N;j+=k)
			{
				v[j>>3]|=(1<<(j&7));
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
	prime();
	int n;
	vector<int>::iterator it,it1;
	while(cin>>n)
	{
		if(n==0)
			break;
		for(it=primes.begin();it!=primes.end() && ((*it)<<1)<=n;++it)
		{
			if(binary_search(primes.begin(),primes.end(),n-(*it)))
			{
				cout<<n<<" = "<<*it<<" + "<<n-(*it)<<endl;
				break;
			}
		}
		if(it==primes.end() || ((*it)<<1)>n)
		{
			cout<<"Goldbach's conjecture is wrong."<<endl;
		}
	}
	return 0;
}