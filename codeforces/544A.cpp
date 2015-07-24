#include <cstdio>
#include <iostream>
#include <string>
#define N 26
#define NS 128

using namespace std;
string s;
int k;
int tab[N]={0};
string t[N];


int main()
{
	cin>>k;
	cin>>s;
	int count=0;
	for(int i=0;i<s.length();++i)
	{
		if(count<k)
		{
			if(tab[s[i]-'a'])
				t[count-1]+=s[i];
			else
			{	
				count++;
				t[count-1]=s[i];
				tab[s[i]-'a']=1;
			}
		}
		else
		{
			t[count-1]+=s[i];
		}
	}
	if(count==k)
	{
		cout<<"YES\n";
		for(int i=0;i<k;++i)
			cout<<t[i]<<endl;
	}
	else 
		cout<<"NO\n";
	return 0;
}