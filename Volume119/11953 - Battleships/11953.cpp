#include <bits/stdc++.h>
#define N 128
#define M 4

using namespace std;
typedef pair<int,int> ii;
int T,n;
int mat[N][N];
int vis[N][N];
string s;
ii dir[M]={{1,0},{-1,0},{0,1},{0,-1}};

int DFSUtil(int i,int j)
{
	int t=mat[i][j];
	for(int k=0;k<M;++k)
	{
		int t1=dir[k].first+i;
		int t2=dir[k].second+j;
		if(t1>=0 && t1<n && t2>=0 && t2<n && mat[t1][t2]>=0 && !vis[t1][t2])
		{
			vis[t1][t2]=1;
			int ret=DFSUtil(t1,t2);
			if(ret)
				t=ret;
		}
	}
	return t;
}

int DFS()
{
	int ret=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(mat[i][j]>=0 && !vis[i][j])
			{
				vis[i][j]=1;
				ret+=DFSUtil(i,j);
			}
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	for(int t=1;t<=T;++t)
	{
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>s;
			for(int j=0;j<n;++j)
			{
				if(s[j]=='.')
					mat[i][j]=-1;
				else if(s[j]=='x')
					mat[i][j]=1;
				else mat[i][j]=0;
				vis[i][j]=0;
			}
		}
		cout<<"Case "<<t<<": "<<DFS()<<"\n";
	}
	return 0;
}