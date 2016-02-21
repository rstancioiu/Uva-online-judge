#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
vector<iii> tab;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	int c=1;
	while(cin>>a>>b)
		tab.push_back(make_pair(ii(a,b),c++));
	sort(tab.begin(),tab.end());
	vector<int> pre(tab.size(),0);
	vector<int> cnt(tab.size(),0);
	for(int i=0;i<tab.size();++i)
	{
		int maximum = 1;
		int pos = i;
		for(int j=0;j<i;++j)
		{
			if(tab[i].X.X>tab[j].X.X && tab[i].X.Y<tab[j].X.Y && cnt[j]>=maximum)
			{
				maximum=cnt[j]+1;
				pos = j;
			}
		}
		cnt[i]=maximum;
		pre[i]=pos;
	}
	vector<int> ans;
	int maximum=0;
	int pos=0;
	for(int i=0;i<tab.size();++i)
	{
		if(maximum<=cnt[i])
		{
			maximum=cnt[i];
			pos=i;
		}
	}
	while(pos!=pre[pos])
	{
		ans.push_back(tab[pos].Y);
		pos=pre[pos];
	}
	ans.push_back(tab[pos].Y);
	cout<<ans.size()<<"\n";
	for(int i=ans.size()-1;i>=0;--i)
		cout<<ans[i]<<"\n";
	return 0;
}