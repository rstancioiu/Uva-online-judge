#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int n;
	while(cin>>n)
	{
		long long int t=(n+1)/2;
		t*=t;
		cout<<(2*(t-1)-1)*3<<endl;
	}
	return 0;
}