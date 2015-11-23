#include <bits/stdc++.h>

using namespace std;
map<string,int> m;
string s;
int t,n;

int main()
{
	freopen("pufu.in","r",stdin);
	freopen("pufu.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		while(n--)
		{
			cin>>s;
			m[s]++;
		}
		cout<<m["ciocolata"]<<" "<<m["cascaval"]<<" "<<m["sare"]<<"\n";
		m.clear();
	}
	return 0;
}