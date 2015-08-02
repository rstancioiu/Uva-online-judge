#include <bits/stdc++.h>

using namespace std;
string s1,s2;
string t="aeiouy";

int main()
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin>>c;
	while(c--)
	{	
		cin>>s1>>s2;
		if(s1.length()!=s2.length())
		{
			cout<<"No"<<endl;
			continue;
		}
		int i;
		for(i=0;i<s1.length();++i)
		{
			if(s1[i]!=s2[i])
			{
				int j;
				for(j=0;j<t.length();++j)
				{
					if(t[j]==s1[i])
						break;
				}
				if(j==t.length())
					break;
				for(j=0;j<t.length();++j)
					if(t[j]==s2[i])
						break;
				if(j==t.length())
					break;
			}
		}
		if(i==s1.length())
		{
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}

	return 0;
}