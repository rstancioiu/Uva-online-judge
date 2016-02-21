#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n && n>=0)
	{
		ll f=1;
		ll m=0;
		for(int i=0;i<n;++i)
		{
			ll tmp = f;
			f = m+1;
			m = tmp+m;
		}
		cout<<m<<" "<<m+f<<endl;
	}
}