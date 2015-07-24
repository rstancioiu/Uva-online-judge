#include <cstdio>
#include <iostream>
#include <vector>
#define N 128

using namespace std;
int tab[N][N];
vector<int> res;
int n;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			scanf("%d",&tab[i][j]);
	}
	for(int i=0;i<n;++i)
	{
		int j;
		for(j=0;j<n;++j)
		{
			if(i!=j)
			{
				if(tab[i][j]==1 || tab[i][j]==3)
				{
					break;
				}
			}
		}
		if(j==n)
			res.push_back(i);
	}
	printf("%d\n",res.size());
	if(res.size()!=0)
		printf("%d",res[0]+1);
	for(int i=1;i<res.size();++i)
	{
		printf(" %d",res[i]+1);
	}
	printf("\n");
	return 0;
}