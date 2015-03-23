#include <iostream>
#include <cmath>

using namespace std;

long long int H(int n)
{
	if(n<=0)
		return 0;
	long long int res=0;
	int sqr=(int)sqrt(n);
	for(int i=1;i<=n/sqr;++i)
	{
		res+=n/i;
	}
	for(int k=sqr;k>=2;--k)
		res+=(k-1)*(n/(k-1)-n/k);
	return res;
}

int main()
{
	int t,a;
	cin>>t;
	while(t--)
	{
		cin>>a;
		cout<<H(a)<<endl;
	}
	return 0;
}