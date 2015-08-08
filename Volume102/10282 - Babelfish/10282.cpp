#include <bits/stdc++.h>

using namespace std;
map<string,string> dict;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s,s1,s2;
	while(getline(cin,s) && s!="")
	{
		istringstream iss(s);
		iss>>s1>>s2;
		dict.insert(make_pair(s2,s1));
	}
	while(getline(cin,s))
	{
		map<string,string>::iterator it=dict.find(s);
		if(it==dict.end())
			cout<<"eh"<<endl;
		else cout<<it->second<<endl;
	}
	return 0;
}