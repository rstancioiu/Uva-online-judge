#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <cstdio>

using namespace std;

map<int,int> mp;

int main()
{
	map<int,int>::iterator it;
	int t,k,m,p;
	char c;
	string s;
	cin>>t;
	getline(cin,s);
	while(t--)
	{
		cin>>k;
		getline(cin,s);
		for(int i=0;i<k;++i)
		{
			cin>>c;
			cin>>p;
			getline(cin,s);
			mp.insert(make_pair(c,p));
		}
		cin>>m;
		getline(cin,s);
		long long int sum=0;
		for(int i=0;i<m;++i)
		{
			getline(cin,s);
			for(int j=0;j<s.length();++j)
			{
				it=mp.find(s[j]);
				if(it!=mp.end())
					sum+=it->second;
			}
		}
		printf("%.2f$\n",(double)sum/100);
		mp.clear();
	}
	return 0;
}

