// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/4/499.html
#include <string>
#include <iostream>
#define N 26

using namespace std;

int upper[N];
int lower[N];
string s;

int main()
{
	while(getline(cin,s))
	{	
		for(int i=0;i<N;++i)
		{
			upper[i]=0;
			lower[i]=0;
		}
		for(int i=0;i<s.length();++i)
		{
			if(s[i]>='A' && s[i]<='Z')
				upper[s[i]-'A']++;
			if(s[i]>='a' && s[i]<='z')
				lower[s[i]-'a']++;
		}
		int maximum=0;
		for(int i=0;i<N;++i)
		{
			if(maximum<upper[i])
				maximum=upper[i];
			if(maximum<lower[i])
				maximum=lower[i];
		}
		for(int i=0;i<N;++i)
			if(maximum==upper[i])
				cout<<(char)('A'+i);
		for(int i=0;i<N;++i)
			if(maximum==lower[i])
				cout<<(char)('a'+i);
		cout<<" "<<maximum<<endl;
 	}		
	return 0;
}