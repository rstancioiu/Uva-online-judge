#include <iostream>

using namespace std;

int main()
{
	int n,res;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		while(n!=n%10)
		{
			int t=0;
			while(n!=0)
			{
				t+=n%10;
				n/=10;
			}
			n=t;
		}
		cout<<n<<endl;
	}
	return 0;
}