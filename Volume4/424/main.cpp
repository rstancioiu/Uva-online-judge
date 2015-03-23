#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

inline unsigned int MAX(unsigned int a,unsigned int b)
{
	return (a>b)? a:b;
}

string add(string a,string b)
{
	string res="";
	int maximum = MAX(a.length(),b.length());
	int t=0;
	for(int i=0;i<maximum || t!=0;++i,t/=10)
	{
		if(i<a.length() && i<b.length())
		{
			t=t+(a[i]-'0')+(b[i]-'0');
			res+=(t%10)+'0';
		}
		else if(i>=a.length() && i<b.length())
		{
			t=t+(b[i]-'0');
			res+=(t%10)+'0';
		}
		else if(i>=b.length() && i<a.length())
		{
			t=t+(a[i]-'0');
			res+=(t%10)+'0';
		}
		else
		{
			res+=t%10+'0';
		}
	}
	return res;
}


int main()
{
	string s;
	string res="";
	while(cin>>s)
	{
		if(s=="0")
			break;
		reverse(s.begin(),s.end());
		res=add(res,s);
	}
	reverse(res.begin(),res.end());
	cout<<res<<endl;
	return 0;
}
