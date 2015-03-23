#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <utility>
#include <algorithm>
#define N 1024
#define INF 0x1f1f1f1f

using namespace std;

vector<string> v;
vector<int> b[N];
int cnt;
int p;
int n,t;
vector<int> res;

bool findmax()
{
	vector<int> vt;
	for(int k=0;k<=n;++k)
		vt.push_back(0);
	for(int i=1;i<=p;++i)
	{
		vt[*(b[i].begin())]++;
	}
	int cnt=0;
	int max=0;
	for(int i=1;i<=n;++i)
	{
		if(max<vt[i])
		{
			cnt=1;
			res.clear();
			max=vt[i];
			res.push_back(i);
		}
		else if(max==vt[i])
		{
			cnt++;
			res.push_back(i);
		}
	}
	if(cnt*max==p)
		return true;
	else 
	{
		vector<int> aux;
		int min=INF;
		for(int i=1;i<=n;++i)
		{
			if(vt[i]==min)
				aux.push_back(i);
			else if(vt[i]<min && vt[i]!=0)
			{
				aux.clear();
				min=vt[i];
				aux.push_back(i);
			}
		}
		vector<int>::iterator it,it1;		
		for(int i=1;i<=p;++i)
		{
			for(it=aux.begin();it!=aux.end();++it)
			{
				it1=find(b[i].begin(),b[i].end(),*it);
				b[i].erase(it1);
			}
		}
		return false;
	}
}

int main()
{
	string s;
	getline(cin,s);
	istringstream iss(s);
	iss>>t;
	getline(cin,s);
	int nb=0;
	while(t--)
	{
		getline(cin,s);
		istringstream iss(s);
		iss>>n;
		cnt=n;
		v.clear();
		for(int i=0;i<n;++i)
		{
			string s;
			getline(cin,s);
			b[i].clear();
			v.push_back(s);	
		}
		p=0;
		res.clear();
		if(nb++)
			cout<<endl;
		while(1)
		{
			int a;
			string s="";
			getline(cin,s);
			istringstream iss(s);
			if(s.empty() || !(iss>>a) || cin.eof())
				break;
			p++;
			for(int i=0;i<n-1;++i)
			{
				b[p].push_back(a);		
				iss>>a;
			}
			b[p].push_back(a);	
		}
		while(1)
		{
			bool boolean = findmax();
			if(boolean == true)
				break;
		}
		vector<int>::iterator it;
		for(it=res.begin();it!=res.end();++it)
		{
			cout<<v[(*it)-1]<<endl;
		}
		for(int i=1;i<=p;++i)
		{
			b[i].clear();
		}
	}
	return 0;
}