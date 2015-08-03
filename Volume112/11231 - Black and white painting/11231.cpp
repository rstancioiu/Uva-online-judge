#include <bits/stdc++.h>

using namespace std;
int n,m,t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>m>>t && !(n==0 && m==0 && t==0))
	{
		if(n<=7 || m<=7)
		{
			cout<<0<<endl;
			continue;
		}
		int ans=(n-7)*(m-7);
		if(ans%2==0 || !t)
		{
			cout<<ans/2<<endl;
		}
		else cout<<ans/2+1<<endl;
	}

	return 0;
}
