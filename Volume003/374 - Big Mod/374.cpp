//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/3/374.html
#include <iostream>

using namespace std;

int main()
{
	unsigned long long int a,b,c;
	while(cin>>a>>b>>c)
	{
		unsigned long long int res=1;
		for(int i=0;(1<<i)<=b;++i)
		{
			if((1<<i)&b)
			{
				res*=a;
				res%=c;
			}
			a*=a;
			a%=c;
		}
		cout<<res<<endl;
	}
	return 0;
}