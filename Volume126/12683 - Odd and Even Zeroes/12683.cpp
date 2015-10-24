#include <bits/stdc++.h>
#define N 100100
#define M 26

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int MIN(int a,int b){return (a<b)?a:b;}
inline int ABS(int a){return (a>0)?a:-a;}
typedef long long ll;
ll n,p;
int a[M];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i=0;i<M;++i)
	{
		if(i==25)
			a[i]=16;
		else if(i>=20)
			a[i]=10+i-20+1;
		else if(i>=15)
			a[i]=10;
		else if(i>=10)
			a[i]=6+i-10;
		else if(i>=5)
			a[i]=5;
		else a[i]=i+1;
	}
	while(cin>>n && n!=-1)
	{
		bool state=true;
		ll ans=0;
		if(n<=25)
			cout<<a[n]<<"\n";
		else
		{
		while(n>25)
		{
			ll p=1;
			ll cnt=0;
			int t=1;
			ll a=1;
			ll b=0;
			while(p*5<=n)
			{
				if(t%2==1)
					a*=5;
				else
					a=3*a+2*(p-a);
				
				cnt+=p;
				t++;
				p*=5;
			}
			if(state)
				ans+=a;
			else ans+=p-a;
			if(cnt%2==1)
				state=!state;
			n-=p;	
		}
		if(state)
			ans+=a[n];
		else
			ans+=n+1-a[n];
		cout<<ans<<endl;
	}
	}
	return 0;
}