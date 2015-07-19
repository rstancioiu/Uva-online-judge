// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/5/562.html
#include <iostream>
#include <vector>
#include <algorithm>
#define N 50001

using namespace std;
unsigned long long int ways[N];
vector<int> coins;

int main()
{
	int sum,value,tests;
	int nbCoins=0;
	cin>>tests;
	while(tests--)
	{
		cin>>nbCoins;
		sum=0;
		for(int i=0;i<nbCoins;++i)
		{
			cin>>value;
			coins.push_back(value);
			sum+=value;
		}
		sort(coins.rbegin(),coins.rend());
		int mid=sum/2;
		for(int i=0;i<=mid;++i)
		{
			ways[i]=0;
		}
		ways[0]=1;
		for(int i=0;i<nbCoins;++i)
		{
			for(int j=mid;j>=1;--j)
			{
				if(j>=coins[i]  && ways[j-coins[i]]!=0)
					ways[j]=ways[j-coins[i]];
			}
		}
		for(int i=mid;i>=0;--i)
		{
			if(ways[i]!=0)
			{
				cout<<sum-2*i<<endl;
				break;
			}
		}
		coins.clear();
	}
	return 0;
}