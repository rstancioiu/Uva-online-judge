#include <bits/stdc++.h>
#define N 32
#define M 4

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
typedef pair<int,int> ii;
int m,n,a,b;
int mat[N][N];
string s;
ii dir[M]={{1,0},{-1,0},{0,1},{0,-1}}; 

int DFSUtil(int i,int j)
{
	int ret=1;
	if(mat[i][j]==2)
		ret=-0x3f3f3f3f;
	mat[i][j]=0;
	for(int k=0;k<M;++k)
	{
		int t1=dir[k].first+i;
		int t2=(dir[k].second+j+n)%n;
		if(t1>=0 && t1<m && mat[t1][t2])
		{
			ret+=DFSUtil(t1,t2);
		}
	}
	return ret;
}

int DFS()
{
	int maximum=0;
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(mat[i][j])
			{
				int t=DFSUtil(i,j);
				maximum=MAX(t,maximum);
			}
		}
	}
	return maximum;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>m>>n)
	{
		char c;
		for(int i=0;i<m;++i)
		{
			cin>>s;
			if(i==0)
				c=s[0];
			for(int j=0;j<n;++j)
			{
				if(s[j]==c)
					mat[i][j]=0;
				else 
					mat[i][j]=1;
			}
		}
		cin>>a>>b;
		if(!mat[a][b])
		{
			for(int i=0;i<m;++i)
			{
				for(int j=0;j<n;++j)
				{
					if(mat[i][j])
						mat[i][j]=0;
					else mat[i][j]=1;
				}
			}
		}
		mat[a][b]=2;
		cout<<DFS()<<"\n";
	}
	return 0;
}