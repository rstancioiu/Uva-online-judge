#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll MAX(ll a,ll b){return (a>b)?a:b;}
ll MIN(ll a,ll b){return (a<b)?a:b;}
ll c;
string line;
vector<ll> w;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(getline(cin,line))
	{
		string s;
		istringstream iss(line);
		while(iss>>s)
		{
			ll a=0;
			for(int i=0;i<s.length();++i)
			{
				a=(a<<5)+s[i]-'a'+1;
			}
			w.push_back(a);
		}
		int n=w.size();
		c=0;
		bool loop=true;
		while(loop)
		{
			loop=false;
			for(int i=0;i<n;++i)
			{
				ll a=c/w[i];
				for(int j=i+1;j<n;++j)
				{
					ll b=c/w[j];
					if(a%n==b%n)
					{
						c=MIN((a+1)*w[i],(b+1)*w[j]);
						loop=true;
					}
				}
			}
		}
		cout<<line<<"\n";
		cout<<c<<"\n\n";
		w.clear();
	}
	return 0;

}