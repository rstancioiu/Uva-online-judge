#include <bits/stdc++.h>

using namespace std;
int g,d;
string s;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>d && d!=0)
	{
		cin>>s;
		g=s.length()/d;
		int cnt=0;
		for(int i=0;i<s.length();++i)
		{
			if(i%g==0)
				cnt++;
			cout<<s[(2*cnt-1)*g-i-1];
		}
		cout<<endl;
	}
	return 0;
}