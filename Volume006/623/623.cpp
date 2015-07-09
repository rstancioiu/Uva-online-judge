// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/6/623.html
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> fact;

string product(string a,string b)
{
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string res="";
	int t=0;
	int k=0;
	int l=0;
	for(int i=0;i<a.length();++i)
	{
		t=0;
		k=i;
		for(int j=0;j<b.length()|| t!=0;++j,t/=10,k++)
		{
			if(j<b.length())
			{
				t+=(a[i]-'0')*(b[j]-'0');
				if(k>=l)
				{
					res+=t%10+'0';
					l++;
				}
				else
				{
					t+=res[k]-'0';
					res[k]=t%10+'0';
				}
			}
			else
			{
				if(k>=l)
				{
					res+=t%10+'0';
					l++;
				}
				else
				{
					t+=res[k]-'0';
					res[k]=t%10+'0';
				}

			}
		}
	}
	reverse(res.begin(),res.end());
	return res;
}

int main()
{
	fact.push_back("1");
	int k=1;
	int n;
	string s;
	while(cin>>n)
	{
		while(k<=n)
		{
			s="";
			ostringstream oss(s);
			oss<<k;
			string t=oss.str();
			fact.push_back(product(fact[k-1],t));
			k++;
		}
		cout<<n<<"!"<<endl;
		cout<<fact[n]<<endl;
	}
	return 0;
}