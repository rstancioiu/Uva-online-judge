// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/101/10127.html
#include <iostream>
#include <string>

using namespace std;

int mod(string a, int b)
{
      int i;
      int t=0;
      for (i=0;i<a.length(); ++i)
              t = (t * 10 + a[i]-'0') % b;
      return t;
}

int main()
{
	int n;
	while(cin>>n)
	{
		int t=1;
		string s="1";
		while(1)
		{
			int res=mod(s,n);
			if(res==0)
			{
				break;
			}
			else
			{
				s+='1';
				t++;
			}
		}
		cout<<t<<endl;
	}
	return 0;
}