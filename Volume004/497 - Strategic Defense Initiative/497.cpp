#include <bits/stdc++.h>

using namespace std;
vector<int> tab;
string s;
int t,a;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	getline(cin,s);
	istringstream iss(s);
	iss>>t;
	getline(cin,s);
	int c=0;
	while(t--)
	{
		if(c++) cout<<"\n";
		while(getline(cin,s) && s!="")
		{
			istringstream iss(s);
			iss>>a;
			tab.push_back(a);
		}
		vector<int> pre(tab.size(),0);
		vector<int> cnt(tab.size(),0);
		for(int i=0;i<tab.size();++i)
		{
			int maximum = 1;
			int pos = i;
			for(int j=0;j<i;++j)
			{
				if(maximum<=cnt[j] && tab[i]>tab[j])
				{
					maximum = cnt[j]+1;
					pos = j;
				}
			}
			pre[i]=pos;
			cnt[i]=maximum;
		}
		vector<int> ans;
		int maximum = 0;
		int pos = 0;
		for(int i=0;i<tab.size();++i)
		{
			if(cnt[i]>maximum)
			{
				maximum=cnt[i];
				pos=i;
			}
		}
		while(pos!=pre[pos])
		{
			ans.push_back(tab[pos]);
			pos=pre[pos];
		}	
		ans.push_back(tab[pos]);
		cout<<"Max hits: "<<ans.size()<<"\n";
		for(int i=ans.size()-1;i>=0;--i)
		cout<<ans[i]<<"\n";
		tab.clear();
	}
	return 0;
}