#include <bits/stdc++.h>
#define N 128

using namespace std;
inline int MIN(int a,int b){return (a>b)?b:a;}
inline int MAX(int a,int b){return (a<b)?b:a;}
int mat[N][N];
int n,m,q,a,b,d;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t=0;
	while(cin>>n>>m>>q && !(n==0 && m==0 && q==0))
	{
		if(t)
			cout<<"\n";
		cout<<"Case #"<<++t<<"\n";
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				mat[i][j]=0x3f3f3f3f;
		for(int i=0;i<m;++i)
		{
			cin>>a>>b>>d;
			mat[a][b]=d;
			mat[b][a]=d;
		}
		for(int k=1;k<=n;++k)
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=n;++j)
				{
					if(mat[i][k]!=0x3f3f3f3f && mat[k][j]!=0x3f3f3f3f)
					{
						int maximum=MAX(mat[i][k],mat[k][j]);
						mat[i][j]=MIN(mat[i][j],maximum);
					}
				}
			}
		}
		for(int i=0;i<q;++i)
		{
			cin>>a>>b;
			if(mat[a][b]==0x3f3f3f3f)
				cout<<"no path\n";
			else
				cout<<mat[a][b]<<"\n";
		}
	}

	return 0;
}