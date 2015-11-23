#include <bits/stdc++.h>
#define N 100100
using namespace std;
int n,m,t,a,b;
int c[N];

int Find(int x){return (x==c[x])?x:Find(c[x]);}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("disjoint.in","r",stdin);
	freopen("disjoint.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		c[i]=i;
	for(int i=0;i<m;++i)
	{
		cin>>t>>a>>b;
		if(t==1)
		{
			int p1=Find(a);
			int p2=Find(b);
			c[p2]=p1;
		}
		else if(t==2)
		{
			int p1=Find(a);
			int p2=Find(b);
			if(p1==p2)
				cout<<"DA\n";
			else
				cout<<"NU\n";
		}
	}
	return 0;
}