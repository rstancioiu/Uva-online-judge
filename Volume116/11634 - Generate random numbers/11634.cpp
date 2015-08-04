#include <bits/stdc++.h>

using namespace std;
set<int> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n && n!=0)
	{
		while(v.find(n)==v.end())
		{
			v.insert(n);
			n*=n;
			n/=100;
			n%=10000;
		}
		cout<<v.size()<<endl;
		v.clear();
	}
	return 0;
}