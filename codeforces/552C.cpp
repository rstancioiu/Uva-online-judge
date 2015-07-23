#include <bits/stdc++.h>

using namespace std;
int w,m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>w>>m;
	while((m%w==0 || m%w==1 || m%w==w-1) && m!=0)
	{
		if(m%w==0)
			m/=w;
		else if(m%w==1)
			m=(m-1)/w;
		else if(m%w==w-1)
			m=(m+1)/w;
	}
	if(m==0)
		cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}