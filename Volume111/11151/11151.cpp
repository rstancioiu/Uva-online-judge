#include <bits/stdc++.h>
#define N 1024

using namespace std;
inline int MAX(int a, int b){return (a>b)?a:b;}
int tab[N][N];
int t;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	getline(cin,s);
	while(t--)
	{
		getline(cin,s);
		int n=s.length();
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				tab[i][j]=0;
		tab[0][0]=1;
		for(int i=1;i<n;++i)
		{
			tab[i][i]=1;
			if(s[i-1]==s[i])
				tab[i-1][i]=2;
			else tab[i-1][i]=1;
		}
		for(int j=2;j<n;++j)
		{
			for(int i=0;i+j<n;++i)
			{
				int k=i+j;
				if(s[i]==s[k])
					tab[i][k]=tab[i+1][k-1]+2;
				else tab[i][k]=tab[i+1][k-1];
				tab[i][k]=MAX(tab[i][k],tab[i+1][k]);
				tab[i][k]=MAX(tab[i][k],tab[i][k-1]);
			}
		}
		int ans=0;
		for(int i=0;i<n;++i)
			for(int j=i;j<n;++j)
				if(tab[i][j]>ans)
					ans=tab[i][j];
		cout<<ans<<endl;
	}

	return 0;
}
