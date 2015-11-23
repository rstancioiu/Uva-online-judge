#include <bits/stdc++.h>
#define N 16
#define MAX 50000

using namespace std;
int t,n,ans,g,a,b;
int p[N];
double d;

int gcd(int a,int b)
{
	while(b!=0)
	{
		int aux=a%b;
		a=b;
		b=aux;
	}
	return a;
}

int main()
{
	freopen("pufarina.in","r",stdin);
	freopen("pufarina.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d.%d",&a,&b);
			p[i]=a*1000+b;
		}
		g=p[0];
		for(int i=1;i<n;++i)
			g=gcd(g,p[i]);
		ans=0;
		for(int i=0;i<n;++i)
			ans+=p[i]/g;
		if(ans>MAX)
			cout<<"ALEGERI FRAUDATE\n";
		else
			cout<<ans<<"\n";
	}
	return 0;
}