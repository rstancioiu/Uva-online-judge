#include <bits/stdc++.h>

using namespace std;

unsigned long long int a,b;
vector<unsigned long long int> tab;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>a>>b && !(a==0 && b==0))
	{
		cout<<b/5-a/5+1<<endl;
	}
	return 0;
}