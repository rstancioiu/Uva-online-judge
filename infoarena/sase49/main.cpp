#include <bits/stdc++.h>
#define N 33
#define M 49

using namespace std;
int tab[N];
int t,a;

int main()
{
	freopen("sase49.in","r",stdin);
	freopen("sase49.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		for(int i=0;i<N;++i)
			tab[i]=0;
		for(int i=0;i<M;++i)
		{
			cin>>a;
			tab[a]++;
		}
		int ans=1;
		for(int i=16;i>=1;--i)
		{
			int cnt=0;
			for(int j=1;i*j<=16;j++)
				cnt+=tab[i*j];
			if(cnt>=6)
			{
				ans=i;
				break;
			}
		}
		cout<<ans<<"\n";
		int cnt=0;
		for(int i=1;cnt<6;)
		{
			if(tab[i*ans])
			{
				cout<<i*ans<<" ";
				cnt++;
				tab[i*ans]--;
			}
			if(!tab[i*ans])
				++i;
		}
		cout<<"\n";
	}
	return 0;
}