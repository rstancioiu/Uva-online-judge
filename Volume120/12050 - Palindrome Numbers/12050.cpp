// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/120/12050.html
#include <bits/stdc++.h>

using namespace std;
int n;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n && n!=0)
	{
		long long int p=9;
		long long int sum=0;
		int cnt=1;
		while(sum<n)
		{
			sum+=p;
			cnt++;
			if(sum>=n)
			{
				sum-=p;
				cnt--;
				break;
			}
			else
			{
				sum+=p;
				cnt++;
			}
			if(sum>=n)
			{
				sum-=p;
				cnt--;
				break;
			}
			p*=10;
		}
		int x=1;
		for(int i=1;i<(cnt+1)/2;++i)
			x*=10;
		int k=n-sum+x-1;
		cout<<k;
		if(cnt%2==1)
			k/=10;
		while(k!=0)
		{
			cout<<k%10;
			k/=10;
		}
		cout<<endl;

	}

	return 0;
}
