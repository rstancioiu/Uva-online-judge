#include <bits/stdc++.h>

using namespace std;
string s;
string encoded;
string decoded;

string Decode(string s)
{
	string res="";
	int n;
	int t=1;
	for(int i=0;i<s.length();++i)
	{
		n+=t*(s[i]-'0');
		t*=10;
		if(n>=32)
		{
			res+=char(n);
			n=0;
			t=1;
		}
	}
	return res;
}

string Encode(string s)
{
	string res="";
	int n;
	for(int i=0;i<s.length();++i)
	{
		n=s[i];
		while(n!=0)
		{
			res+='0'+n%10;
			n/=10;
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(getline(cin,s))
	{
		if(s[0]>='0' && s[0]<='9')
		{
			cout<<Decode(s)<<endl;
		}
		else cout<<Encode(s)<<endl;
	}
	return 0;
}