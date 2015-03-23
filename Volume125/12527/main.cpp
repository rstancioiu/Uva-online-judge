#include <cstdio>
#define N 5001

using namespace std;
int n,m;
int nbStreets[N]={0};

int main()
{
	int digits[4];
	for(int i=1;i<N;++i)
	{
		bool repeat=false;
		int k=i,cnt=0;
		while(k!=0)
		{
			digits[cnt++]=k%10;
			k/=10;
		}
		for(int j=0;j<cnt;++j)
		{
			for(int k=j+1;k<cnt;++k)
			{
				if(digits[j]==digits[k])
				{
					repeat=true;
				}
			}
		}
		if(repeat)
		{
			nbStreets[i]=nbStreets[i-1];
		}
		else 
		{
			nbStreets[i]=nbStreets[i-1]+1;
		}
	}
	while(scanf("%d %d",&n,&m)==2)
	{
		printf("%d\n",nbStreets[m]-nbStreets[n-1]);
	}

	return 0;
}