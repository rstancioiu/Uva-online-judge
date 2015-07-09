// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/100/10008.html
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#define N 32

using namespace std;
vector<pair <int,char> > v;

bool function (pair<int,char> p1, pair<int,char> p2) 
{
	 if(p1.first > p2.first)
	 	return true;
	 else if(p1.first<p2.first)
	 	return false;
	 else 
	 	return (p1.second < p2.second) ? 1 : 0; 
}

int main()
{
	for(int i=0;i<=26;++i)
		v.push_back(make_pair(0,'A'+i));
	string s;
	int n;
	getline(cin,s);
	istringstream iss(s);
	iss>>n;
	for(int i=0;i<n;++i)
	{
		string s;
		getline(cin,s);
		for(int i=0;i<s.length();++i)
		{
			if(s[i]>='a'&& s[i]<='z')
				v[s[i]-'a'].first++;
			else if(s[i]>='A'&& s[i]<='Z')
				v[s[i]-'A'].first++;
		}
	}
	sort(v.begin(),v.end(),function);
	vector<pair<int,char> >::iterator it;
	for(it=v.begin();it!=v.end();++it)
	{
		if(it->first>0)
		{
			cout<<it->second<<" "<<it->first<<endl;
		}
	}
	return 0;
}