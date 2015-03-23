#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> fibo;
int n,t;

string add(string a,string b)
{
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int t=0;
	string c="";
	for(int i=0;i<a.length() || i<b.length() || t!=0;i++,t/=10)
	{
		if(i<a.length() && i<b.length())
		{
			t+=a[i]-'0' + b[i] - '0';
			c+=t%10+'0';
		}
		else if(i<a.length() && i>=b.length())
		{
			t+=a[i]-'0';
			c+=t%10+'0';
		}
		else if(i>=a.length() && i<b.length())
		{
			t+=b[i]-'0';
			c+=t%10+'0';
		}
		else
		{
			c+=t%10+'0';
		}
	}
	reverse(c.begin(),c.end());
	return c;
}

int main()
{
	fibo.push_back("0");
	fibo.push_back("1");
	fibo.push_back("1");
	n=2;
	while(cin>>t)
	{
		if(t>n)
		{
			for(int i=n+1;i<=t;++i)
			{
				fibo.push_back(add(fibo[i-1],fibo[i-2]));
			}
			n=t;
		}
		cout<<fibo[t]<<endl;
	}
	return 0;
}