#include <bits/stdc++.h>
#define N 200005

using namespace std;
inline int MIN(int a,int b){return (a>b)?b:a;}
inline int MAX(int a,int b){return (a>b)?a:b;}
int ans[N]={0};
vector<pair<int,int> > tab;
set<pair<int,int> > order;
int n,a;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		tab.push_back(make_pair(a,i));
	}
	sort(tab.begin(),tab.end());
	order.insert(make_pair(0,0));
	order.insert(make_pair(n+1,0));
	for(int i=0;i<n;++i)
	{
		pair<set<pair<int,int> >::iterator, bool> res = order.insert(make_pair(tab[i].second,tab[i].first));
		set<pair<int,int> >::iterator right = res.first;
		right++;
		set<pair<int,int> >::iterator left = res.first;
		left--;
		int dif = right->first - left->first;
		ans[dif-1] = MAX(ans[dif-1],res.first->second);	
	}
	for(int i=n-1;i>0;--i)
	{
		ans[i]=MAX(ans[i+1],ans[i]);
	} 
	for(int i=1;i<n;++i)
		cout<<ans[i]<<" ";
	cout<<ans[n]<<endl;
	return 0;
}