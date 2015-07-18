// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/100/10019.html
#include <iostream>

using namespace std;

int main()
{
	int n,c,m,b1,b2;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>m;
		b1=0;
		b2=0;
		for(int i=0;(1<<i)<=m;++i)
		{
			if(m&(1<<i))
			{
				b1++;
			}
		}
		while(m!=0)
		{
			c=m%10;
			for(int i=0;(i<<1)<=c;++i)
			{
				if(c&(1<<i))
					b2++;
			}
			m/=10;
		}
		cout<<b1<<" "<<b2<<endl;
	}

	return 0;
}