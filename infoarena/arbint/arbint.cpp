#include <bits/stdc++.h>
#define N (1<<18)

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
int tab[N+1]={0};
int n,q,a,b,t;

int query(int node,int a,int b,int x,int y)
{
	if(a>=x && y>=b)
	{
		return tab[node];
	}
	int ret1=0,ret2=0;
	int middle=(a+b)/2;
	if(x<=middle)
		ret1=query(node*2,a,middle,x,y);
	if(y>middle)
		ret2=query(node*2+1,middle+1,b,x,y);
	return MAX(ret1,ret2);
}

void update(int node,int a,int b,int i,int val)
{
	if(a==b && b==i)
	{
		tab[node]=val;
		return;
	}
	int middle=(a+b)/2;
	if(i<=middle)
		update(2*node,a,middle,i,val);
	else
		update(2*node+1,middle+1,b,i,val);
	tab[node]=MAX(tab[2*node],tab[2*node+1]);
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("arbint.in","r",stdin);
	freopen("arbint.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		update(1,1,n,i,a);
	}
	for(int i=0;i<q;++i)
	{
		cin>>t>>a>>b;
		if(t)
			update(1,1,n,a,b);
		else
		{
			int ans=query(1,1,n,a,b);
			cout<<ans<<"\n";
		}
	}
	return 0;
}