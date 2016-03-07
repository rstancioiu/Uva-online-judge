#include <bits/stdc++.h>
#define N 100100

using namespace std;
typedef long long ll;
vector<ll> tab;
ll maximum;

void solve()
{
	maximum=0;
	ll sum=0;
	for(int i=0;i<tab.size();++i)
	{
		sum+=tab[i];
		if(sum<0) 
		{
			sum=0;
		}
		if(sum>maximum)
		{
			maximum=sum;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while(getline(cin,s))
	{
		istringstream iss(s);
		ll a;
		while(iss>>a)
		{
			tab.push_back(a);
		}
		solve();
		cout<<maximum<<"\n";
		tab.clear();
	}
	return 0;
}
