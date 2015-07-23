#include <iostream>

using namespace std;

long long int n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	long long int sum=0;
	long long int prev=1;
	long long int p=10;
	long long int i=1;
	for(i=1;p<=n;++i)
	{
		sum+=i*(p-prev);
		prev=p;
		p*=10;
	}
	sum+=i*(n-prev+1);
	cout<<sum<<endl;
	return 0;
}