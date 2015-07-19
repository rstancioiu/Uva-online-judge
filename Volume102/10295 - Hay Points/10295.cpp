// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/102/10295.html
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <utility>

using namespace std;
int n,m;
map<string,int> dict;


int main()
{
	int value;
	string s;
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		cin>>s>>value;
		dict.insert(make_pair(s,value));
	}
	long long int count=0;
	while(cin>>s)
	{
		if(s==".")
		{
			cout<<count<<endl;
			count=0;
		}
		else
		{
			map<string,int>::iterator it=dict.find(s);
			if(it!=dict.end())
			{
				count+=it->second;
			}
		}
	}
	return 0;
}