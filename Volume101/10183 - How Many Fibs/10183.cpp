// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/101/10183.html
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

vector<string> fibo;

string add(string a,string b)
{
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string res="";
	int t=0;
	for(int i=0;i<a.length() || i<b.length() || t;++i,t/=10)
	{
		if(i<a.length() && i<b.length())
		{
			t=t+ (a[i]-'0') + (b[i]-'0');
			res+=t%10+'0';
		}
		else if(i<a.length())
		{
			t=t+ (a[i]-'0');
			res+=t%10+'0';
		}
		else if(i<b.length())
		{
			t=t+ (b[i]-'0');
			res+=t%10+'0';
		}
		else
		{
			res+=t%10+'0';
		}
	}
	reverse(res.begin(),res.end());
	return res;
}

bool compare(string a,string b)
{
	if(a.length()>b.length())
		return true;
	else if(a.length()<b.length())
		return false;
	else return a>b;
}


int main()
{
	string a="1";
	string b="2";
	fibo.push_back(a);
	fibo.push_back(b);
	while(b.length()<101)
	{
		string aux=b;
		b=add(a,b);
		a=aux;
		fibo.push_back(b);
	}
	while(cin>>a>>b && !(a=="0" && b=="0"))
	{
		int i=0,j=0;
		for(;compare(a,fibo[i]);i++);
		for(;compare(b,fibo[j]) || b==fibo[j];j++);
		cout<<j-i<<endl;
	}
	return 0;
}