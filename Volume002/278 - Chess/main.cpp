#include <bits/stdc++.h>

using namespace std;
inline int MIN(int a,int b){return (a>b)?b:a;}
int t;
int n,m;
char type;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>type;
		cin>>n>>m;
		if(type=='r' || type=='Q')
		{
			cout<<MIN(n,m)<<endl;
		}
		else if(type=='K')
		{
			cout<<((n+1)/2)*((m+1)/2)<<endl;
		}
		else if(type=='k')
		{
			cout<<(n*m)/2<<endl;
		}
	}

	return 0;
}