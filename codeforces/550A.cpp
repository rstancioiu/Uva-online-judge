#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	int over=0;
	int ab=0;
	int ba=0;
	for(int i=0;i<s.length();++i)
	{
		if(s[i]=='A')
		{
			if(s[i+1]=='B')
				if(s[i+2]=='A')
				{
					over++;
					i+=2;
				}
				else
				{
					ab++;
					i++;
				}
		}
		else if(s[i]=='B')
		{
			if(s[i+1]=='A')
				if(s[i+2]=='B')
				{
					over++;
					i+=2;
				}
				else
				{
					ba++;
					i++;
				}
		}
	}
	if((ab>=1 && (ba>=1 || over>=1))||(ba>=1 && (over>=1||ab>=1))||over>=2)
	{
		cout<<"YES\n";
	}
	else cout<<"NO\n";
	return 0;

}