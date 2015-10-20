#include <bits/stdc++.h>
#define N 128
#define INF 0x3f3f3f3f

using namespace std;

int t,n,a,b,m;
int mat[N][N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int c=1;c<=t;++c)
	{
		cin>>n>>m;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				mat[i][j]=INF;
		for(int i=0;i<m;++i)
		{
			cin>>a>>b;
			mat[a][b]=1;
			mat[b][a]=1;
		}
		for(int i=0;i<n;++i)
			mat[i][i]=0;
		for(int k=0;k<n;++k)
		{
			for(int i=0;i<n;++i)
			{
				for(int j=0;j<n;++j)
				{
					if(mat[i][j]>mat[i][k]+mat[k][j])
						mat[i][j]=mat[i][k]+mat[k][j];
				}
			}
		}
		cin>>a>>b;		
		int maximum=mat[a][b];
		for(int k=0;k<n;++k)
		{
			if(mat[a][k]!=0x3f3f3f3f && mat[k][b]!=0x3f3f3f3f)
			{
				if(mat[a][k]+mat[k][b]>maximum)
				maximum=mat[a][k]+mat[k][b];
			}
		}
		cout<<"Case "<<c<<": "<<maximum<<"\n";
	}
	return 0;
}