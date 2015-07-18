// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/110/11029.html
#include <bits/stdc++.h>
#define MOD 1000

using namespace std;
unsigned int n,k;
int t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	int first,second;
	while(t--)
	{
		cin>>n>>k;
		int p=n%MOD;
		second=1;
		for(unsigned int j=0;(1<<j)<=k;j++)
		{
			if((1<<j)&k)
			{
				second=(second*p)%MOD;
			}
			p=(p*p)%MOD;
		}
		double mant=log10(n)*k;
		mant-=(int)mant-2;
		first=floor(pow(10,mant));
		printf("%d...%.3d\n",first,second);
	}
	return 0;
}
