#include <bits/stdc++.h>

using namespace std;
long long n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c=1;
	while(cin>>n && n!=0)
	{
		n<<=1;
		long long k = sqrt(n);
		for(int i=0;;++i)
		{
			long long a =k+i;
			if(a*(a-3)>=n)
			{
				cout<<"Case "<<c++<<": "<<a<<"\n";
				break;
			}
		}
	}
	return 0;
}