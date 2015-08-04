#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	long long int n;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>n;
		long long int p=n*(n-1)/2;
		if(p%2==0)
			cout<<"Case "<<i<<": "<<p/2<<endl;
		else
			cout<<"Case "<<i<<": "<<p<<"/2"<<endl;
	}
	return 0;
}
