#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int a,n,t;
vector<int> prices;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a);
			prices.push_back(a);
		}
		sort(prices.begin(),prices.end());
		int j=1;
		long sum=0;
		for(int i=n-1;i>=0;--i,j++)
		{
			if(j==3)
			{
				sum+=prices[i];
				j=0;
			}
		}
		printf("%ld\n",sum);
		prices.clear();
	}
	return 0;
}