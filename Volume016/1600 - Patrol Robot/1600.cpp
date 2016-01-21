#include <bits/stdc++.h>
#define N 32
#define M 4

using namespace std;
struct cell{
	int x,y,z,val;
	cell(int x,int y,int z,int val): x(x),y(y),z(z),val(val) {}
};
int t;
int n,m,k;
int obs[N][N]={0};
int best[N][N][N];
int dirx[M]={0,0,1,-1};
int diry[M]={-1,1,0,0};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		for(int i=0;i<=k;++i)
			for(int p=1;p<=n;++p)
				for(int q=1;q<=m;++q)
					best[p][q][i]=0x7fffffff;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				cin>>obs[i][j];
		queue<cell> Q;
		cell C(1,1,0,0);
		Q.push(C);
		while(!Q.empty())
		{
			int x=Q.front().x;
			int y=Q.front().y;
			int z=Q.front().z;
			int val=Q.front().val;
			Q.pop();
			if(val<best[x][y][z])
			{
				best[x][y][z]=val;
				for(int i=0;i<M;++i)
				{
					int p=x+dirx[i];
					int q=y+diry[i];
					int new_z=0;
					if(obs[p][q])
				 		new_z = z + obs[p][q];
					if(p>0 && q>0 && p<=n && q<=m && new_z<=k)
					{
						if(val+1<best[p][q][new_z])
						{
							cell new_cell(p,q,new_z,val+1);
							Q.push(new_cell);
						}
					}
				}
			}
		}
		int minimum=0x7fffffff;
		for(int i=0;i<=k;++i)
		{
			if(minimum>best[n][m][i])
				minimum=best[n][m][i];
		}
		if(minimum==0x7fffffff)
			cout<<-1<<"\n";
		else
			cout<<minimum<<"\n";
		for(int i=0;i<=n;++i)
			for(int j=0;j<=m;++j)
				obs[i][j]=0;
	}
}