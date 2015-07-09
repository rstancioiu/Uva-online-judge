// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/108/10883.html
#include <bits/stdc++.h>
#define EPS 1e-6


using namespace std;
int t,n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
    double a;
	for(int j=1;j<=t;++j)
	{
		cin>>n;
		double ans=0;
		double p=0;
		for(int i=0;i<n;++i)
		{
			cin>>a;
			ans=ans+exp(p-(n-1)*log(2))*a;
			p=p+log(n-i-1)-log(i+1);
		}
		cout<<"Case #"<<j<<": "<<fixed<<setprecision(3)<<ans<<endl;
	}
	return 0;
}
