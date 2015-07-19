// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/9/924.html
#include <queue>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#define N 3000

using namespace std;
vector<int> friends[N];
int visited[N];
int empoyees,t;
int dayMax;
int maximum;

void Bfs(int a)
{
	map<int,int> dailyboom;
	vector<int>::iterator it;
	queue<int> fifo;
	for(int i=0;i<empoyees;++i)
	{
		visited[i]=-1;
	}
	visited[a]=0;
	fifo.push(a);
	while(!fifo.empty())
	{
		int p=fifo.front();
		fifo.pop();
		for(it=friends[p].begin();it!=friends[p].end();++it)
		{
			if(visited[*it]==-1)
			{
				visited[*it]=visited[p]+1;
				fifo.push(*it);
			}
		}
	}
	map<int,int>::iterator itm;
	dayMax=0;
	maximum=0;
	for(int i=0;i<empoyees;++i)
	{
		if(visited[i]>0)
		{
			itm=dailyboom.find(visited[i]);
			if(itm!=dailyboom.end())
			{
				itm->second++;
			}
			else
			{
				dailyboom.insert(make_pair(visited[i],1));
			}
		}
	}
	for(itm=dailyboom.begin();itm!=dailyboom.end();++itm)
	{
		if(itm->second>maximum)
		{
			maximum=itm->second;
			dayMax=itm->first;
		}
	}
	dailyboom.clear();
}


int main()
{
	dayMax=0;
	maximum=0;
	int n,a;
	cin>>empoyees;
	for(int i=0;i<empoyees;++i)
	{	
		cin>>n;
		for(int j=0;j<n;++j)
		{
			cin>>a;
			friends[i].push_back(a);
		}
	}
	cin>>t;
	while(t--)
	{
		cin>>a;
	 	Bfs(a);
	 	if(maximum!=0)
	 	{
	 		cout<<maximum<<" "<<dayMax<<endl; 
	 	}
	 	else cout<<maximum<<endl;
	}
	return 0;
}