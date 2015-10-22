#include <bits/stdc++.h>
#define N 400100

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int MIN(int a,int b){return (a<b)?a:b;}
inline int ABS(int a){return (a>0)?a:-a;}

typedef long long ll;
ll n,m;
int t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int i=0;i<t;++i)
	{
		cin>>n>>m;
		if(m>n)
			cout<<0<<endl;
		else
		{
			ll a=(m+1)/2+(n-m)-1;
			ll d1=n-m,d2=a-n+m;
			ll cnt1=0,cnt2=0,cnt3=0;
			for(ll i=2;i<=a;i*=2)
			{
				cnt1+=a/i;
				cnt2+=d1/i;
				cnt3+=d2/i;
			}
			if(cnt1>cnt2+cnt3)
				cout<<0<<endl;
			else
				cout<<1<<endl;
		}
	}
	return 0;
}