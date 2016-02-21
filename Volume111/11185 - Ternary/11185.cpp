#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n && n>=0)
	{
		if(n==0)
		{
			cout<<"0\n";
			continue;
		}

		int p=1;
		string s = "";
		while(n!=0)
		{
			int t = n/p;
			int k = t%3;
			s+= '0' + k;
			n-=k*p;
			p*=3;
		}
		for(int i=s.length()-1;i>=0;--i)
			cout<<s[i];
		cout<<"\n";
	}
	return 0;
}