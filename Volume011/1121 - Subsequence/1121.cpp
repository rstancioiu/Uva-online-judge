#include <bits/stdc++.h>
#define N 100100

using namespace std;
typedef long long ll;
inline ll MIN(ll a,ll b){return (a>b)?b:a;}
ll n,s;
ll a[N];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>s)
	{
		for(int i=0;i<n;++i)
			cin>>a[i];
		ll sumaux=0;
		ll j=0;
		ll ans=n+1;
		for(int i=0;i<n;++i)
		{
			sumaux+=a[i];
			if(sumaux>=s)
			{
				while(sumaux-a[j]>=s && i!=j)
				{
					sumaux-=a[j];
					j++;
				}
				ans=MIN(ans,i-j+1);
			}
		}
		if(ans==n+1)
			cout<<0<<"\n";
		else
			cout<<ans<<"\n";
	}
	return 0;
}