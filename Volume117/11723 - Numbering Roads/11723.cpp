#include <bits/stdc++.h>
#define M 26

using namespace std;
int n,r;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c=1;
	while(cin>>n>>r && !(n<=0 && r<=0))
	{
		int p=(n-1)/r;
		if(p<=M)
			cout<<"Case "<<c++<<": "<<p<<endl;
		else cout<<"Case "<<c++<<": impossible"<<endl;
	}
	return 0;
}