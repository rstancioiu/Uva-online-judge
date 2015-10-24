#include <bits/stdc++.h>
#define N 128
#define M 4

using namespace std;
typedef pair<int,int> ii;
int vis[N][N];
int T,r,c,m,n,w,a,b;
ii dir[M]={{1,1},{1,-1},{-1,1},{-1,-1}};

void DFS(int i,int j)
{
	for(int k=0;k<M;++k)
	{
		int p1=dir[k].first*n+i;
		int p2=dir[k].second*m+j;
		int p3=dir[k].first*m+i;
		int p4=dir[k].second*n+j;
		if(p1>=0 && p2>=0 && p1<r && p2<c && vis[p1][p2]==0)
		{
			vis[p1][p2]=1;
			DFS(p1,p2);
		}
		if(p3>=0 && p4>=0 && p3<r && p4<c && vis[p3][p4]==0)
		{
			vis[p3][p4]=1;
			DFS(p3,p4);
		}
	}
} 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	for(int t=1;t<=T;++t)
	{
		cin>>r>>c>>m>>n;
		for(int i=0;i<r;++i)
		{
			for(int j=0;j<c;++j)
			{
				vis[i][j]=0;
			}
		}
		cin>>w;
		for(int i=0;i<w;++i)
		{
			cin>>a>>b;
			vis[a][b]=-1;
		}
		vis[0][0]=1;
		DFS(0,0);
		int e=0,o=0;
		for(int i=0;i<r;++i)
		{
			for(int j=0;j<c;++j)
			{
				if(vis[i][j]>0)
				{
					int k=0;
					for(int l=0;l<M;++l)
					{
						if(((l==1 || l==2) && (n==0|| m==0)) || (n!=0 && m!=0))
						{
							int p1=dir[l].first*n+i;
							int p2=dir[l].second*m+j;
							int p3=dir[l].first*m+i;
							int p4=dir[l].second*n+j;
							if(p1>=0 && p2>=0 && p1<r && p2<c && vis[p1][p2]>0 && n!=m)
								k++;
							if(p3>=0 && p4>=0 && p3<r && p4<c && vis[p3][p4]>0)
								k++;
						}
					}
					if(k%2==0)
						e++;
					else
						o++;
				}
			}
		}

		cout<<"Case "<<t<<": "<<e<<" "<<o<<"\n";
	}
	return 0;
}