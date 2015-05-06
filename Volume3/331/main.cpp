//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/3/331.html
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;
vector<vector<int> > res;
int cnt;

vector<int> findSwaps(vector<int> v)
{
	vector<int>::iterator it;
	vector<int> swaps;
	int t=*(v.begin());
	int p=0;
	for(it=v.begin();it!=v.end();++it)
	{
		if((*it)<t)
		{	
			swaps.push_back(p-1);
		}
		t=*it;
		p++;
	}
	return swaps;
}

void back(vector<int> v,vector<int> t,int k)
{
	if(k != -1)
	{
		swap(v[k], v[k+1]);
		t[k]++;

	}
	vector<int>::iterator it;
	vector<int> swaps=findSwaps(v);
	if(!swaps.empty())
	{
		for(it=swaps.begin();it!=swaps.end();++it)
		{
			back(v,t,*it);
		}
	}
	else
	{
		cnt++;
	}
}


int main()
{
	string s;
	int n;
	int nb=0;
	while(1)
	{
		nb++;
		res.clear();
		cin>>n;
		cnt=0;
		if(n==0)
			break;
		vector<int> v;
		vector<int> aux;
		int t;
		for(int i=0;i<n;++i)
		{
			cin>>t;
			v.push_back(t);
			aux.push_back(0);
		}
		vector<int> swaps=findSwaps(v);
		if(!swaps.empty())  back(v,aux,-1);
		cout<<"There are "<<cnt<<" swap maps for input data set "<<nb<<"."<<endl;
	}
}