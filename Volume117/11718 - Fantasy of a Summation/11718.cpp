#include <bits/stdc++.h>

using namespace std;
int t;
unsigned int n,k,m,a;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>n>>k>>m;
		unsigned int ans=0;
		for(int j=0;j<n;++j)
		{
			cin>>a;
			ans=(ans+a)%m;
		}
	    int p=1;
        k--;
		for(int j=0;j<31 && (1<<j)<=k;++j)
		{
			if(k&(1<<j))
			{
				p=(p*n)%m;
			}
			n=(n*n)%m;
		}
		ans=(((ans*p)%m)*((k+1)%m))%m;
		cout<<"Case "<<i<<": "<<ans<<endl;
	}
	return 0;
}
