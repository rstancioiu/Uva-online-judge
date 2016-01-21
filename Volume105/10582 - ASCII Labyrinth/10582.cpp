#include <bits/stdc++.h>
#define N 64
#define M 3
#define DIR 4

using namespace std;
int t;
int n,m;
char tab[N][N][M][M];
int mat[N][N];
int vis[N][N];
int x[DIR]={0,0,-1,1};
int y[DIR]={-1,1,0,0};
int sol;

void compute(int i,int j,int dir)
{
	if(i==n-1 && j==m-1)
	{
		if(mat[i][j]!=0)
			sol++;
		return;
	}
	if(mat[i][j]==0)
		return;
	if(mat[i][j]==1)
	{
		int t1 = i+x[dir];
		int t2 = j+y[dir];
		if(t1>=0 && t1<n && t2>=0 && t2<m && !vis[t1][t2])
		{
			vis[t1][t2]=1;
			compute(t1,t2,dir);
			vis[t1][t2]=0;
		}
	}
	else
	{
		int p1=0,p2=1;
		if(dir==0 || dir==1)
		{
			p1=2;
			p2=3;
		}
		int t1=i+x[p1];
		int t2=j+y[p1];
		int t3=i+x[p2];
		int t4=j+y[p2];
		if(t1>=0 && t1<n && t2>=0 && t2<m && !vis[t1][t2])
		{
			vis[t1][t2]=1;
			compute(t1,t2,p1);
			vis[t1][t2]=0;
		}
		if(t3>=0 && t3<n && t4>=0 && t4<m && !vis[t3][t4])
		{
			vis[t3][t4]=1;
			compute(t3,t4,p2);
			vis[t3][t4]=0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	getline(cin,s);
	istringstream iss(s);
	iss>>t;
	while(t--)
	{
		getline(cin,s);
		istringstream iss(s);
		iss>>n>>m;
		for(int i=0;i<n*4;++i)
		{
			getline(cin,s);
			if(i%4!=0)
			{
				for(int j=0;j<4*m;++j)
				{
					if(j%4!=0)
					{
						tab[i/4][j/4][i%4-1][j%4-1]=s[j];
					}
				}
			}
		}
		getline(cin,s);
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				if(tab[i][j][1][0]=='*' && tab[i][j][1][1]=='*' && tab[i][j][1][2]=='*')
					mat[i][j]=1;
				else if(tab[i][j][1][0]=='*' && tab[i][j][1][1]=='*' && tab[i][j][2][1]=='*')
					mat[i][j]=2;
				else
					mat[i][j]=0;
			}
		}
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				vis[i][j]=0;
		sol=0;
		vis[0][0]=1;
		compute(0,0,1);
		compute(0,0,3);
		cout<<"Number of solutions: "<<sol<<"\n";
	}

	return 0;

}