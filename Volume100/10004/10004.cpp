// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/100/10004.html
#include <iostream>
#include <vector>
#include <queue>
#define N 200

using namespace std;
vector<int> arcs[N];
int color[N];
int n;

bool bicolorUtil(int i,int clr)
{
	vector<int>::iterator it;
	for(it=arcs[i].begin();it!=arcs[i].end();++it)
	{
		if(color[*it]==clr)
			return false;
		else if(color[*it]==0)
		{
			color[*it]=-clr;
			bool boolean = bicolorUtil(*it,-clr);
			if(!boolean)
				return false;
		}
	}
	return true;
}

bool bicolor()
{
	for(int i=1;i<=n;++i)
	{
		if(color[i]==0)
		{
			color[i]=1;
			bool boolean = bicolorUtil(i,color[1]);
			if(!boolean)
				return false;
		}
	}
	return true;
}

int main()
{
	int l,a,b;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		cin>>l;
		for(int i=1;i<=n;++i)
		{
			arcs[i].clear();
			color[i]=0;
		}
		for(int i=1;i<=l;++i)
		{
			cin>>a>>b;
			arcs[a].push_back(b);
			arcs[b].push_back(a);
		}
		bool boolean = bicolor();
		if(boolean)
		{
			cout<<"BICOLORABLE."<<endl;
		}
		else cout<<"NOT BICOLORABLE."<<endl;

	}
	return 0;
}