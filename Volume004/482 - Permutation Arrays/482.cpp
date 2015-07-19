// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/4/482.html
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <string>
#include <sstream>

using namespace std;

int main()
{

	int t;
	string s;
	getline(cin,s);
	istringstream iss(s);
	iss>>t;
	int z=0;
	while(t--)
	{
		if(z++) cout<<endl;
		getline(cin,s);
		map<int,string> res;
		vector<int> pos;
		getline(cin,s);
		istringstream iss1(s);
		int n;
		string p;
		while(iss1>>n)
		{
			pos.push_back(n);
		}
		int i=0;
		getline(cin,s);
		istringstream iss2(s);
		while(iss2>>p)
		{
			res.insert(make_pair(pos[i++],p));
		}
		map<int,string>::iterator it;
		for(it = res.begin();it!=res.end();++it)
		{
			cout<<it->second<<endl;
		}
	}
	return 0;
}