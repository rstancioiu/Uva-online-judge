#include <bits/stdc++.h>
#define N 16

using namespace std;
int t;
int h,n;
int tab[N];

void generate(int h,int n,int cnt)
{
	if(h>n-cnt)
		return;
	if(cnt==n)
	{
		if(h==0)
		{
			for(int i=0;i<n;++i)
				cout<<tab[i];
			cout<<"\n";
		}
		return;
	}
	tab[cnt]=0;
	generate(h,n,cnt+1);
	if(h>0)
	{
		tab[cnt]=1;
		generate(h-1,n,cnt+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int i=0;i<t;++i)
	{
		if(i)
			cout<<"\n";
		cin>>n>>h;
		generate(h,n,0);
	}
	return 0;
}