#include <bits/stdc++.h>
#define N 512

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
int tab[N][N];
int row[N];
int n,m,q;
int a,b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >>n>>m>>q;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>tab[i][j];
	for(int i=1;i<=n;++i)
	{
		int count=0;
		int maximum=0;
		for(int j=1;j<=m;++j)
		{
			if(tab[i][j])
			{
				if(++count > maximum)
				{
					maximum = count;
				}
			}
			else count=0;
		}
		row[i]=maximum;
	}	
	for(int t=0;t<q;++t)
	{
		cin>>a>>b;
		tab[a][b]=!tab[a][b];
		int	maximum=0;
		int count=0;
		for(int j=1;j<=m;++j)
		{
			if(tab[a][j])
			{
				if(++count > maximum)
					maximum = count;
			}
			else count=0;
		}
		row[a]=maximum;
		maximum=0;
		for(int i=1;i<=n;++i)
			maximum=MAX(maximum,row[i]);
		cout<<maximum<<endl;
	}
	return 0;
}