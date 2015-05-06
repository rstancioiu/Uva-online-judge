//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/1/156.html
//Description: brute force algorithm
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

// Method that returns if words a and b are anagrams
bool checkAnagram(string a,string b)
{
	if(a.length()!=b.length())
		return false;
	vector<int> va;
	vector<int> vb;
	for(int i=0;i<32;++i)
	{
		va.push_back(0);
		vb.push_back(0);
	}
	for(int i=0;i<a.length();++i)
	{
		va[a[i]%32]++;
		vb[b[i]%32]++;
	}
	int j;
	for(j=0;j<32;++j)
	{
		if(va[j]!=vb[j])
			break;
	}
	if(j==32)
		return true;
	else return false;
}

int main()
{
	// the dictionnary of words
	map<string,int> dict;
	map<string,int>::iterator it;
	string s;
	for(;;)
	{
		cin>>s;
		if(s=="#")
			break;
		for(it=dict.begin();it!=dict.end();++it)
		{
			if(checkAnagram(s,it->first))
				break;
		}
		if(it!=dict.end())
			it->second=1;
		else
			dict.insert(make_pair(s,0));
	}
	// we write all the words that don't have anagrams in the domain
	for(it=dict.begin();it!=dict.end();++it)
	{
		if(it->second==0)
			cout<<it->first<<endl;
	}
	return 0;
}