#include <bits/stdc++.h>
#define N 1024

using namespace std;
inline int ABS(int a){return (a>0)?a:-a;}
int n;
int tab[N];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>tab[i];
	}
	for(int i=0;i<2*n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(j&1)
			{
				tab[j]=(tab[j]-1+n)%n;
			}
			else
			{
				tab[j]=(tab[j]+1+n)%n;
			}
		}
		int p;
		for(p=0;p<n;++p)
			if(tab[p]!=p)
				break;
		if(p==n)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}