#include <bits/stdc++.h>

using namespace std;
int t;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	getline(cin,s);
	int c=0;
	while(t--)
	{
		getline(cin,s);
		getline(cin,s);
		if(c++) cout<<"\n";
		int p = s.length();
		for(int j=1;j<s.length();++j)
		{
			if(s.length()%j!=0)
				continue;
			int i=0;
			for(i=0;i+j<s.length();++i)
			{
				if(s[i]!=s[i+j])
					break;
			}
			if(i+j==s.length())
			{
				p=j;
				break;
			}
		}
		cout<<p<<"\n";
	}
}