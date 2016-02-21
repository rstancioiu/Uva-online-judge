#include <bits/stdc++.h>
#define LIMIT 1024

using namespace std;
int t,n;

int square_sum(int n)
{
	int sum=0;
	while(n!=0)
	{
		sum+=(n%10)*(n%10);
		n/=10;
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int c=1;c<=t;++c)
	{
		cin>>n;
		int p = square_sum(n);
		int k = p;
		int i=1;
		do
		{
			k = square_sum(k);
		}while(k!=1 && i++<LIMIT);
		if(k==1)
			cout<<"Case #"<<c<<": "<<n<<" is a Happy number.\n";
		else cout<<"Case #"<<c<<": "<<n<<" is an Unhappy number.\n"; 
	}

	return 0;
}