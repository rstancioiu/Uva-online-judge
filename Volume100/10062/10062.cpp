// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/100/10062.html
#include <iostream>
#include <string>
#include <set>
#include <vector>
#define N 128

using namespace std;
typedef pair<int,int> ii;

struct ltstr
{
  bool operator()( ii pr1, ii pr2) const
  {
     if(pr1.first>pr2.first)
     	return true;
     else if(pr1.first<pr2.first)
     	return false;
     else return (pr1.second<pr2.second);
  }
};
vector<int> freq(N,0);
set<pair<int,int>,ltstr > res;

int main()
{
	string s;
	int t=0;
	while(getline(cin,s))
	{
		if(t++)
			cout<<endl;
		for(int i=0;i<N;++i)
			freq[i]=0;
		for(int i=0;i<s.length();++i)
		{
			freq[s[i]]++;
		}
		for(int i=0;i<N;++i)
		{
			if(freq[i]!=0)
			{
				res.insert(make_pair(freq[i],i));
			}
		}
		set<pair<int,int> >::reverse_iterator it;
		for(it=res.rbegin();it!=res.rend();++it)
		{
			cout<<it->second<<" "<<it->first<<endl;
		}
		res.clear();
	}
}