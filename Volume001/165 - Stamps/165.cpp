#include <bits/stdc++.h>
#define N 16
#define M 2048

using namespace std;
int h,k;
int tab[N];
int vis[M];
int best[N];
int answer;

void compute(int cnt)
{
	if(cnt==k)
	{
		int maximum = tab[k-1]*h;
		for(int i=0;i<maximum;++i)
			vis[i]=0;
		vector<int> occ;
		for(int i=0;i<k;++i)
		{
			occ.push_back(tab[i]);
			vis[tab[i]]=1;
		}
		for(int t=1;t<h;++t)
		{
			int n=occ.size();
			for(int i=0;i<n;++i)
			{
				for(int j=0;j<k;++j)
				{
					int p =occ[i]+tab[j];
					if(!vis[p])
					{
						vis[p]=1;
						occ.push_back(p);
					}
				}
			}
		}
		int i;
		for(i=1;i<=maximum;++i)
		{
			if(!vis[i])
				break;
		}
		i--;
		if(answer<i)
		{
			answer=i;
			for(int i=0;i<k;++i)
			{
				best[i]=tab[i];
			}
		}
		occ.clear();
		return;
	}
	int maximum = tab[cnt-1]*h+1;
	for(int i=tab[cnt-1]+1;i<=maximum;++i)
	{
		tab[cnt]=i;
		compute(cnt+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>h>>k && !(h==0 && k==0))
	{
		tab[0]=1;
		answer=0;
		compute(1);
		for(int i=0;i<k;++i)
			cout<<right<<setw(3)<<best[i];
		cout<<" ->";
		cout<<right<<setw(3)<<answer<<"\n";
	}

	return 0;
}