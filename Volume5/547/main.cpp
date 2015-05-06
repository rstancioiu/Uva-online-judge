#include <cstdio>
#include <cmath>
#include <vector>
#define N 3001

using namespace std;
int n,m;
int sumDF[N]={0};
int sumDN[N]={0};
vector<int> ddf[N];

int SumDigitsNumber(int t)
{
	int sum=0;
	while(t!=0)
	{
		sum+=t%10;
		t/=10;
	}
	return sum;
}

void CalculeSumNumbers()
{
	for(int i=1;i<N;++i)
	{
		sumDN[i]=SumDigitsNumber(i);
	}
}

void CalculeSumFactors()
{
	sumDF[1]=1;
	for(int i=2;i<N;++i)
	{
		int t=sqrt(i);
		sumDF[i]=1+sumDN[i];
		for(int j=2;j<=t;++j)
		{
			if(i%j==0)
			{
				sumDF[i]+=sumDN[j];
				sumDF[i]+=sumDN[i/j];
			}
		}
		if(i==t*t)
		{
			sumDF[i]-=sumDN[t];
		}
	}
}

void CalculeDDF()
{
	int prev,i;
	ddf[0].push_back(0);
	for(i=1;i<N;++i)
	{
		ddf[i].push_back(i);
		prev=i;
		while(prev!=sumDF[prev])
		{
			prev=sumDF[prev];
			ddf[i].push_back(prev);
		}
	}	
}

int main()
{
	CalculeSumNumbers();
	CalculeSumFactors();
	CalculeDDF();
	int t=0;
	while(scanf("%d %d",&n,&m)==2)
	{
		t++;
		printf("Input%d: %d %d\n",t,n,m);
		if(n>m)
		{
			int aux=m;
			m=n;
			n=aux;
		}
		int maximum=n,sizemax=ddf[n].size();
		for(int i=n;i<=m;++i)
		{
			if(sizemax<ddf[i].size())
			{
				sizemax=ddf[i].size();
				maximum=i;
			}
		}
		printf("Output%d:",t);
		for(int i=0;i<ddf[maximum].size();++i)
		{
			printf(" %d",ddf[maximum][i]);
		}
		printf("\n");
	}
	return 0;
}