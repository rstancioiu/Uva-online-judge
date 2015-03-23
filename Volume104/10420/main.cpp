#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <utility>

using namespace std;

map<string,int> m;

int main()
{
	map<string,int>::iterator it;
	int n;
	cin>>n;
	string s,country;
	getline(cin,s);
	for(int i=0;i<n;++i)
	{
		getline(cin,s);
		istringstream iss(s);
		iss>>country;
		it=m.find(country);
		if(it!=m.end())
		{
			it->second++;
		}
		else
		{
			m.insert(make_pair(country,1));
		}
	}
	for(it=m.begin();it!=m.end();++it)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}