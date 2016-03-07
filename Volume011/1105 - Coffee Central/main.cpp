#include <bits/stdc++.h>
#define N 2024

using namespace std;
inline int MIN(int a,int b){return (a>b)?b:a;}
inline int MAX(int a,int b){return (a>b)?a:b;}
int dx,dy,n,q;
int mat[N][N]={0};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	int c=1;
	while(cin>>dx>>dy>>n>>q && !(dx==0 && dy==0 && n==0 && q==0))
	{
		int k=dx+dy;
		for(int i=0;i<=k;++i)
			for(int j=0;j<=k;++j)
				mat[i][j]=0;
		for(int i=0;i<n;++i)
		{
			cin>>a>>b;
			mat[a][b]++;
		}
		for(int i=1;i<=k;++i)
			for(int j=1;j<=k;++j)
				mat[i][j]+=mat[i-1][j-1];
		cout<<"Case "<<c++<<":"<<endl;
		
		for(int p=0;p<q;++p)
		{
			cin>>a;
			int ans=0;
			int x=1,y=1;
			for(int i=1;i<=k;++i)
			{
				int sum=0;
				int j=1;
				int t=i;
				while(t>0)
				{
					int l = MIN(j-1,t-1);
					 l =MIN(l,a);
					int p1 = j-l;
					int p2 = t-l;
					if(l==a)
					{
						sum+=mat[j][t]-mat[p1-1][p2-1];
						sum+=mat[j-1][t]-mat[p1-1][p2];
					}
					else 
						sum+=mat[j][t]+mat[j-1][t];
					if(j>a+1)
					{
						int t1 = j-a-1;
						int t2 = t+a+1;
						int l = MIN(t1-1,t2-1);
						l = MIN(l,a);
						p1=t1-l;
						p2=t2-l;
						if(l==a)
						{
							sum-=mat[t1][t2]-mat[p1-1][p2-1];
							sum-=mat[t1][t2-1]-mat[p1][p2-1];
						}
						else
							sum-=mat[t1][t2]+mat[t1][t2-1];
					}
					p1 = MAX(j-a,1);
					p2= t;
					if(sum>ans)
					{
						ans=sum;
						x = p1,y = p2;
					}
					else if(sum==ans)
					{
						if(y>p2 || (y==p2 && x>p1))
						{
							y=p2;
							x=p1;
						}
					}
					t--;
					j++;
				}
			}
			cout<<ans<<" ("<<x<<","<<y<<")"<<endl;
		}
	}


	return 0;
}