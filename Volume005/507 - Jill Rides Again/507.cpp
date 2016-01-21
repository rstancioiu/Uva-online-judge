#include <bits/stdc++.h>
#define N 100100

using namespace std;
int tab[N];
int t,n,ans,x,y;

void solve()
{
	int maximum=-1;
	int sum=0;
	int j=0;
	x=y=0;
	for(int i=0;i<n-1;++i)
	{
		sum+=tab[i];
		if(sum<0) 
		{
			sum=0;
			j=i+1;
		}
		if(sum>maximum)
		{
			maximum=sum;
			x=j;
			y=i;
		}
		else if(sum==maximum && i-j>y-x)
		{
			x=j;
			y=i;
		}
	}
	x++,y++;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int c=1;c<=t;++c)
	{
		cin>>n;
		for(int i=0;i<n-1;++i)
			cin>>tab[i];
		solve();
		bool no_parts = true;
		for(int i=0;i<n-1;++i)
			if(tab[i]>=0)
				no_parts=false;
		if(no_parts)
			cout<<"Route "<<c<<" has no nice parts\n";
		else
			cout<<"The nicest part of route "<<c<<" is between stops "<<x<<" and "<<y+1<<"\n";
	}
	return 0;
}
