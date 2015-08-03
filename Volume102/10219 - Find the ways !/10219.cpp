#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	while(cin>>n>>k)
	{
		double ans=0;
		int t=n-k;
		for(int i=1;i<=k;++i)
		{
			ans+=log10(t+i)-log10(i);
		}
		cout<<(int)ans+1<<endl;
	}
	return 0;
}
