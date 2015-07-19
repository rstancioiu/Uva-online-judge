// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/4/495.html
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<string> fib;

string add(string a,string b)
{
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int t=0;
	int n=a.length();
	int m=b.length();
	string res="";
	for(int i=0;i<n || i<m || t!=0 ;++i,t/=10)
	{
		if(i<n && i<m)
		{
			t+=a[i]-'0'+b[i]-'0';
		}
		else if(i>=n && i<m)
		{
			t+=b[i]-'0';
		}
		else if(i<n && i>=m)
		{
			t+=a[i]-'0';
		}
		res+=t%10+'0';
	}
	reverse(res.begin(),res.end());
	return res;
}

int main()
{
	fib.push_back("0");
	fib.push_back("1");
	int n;
	int cnt=1;
	while(cin>>n)
	{
		if(n>cnt)
		{
			for(int i=cnt+1;i<=n;++i)
			{
				fib.push_back(add(fib[i-1],fib[i-2]));
			}
			cnt=n;
		}
		cout<<"The Fibonacci number for "<<n<<" is "<<fib[n]<<endl;
	}
}