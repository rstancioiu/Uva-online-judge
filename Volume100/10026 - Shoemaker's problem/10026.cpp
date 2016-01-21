#include <bits/stdc++.h>

using namespace std;

struct Job{
	int s,t,pos;
	Job(int s,int t,int pos): s(s),t(t),pos(pos) {}
};
vector<Job> tab;
int T,n;
int t,s;

bool compare(Job a, Job b)
{
	if(a.t*b.s==b.t*a.s)
		return (a.pos<b.pos);
	else
		return (a.t*b.s<b.t*a.s);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	int c=0;
	while(T--)
	{
		if(c++)
			cout<<"\n";
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>t>>s;
			Job new_job(s,t,i+1);
			tab.push_back(new_job);
		}
		sort(tab.begin(),tab.end(),compare);
		for(int i=0;i<n-1;++i)
			cout<<tab[i].pos<<" ";
		cout<<tab[n-1].pos<<"\n";
		tab.clear();
	}

	return 0;
}