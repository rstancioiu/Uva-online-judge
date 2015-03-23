#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdio>

using namespace std;
int used[32];
vector<int> arcs[32];
int visited[32];

inline unsigned int min(unsigned int a,unsigned int b)
{
	return (a>b) ? b : a;  
}

inline unsigned int max(unsigned int a,unsigned int b)
{
	return (a>b) ? a:b;
}

void compare(string a, string b)
{
	unsigned int minimum=min(a.length(),b.length());
	unsigned int i;
	for(int t=0;t<b.length();++t)
	{
		if(!used[b[t]-'A'])
		{
			used[b[t]-'A']=1;
		}
	}
	for(i=0;i<minimum;++i)
	{
		if(a[i]!=b[i])
			break;
	}
	if(i!=minimum)
	{
		arcs[a[i]-'A'].push_back(b[i]-'A');
	}
}

void Read()
{
	for(int i=0;i<=30;++i)
	{
		used[i]=0;
	}
	//freopen("test.txt","r",stdin);
	string s1="";
	string s2="";
	cin>>s2;
	while(s2!="#")
	{
		compare(s1,s2);
		s1=s2;
		cin>>s2;
	}
}

void topologicalSortUtil(int k,stack<int> &lifo)
{
	visited[k]=1;

	vector<int>::iterator it;
	for(it=arcs[k].begin();it!=arcs[k].end();++it)
	{
		if(visited[*it] == 0)
		{
			topologicalSortUtil(*it,lifo);
		}
	}

	lifo.push(k);
}

void TopologicalSort()
{
	stack<int> lifo;
	for(int i=0;i<=26;++i)
	{
		if(used[i])
		{
			visited[i]=0;
		}
		else
		{
			visited[i]=-1;
		}
	}
	for(int i=0;i<=26;++i)
	{
		if(visited[i]==0)
			topologicalSortUtil(i,lifo);
	}

	while(!lifo.empty())
	{
		cout<<(char)(lifo.top()+'A');
		lifo.pop();
	}
	cout<<endl;
}

int main()
{
	Read();
	TopologicalSort();
	return 0;
}