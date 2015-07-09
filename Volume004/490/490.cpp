// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/4/490.html
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> v;
int maximum;

int main()
{
	ios::sync_with_stdio(false);
	string s;
	maximum=0;
	while(getline(cin,s))
	{
		if(maximum<s.length())
		{
			maximum=s.length();
		}
		v.push_back(s);
	}
	vector<string>::iterator it;
	for(int i=0;i<maximum;++i)
	{	
		for(it=v.end(),it--;it>=v.begin();--it)
		{
			if(i<(*it).length())
			{
				cout<<(*it)[i];
			}
			else cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}	