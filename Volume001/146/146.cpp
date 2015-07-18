//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/1/146.html
//Description: ad-hoc (usage of c++ library algorithm)
#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

// We use the method next_permutation from the library algorithm
int main()
{
	string s;
	while(cin>>s && s!="#")
	{
		if(next_permutation(s.begin(),s.end()))
			cout<<s<<endl;
		else
			cout<<"No Successor"<<endl;
	}
	return 0;
}