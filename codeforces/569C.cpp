#include <bits/stdc++.h>
#define N 1500000

using namespace std;
inline int MAX(int a,int b){return (a<b)?b:a;}
inline int MIN(int a,int b){return (a>b)?b:a;} 
inline int ABS(int a){return (a>0)?a:-a;}
int n,k;
int primes[N]={0};
int pali[N]={0};
char v[N/2];
int m[N];

void GeneratePrimes()
{
	primes[2]=1;
	int i,j,k;
	for(i=1;((i*i)<<1)+(i<<1)<N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
		{
			primes[(i<<1)+1]++;
			for(j=((i*i)<<1)+(i<<1),k=(i<<1)+1;(j<<1)+1<N;j+=k)
				v[j>>3]|=(1<<(j&7));
		}
	}
	for(;(i<<1)+1<N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
			primes[(i<<1)+1]++;
	}
	for(int i=1;i<N;++i)
	{
		primes[i]+=primes[i-1];
	}		
}

void GenearatePalindrome()
{
	for(int i=1;i<N;++i)
	{
		int j=i;
		int k=0;
		while(j!=0)
		{
			k=(k<<3)+(k<<1)+j%10;
			j/=10;
		}
		if(k==i)
			pali[i]++;
		pali[i]+=pali[i-1];
	}
}

int p,q;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  GeneratePrimes();
  GenearatePalindrome();
  cin>>p>>q;
  int low=1,high=N-1;
  int middle;
  int k=100000;
  while(low+1<high)
  {
  	middle=low+((high-low)>>1);
  	if(pali[middle]*p>=primes[middle]*q)
  	{
  		low=middle;
  	}
  	else
  	{
  		high=middle;
  	}
  }
  int ans=low;
  for(int i=low;i<=low+k;++i)
  {
  	if(pali[i]*p>=primes[i]*q)
  		ans=i;
  }
  cout<<ans<<endl;
  return 0;
}