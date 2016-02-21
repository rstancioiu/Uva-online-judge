#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int t,n,a;
vector<int> tab;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<ii> dir1(n,ii(0,0)); 
		for(int i=0;i<n;++i)
		{
			cin>>a;
			tab.push_back(a);
		}

		for(int i=n-1;i>=0;--i)
		{
			int minimum=1,maximum=1;		
			for(int j=i+1;j<n;++j)
			{
				if(tab[i]<tab[j])
					minimum = MAX(minimum,dir1[j].X+1);
				else if(tab[i]>tab[j])
					maximum = MAX(maximum,dir1[j].Y+1);
			}
			dir1[i].X=minimum;
			dir1[i].Y=maximum;
		}
		int ans=0;
		for(int i=0;i<n;++i)
		{
			ans = MAX(ans,dir1[i].X+dir1[i].Y-1);
		}
		tab.clear();
		cout<<ans<<"\n";
	}
	return 0;
}       






