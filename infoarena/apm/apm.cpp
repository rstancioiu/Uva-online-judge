#include <bits/stdc++.h>
#define N 200100
#define M 400100

using namespace std;
struct Edge
{
	int a,b,d;
	bool operator < (const Edge &E) const
	{
		return this->d <E.d;
	}
};
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int va[M],vb[M],ranks[M];
int c[N];
Edge e[M];
int n,m,a,b,d;

int Find(int x){
	int y=x;
	while(y!=c[y])
		y=c[y];
	while(x!=c[x])
	{
		int aux=c[x];
		c[x]=y;
		x=aux;
	}
	return y;
}

void Union(int x,int y)
{
	if(ranks[x]>ranks[y])
		c[x]=y;
	else
		c[y]=x;
	if(ranks[x]==ranks[y])
		ranks[y]++;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("apm.in","r",stdin);
	freopen("apm.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;++i)
	{
		cin>>e[i].a>>e[i].b>>e[i].d;
	}
	for(int i=1;i<=n;++i)
	{
		c[i]=i;
		ranks[i]=1;
	}
	sort(e,e+m);
	int sum=0;
	int cnt=0;
	for(int i=0;i<m;++i)
	{
		int a=e[i].a;
		int b=e[i].b;
		int t1=Find(a);
		int t2=Find(b);
		if(t1!=t2)
		{
			sum+=e[i].d;
			va[cnt]=a;
			vb[cnt]=b;
			cnt++;
			Union(t1,t2);
		}
	}
	cout<<sum<<"\n";
	cout<<cnt<<"\n";
	for(int i=0;i<cnt;++i)
		cout<<va[i]<<" "<<vb[i]<<"\n";
	return 0;
}