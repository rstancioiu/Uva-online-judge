#include <bits/stdc++.h>

using namespace std;
inline int ABS(int a){return (a>0)?a:-a;}
int n;
string s;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	cin>>s;
	int cnt0=0;
	int cnt1=0;
	for(int i=0;i<n;++i)
	{
		if(s[i]=='0')
			cnt0++;
		else cnt1++;
	}
	cout<<ABS(cnt1-cnt0)<<endl;
	return 0;
}