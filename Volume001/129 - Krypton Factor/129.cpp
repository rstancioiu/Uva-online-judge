#include <bits/stdc++.h>
#define N 84

using namespace std;
int n,l;
int vis[N]={0};
int cnt=0;
bool found=false;

void backtrack(int i,int l)
{
	if(cnt==n)
	{
		for(int j=1;j<i;++j)
		{
			cout<<(char)(vis[j]+'A');
			if(j%64==0)
				cout<<"\n";
			else if(j%4==0 && j!=i-1)
				cout<<" ";
		}
		cout<<"\n";
		cout<<i-1<<"\n";
		found=true;
		return;
	}
	for(int j=0;j<l;++j)
	{
		vis[i]=j;
		int k;
		for(k=1;2*k<=i;k++)
		{
			int t;
			for(t=0;t<k;++t)
				if(vis[i-t]!=vis[i-t-k])
					break;
			if(t==k)
				break;
		}
		if(2*k>i)
		{
			cnt++;
			backtrack(i+1,l);
		}
		if(found)
			return;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>l && !(n==0 && l==0))
	{
		cnt=0;
		found=false;
		backtrack(1,l);
	}
	return 0;
}