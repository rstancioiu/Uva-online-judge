#include <bits/stdc++.h>


using namespace std;
double a,b,c,d,p,n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(10);
	while(cin>>p>>a>>b>>c>>d>>n)
	{
		double ans=0;
		double current=0;
		int k=1;
		double minimum=p*(sin(a*k+b)+cos(c*k+d)+2);
		double maximum=minimum;
		for(k++;k<=n;++k)
		{
			double price=p*(sin(a*k+b)+cos(c*k+d)+2);
			if(price>=maximum)
            {
                maximum=price;
                minimum=price;
            }
            else if(price<minimum)
            {
                minimum=price;
                if(maximum-minimum>ans)
                    ans=maximum-minimum;
            }
		}
		if(maximum-minimum>ans)
            ans=maximum-minimum;
		cout<<ans<<endl;
	}
	return 0;
}
