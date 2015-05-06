#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> id;
vector<int> visited;
map<int,vector<int> > graph;
stack<pair<int,int> order;
int n,m;


void TopologicalSortUtil(int s,int level)
{
	map<int,vector<int> >::iterator it=graph.find(s);
	visited[s]=1;
	vector<int>::iterator i;
	for(i=it->second.begin();i!=it->second.end();++i)
	{
		if(!visited[*i])
			TopologicalSortUtil(*i,level+1);
	}
	order.push(make_pair(s,level));
}

void TopologicalSort()
{
	map<int,vector<int> >::iterator it;
	for(it=graph.begin();it!=graph.end();++it)
	{
		if(!visited[it->first])
			TopologicalSortUtil(it->first);
	}
	while(!order.empty())
	{

		cout<<" "<<id[order.top()];
		order.pop();
	}
	cout<<"."<<endl<<endl;
}


int main()
{
	string s,a,b;
	int count=0;
	while(cin>>n)
	{
		count++;
		for(int i=0;i<n;++i)
		{
			vector<int> v;
		 	cin>>s;
		 	id.push_back(s);
		 	visited.push_back(0);
		 	graph.insert(make_pair(i,v));
		}
		cin>>m;
		for(int i=0;i<m;++i)
		{
			cin>>a>>b;
			vector<string>::iterator ita=find(id.begin(),id.end(),a);
			vector<string>::iterator itb=find(id.begin(),id.end(),b);
			graph[ita-id.begin()].push_back(itb-id.begin());
		}

		cout<<"Case #"<<count<<": Dilbert should drink beverages in this order:";
		TopologicalSort();
		graph.clear();
	}
}