#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string s;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>s && s[0]!='-')
	{
		if(s[0]=='0')
		{
			ll number=0;
			for(int i = 2;i<s.length();++i)
			{
				if(s[i]>='0' && s[i]<='9')
					number=16*number+s[i]-'0';
				else if(s[i]>='A' && s[i]<='F')
					number=16*number+s[i]-'A'+10;
				else if(s[i]>='a' && s[i]<='f')
					number=16*number+s[i]-'a'+10;
			}
			cout<<number<<endl;
		}
		else
		{
			istringstream iss(s);
			ll t;
			iss>>t;
			s = "";
			while(t!=0)
			{
				int p = t%16;
				if(p<=9)
					s+='0'+p;
				else
					s+='A'+p-10;
				t/=16;
			}
			reverse(s.begin(),s.end());
			cout<<"0x"<<s<<endl;
		}
	}

	return 0;
}