#include <iostream>
#define INF 0x1f1f1f1f

using namespace std;


int main()
{
	long long int x,y,n;
	while(cin>>n && n!=0)
	{
		bool solfound = false;
		x=1;
		long long int resx=0;
		long long int resy=INF;
		for(;3*x*x-3*x+1<=n;++x)
		{
			for(y=1;y<x;++y)
			{
				if(n==x*x*x-y*y*y)
				{
					if(y<resy)
					{
						resx=x;
						resy=y;
					}
					solfound=true;
				}
			}
		}

		if(!solfound)
			cout<<"No solution"<<endl;
		else
			cout<<resx<<" "<<resy<<endl;

	}
	return 0;
}