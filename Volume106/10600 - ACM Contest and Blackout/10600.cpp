#include <bits/stdc++.h>
#define N 128

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<iii> e;
int t,n,m,a,b,d;
int cost[N],c[N];
int mat[N][N];

int find(int x){return (x==c[x])?x:find(c[x]);}
 
int main()
{		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;++i)
			c[i]=i;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				mat[i][j]=0;
		for(int i=0;i<m;++i)
		{
			cin>>a>>b>>d;
			e.push_back(make_pair(d,ii(a,b)));
		}
		int sum=0,dif=0x7fffffff;
		sort(e.begin(),e.end());
		for(int i=0;i<e.size();++i)
		{
			int p1=find(e[i].second.first);
			int p2=find(e[i].second.second);
			int t1=e[i].second.first;
			int t2=e[i].second.second;
			if(p1!=p2)
			{
				for(int k=1;k<=n;++k)
				{
					int p3=find(k);
					for(int j=1;j<=n;++j)
					{
						int p4=find(j);
						if((p3==p1 && p4==p2) || (p3==p2 && p4==p1))
							mat[k][j]=e[i].first;
					}
				}
				c[p1]=p2;
				sum+=e[i].first;
			}
			else if(mat[t1][t2] && dif>e[i].first-mat[t1][t2])
				dif=e[i].first-mat[t1][t2];
			else if(mat[t2][t1] && dif>e[i].first-mat[t2][t1])
				dif=e[i].first-mat[t2][t1];
		}
		cout<<sum<<" "<<sum+dif<<"\n";
		e.clear();
	}
	return 0;
}