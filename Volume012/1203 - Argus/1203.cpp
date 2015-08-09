#include <bits/stdc++.h>

using namespace std;
priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int> >,greater<pair<pair<int,int>,int> > > Q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int k,id,val,dif;
	while(cin>>s && s!="#")
	{
		cin>>id>>val;
		Q.push(make_pair(make_pair(val,id),val));
	}
	cin>>k;
	while(k--)
	{
		id=Q.top().first.second;
		val=Q.top().first.first;
		dif=Q.top().second;
		cout<<id<<endl;
		Q.pop();
		Q.push(make_pair(make_pair(val+dif,id),dif));
	}
	return 0;
}