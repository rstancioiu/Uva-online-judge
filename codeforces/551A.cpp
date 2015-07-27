#include <bits/stdc++.h>
#define N 2048

using namespace std;
vector<pair<int,int> > pos;
int v[N]={0};
int n,a;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a;
		pos.push_back(make_pair(a,i));
	}
	sort(pos.begin(),pos.end());
	v[pos[n-1].second]=1;
	for(int i=n-2;i>=0;--i)
	{
		if(pos[i].first==pos[i+1].first)
			v[pos[i].second]=v[pos[i+1].second];
		else
		{
			v[pos[i].second]=n-i;
		}
	}
	for(int i=0;i<n-1;++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<v[n-1]<<endl;
	return 0;
}