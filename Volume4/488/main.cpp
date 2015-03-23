#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t,a,f;
	cin>>t;
	int nb=0;
	while(t--)
	{
		if(nb++) cout<<endl;
		cin>>a;
		cin>>f;
		a%=10;
		for(int p=0;p<f;++p)
		{
			for(int i=1;i<=a;++i)
			{
				for(int j=0;j<i;++j)
					cout<<i;
				cout<<endl;
			}
			for(int i=a-1;i>=1;--i)
			{
				for(int j=0;j<i;++j)
					cout<<i;
				cout<<endl;
			}
			if(p<f-1) cout<<endl;
		}
	}
	return 0;
}