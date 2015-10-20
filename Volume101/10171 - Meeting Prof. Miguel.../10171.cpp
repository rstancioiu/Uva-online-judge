#include <bits/stdc++.h>
#define N 26

using namespace std;
typedef pair<int,int> ii;
int d1[N],d2[N];
vector<ii> g1[N],g2[N];

void compute(int s,int* d,vector<ii>* g)
{
	queue<int> Q;
	int v[N];
	for(int i=0;i<N;++i)
	{
		d[i]=0x3f3f3f3f;
		v[i]=0;
	}
	Q.push(s);
	d[s]=0;
	v[s]=1;
	while(!Q.empty())
	{
		int t=Q.front();
		Q.pop();
		v[t]=0;
		for(int i=0;i<g[t].size();++i)
		{
			if(d[g[t][i].first]>d[t]+g[t][i].second)
			{
				d[g[t][i].first]=d[t]+g[t][i].second;
				if(!v[g[t][i].first])
				{
					Q.push(g[t][i].first);
					v[g[t][i].first]=1;
				}
			}
		}
	}
}

int n;
char ot,et,a,b;
int p;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n && n!=0)
	{
		for(int i=0;i<n;++i)
		{
			cin>>ot>>et>>a>>b>>p;
			if(ot=='Y')
			{
				g1[a-'A'].push_back(ii(b-'A',p));
				if(et=='B')
					g1[b-'A'].push_back(ii(a-'A',p));
			}
			else 
			{
				g2[a-'A'].push_back(ii(b-'A',p));
				if(et=='B')
					g2[b-'A'].push_back(ii(a-'A',p));
			}
		}
		cin>>a>>b;
		compute(a-'A',d1,g1);
		compute(b-'A',d2,g2);
		int minimum=0x7fffffff;
		for(int i=0;i<N;++i)
		{
			if(d1[i]!=0x3f3f3f3f && d2[i]!=0x3f3f3f3f)
			{
				if(d1[i]+d2[i]<minimum)
					minimum=d1[i]+d2[i];
			}
		}
		int cnt=0;
		if(minimum==0x7fffffff)
			cout<<"You will never meet.\n";
		else
		{
			cout<<minimum;
			for(int i=0;i<N;++i)
			{
				if(d1[i]+d2[i]==minimum)
				{
					cout<<" "<<char(i+'A');
				}
			}
			cout<<"\n";
		}
		for(int i=0;i<N;++i)
		{
			g1[i].clear();
			g2[i].clear();
		}
	}
	return 0;
}