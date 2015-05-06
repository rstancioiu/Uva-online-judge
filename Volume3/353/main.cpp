//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/3/353.html
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> listOfPalindromes;

bool checkPalindrome(string s,int i,int j)
{
	int t1=i;
	int t2=j;
	for(;t1<t2;t1++,t2--)
	{
		if(s[t1]!=s[t2])
		{
			return false;
		}
	}
	string t="";
	for(int k=i;k<=j;++k)
	{
		t+=s[k];
	}
	vector<string>::iterator it = find(listOfPalindromes.begin(),listOfPalindromes.end(),t);
	if(it==listOfPalindromes.end())
	{
		listOfPalindromes.push_back(t);
		return true;
	}
	else return false;
}



int main()
{
	string s;
	while(cin>>s)
	{
		int count=0;
		for(int i=0;i<s.length();++i)
		{
			for(int j=i;j<s.length();++j)
			{
			   if(checkPalindrome(s,i,j))
			   		count++;
			}
		}
		cout<<"The string '"<<s<<"' contains "<<count<<" palindromes."<<endl;
		listOfPalindromes.clear();
	}
	return 0;
}