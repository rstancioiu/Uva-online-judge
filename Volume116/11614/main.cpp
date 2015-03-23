#include <iostream>
#include <cmath>

using namespace std;

long long int n,i,res;

int main()
{
	int t=0;
	cin>>t;
	while(t--)
	{
		cin>>n;
		i=(long long int) sqrt(n<<1);
		if(i*i+i>n*2)
			i--;
		cout<<i<<endl;
	}
	return 0;
}