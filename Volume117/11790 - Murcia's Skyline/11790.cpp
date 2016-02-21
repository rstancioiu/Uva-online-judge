#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
inline ll MAX(ll a,ll b){return (a>b)?a:b;}

int t,n;
vector<pll> tab;
vector<pll> com;

ll A,B;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int c=1;c<=t;++c)
	{
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>A;
			tab.push_back(pll(A,0));
		}
		for(int i=0;i<n;++i)
		{
			cin>>tab[i].Y;
		}
		for(int i=0;i<n;++i)
		{
			com.push_back(pll(tab[i].Y,tab[i].Y));
			for(int j=0;j<i;++j)
			{
				if(tab[j].X<tab[i].X)
				{
					com[i].X=MAX(com[i].X,tab[i].Y+com[j].X);
				}
				else if(tab[j].X>tab[i].X)
				{
					com[i].Y=MAX(com[i].Y,tab[i].Y+com[j].Y);
				}
			}
		}
		A = com[0].X;
		B = com[0].Y;
		for(int i=0;i<n;++i)
		{
			A = MAX(A,com[i].X);
			B = MAX(B,com[i].Y);
		}
		if(A>=B)
			cout<<"Case "<<c<<". Increasing ("<<A<<"). Decreasing ("<<B<<").\n";
		else
			cout<<"Case "<<c<<". Decreasing ("<<B<<"). Increasing ("<<A<<").\n";
		tab.clear();
		com.clear();
	}

	return 0;
}