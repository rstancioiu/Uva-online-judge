// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/2/201.html
#include <bits/stdc++.h>
#define N 16
#define D 2

using namespace std;
int n,m;
int tab[N][N][D];
int v[N][N][D];
int cnt[N];
char d;
int x,y;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c=1;
	while(cin>>n)
	{
		if(c!=1)
		{
			cout<<endl;
			cout<<"**********************************"<<endl;
			cout<<endl;
		}
		for(int i=1;i<N;++i)
		{
			for(int j=1;j<N;++j)
			{
				for(int k=0;k<D;++k)
				{
					tab[i][j][k]=0;
					v[i][j][k]=0;
				}
			}
		}
		for(int i=1;i<N;++i)
		{
			cnt[i]=0;
		}
		cin>>m;
		for(int i=0;i<m;++i)
		{
			cin>>d;
			cin>>x>>y;
			if(d=='H')
			{
				v[x][y+1][0]=1;
			}
			else if(d=='V')
			{
				v[y+1][x][1]=1;
			}
		}
		for(int i=1;i<=n;++i)
		{
			tab[i][1][0]=0;
			for(int j=2;j<=n;++j)
			{
				if(v[i][j][0])
				{
					tab[i][j][0]=tab[i][j-1][0]+1;
				}
			}
		}
		for(int j=1;j<=n;++j)
		{
			tab[1][j][1]=0;
			for(int i=2;i<=n;++i)
			{
				if(v[i][j][1])
				{
					tab[i][j][1]=tab[i-1][j][1]+1;
				}
			}
		}
		for(int s=1;s<=n;++s)
		{
			for(int i=1;i<=n-s;++i)
			{
				for(int j=1;j<=n-s;++j)
				{
					if(tab[i][j+s][0]>=s && tab[i+s][j][1]>=s)
					{
						if(tab[i+s][j+s][0]>=s && tab[i+s][j+s][1]>=s)
						{
							cnt[s]++;
						}
					}
				}
			}
		}
		cout<<"Problem #"<<c++<<endl;
		cout<<endl;
		int i;
		for(i=1;i<=n;++i)
			if(cnt[i])
				break;
		if(i>n)
		{
			cout<<"No completed squares can be found."<<endl;
		}
		else
		{
			for(int i=1;i<=n;++i)
			{
				if(cnt[i])
				{
					cout<<cnt[i]<<" square (s) of size "<<i<<endl;
				}
			}
		}
	}
	return 0;
}
