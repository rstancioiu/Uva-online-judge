//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/1/195.html
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
string s;
set<string>::iterator it;

struct lex_compare {
    int operator() (const string& a, const string& b) const{
	   string va=a;
	   string vb=b;
	   for(int i=0;i<va.length();++i)
	   {
	   		if(va[i]%32==vb[i]%32)
	   		{
	   			if(va[i]<vb[i])
	   				return 1;
	   			else if(va[i]>vb[i])
	   				return 0;
	   		}
	   		else if(va[i]%32 < vb[i]%32)
	   		{
	   			return 1;
	   		}
	   		else if(va[i]%32 > vb[i]%32)
	   		{
	   			return 0;
	   		}
	   }
	   return 0;
    }
};
set<string,lex_compare> anagrams;

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>s;
		sort(s.begin(),s.end());
		do
		{
			it=anagrams.find(s);
			if(it==anagrams.end())
				anagrams.insert(s);
		}while(next_permutation(s.begin(),s.end()));
		for(it=anagrams.begin();it!=anagrams.end();++it)
			cout<<*it<<endl;
		anagrams.clear();
	}
	return 0;
}


//Solution 2
/*
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

string s;

bool comp(const char &a, const char &b) {
    int delta = tolower(a) - tolower(b);
    return delta ? delta < 0 : a <b;
}
int main() {
    int T;
    cin>>T;
    while (T-- && cin >> s) {
        sort(s.begin(), s.end(), comp);
        do
            cout << s << endl;
        while (next_permutation(s.begin(), s.end(), comp));
    }
    return 0;
}
*/
