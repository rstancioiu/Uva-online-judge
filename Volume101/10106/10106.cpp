// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/101/10106.html
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string product(string a,string b)
{
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int n=a.length();
	int m=b.length();
	int t=0;
	string res="";
	int k=0;
	for(int i=0; i<n;++i)
	{
		t=0;
		for(int j=0;j<m || t!=0;++j,t/=10)
		{
			if(k>i+j && j<m)
			{
				t+=(res[i+j]-'0')+(a[i]-'0')*(b[j]-'0');
				res[j+i]=(t%10)+'0';
			}
			else if(j<m && k<=i+j)
			{
				k++;
				t+=(a[i]-'0')*(b[j]-'0');
				res+=(t%10)+'0';
			}
			else
			{
				k++;
				res+=(t%10)+'0';
			}
		}
	}
	reverse(res.begin(),res.end());
	return res;
}

int main()
{
	string s1,s2,res;
	while(cin>>s1)
	{
		cin>>s2;
		if(s1=="0" || s2=="0")
			cout<<"0"<<endl;
		else
		{
			res=product(s1,s2);
			cout<<res<<endl;
		}
	}
}