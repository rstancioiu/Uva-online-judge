#include <bits/stdc++.h>
#define N 256

using namespace std;
inline int MIN(int a,int b){return (a>b)?b:a;}
inline int MAX(int a,int b){return (a<b)?b:a;}
struct Point{
	int x;
	int y;
};
int n;
Point array[N];
int dist[N][N];

int compute_distance(Point a, Point b)
{
	return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c=1;
	while(cin>>n && n!=0)
	{
		cin>>array[1].x>>array[1].y;
		cin>>array[n].x>>array[n].y;
		for(int i=2;i<n;++i)
			cin>>array[i].x>>array[i].y;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				dist[i][j]=compute_distance(array[i],array[j]);
			}
		}
		for(int k=1;k<=n;++k)
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=n;++j)
				{
					dist[i][j]=MIN(dist[i][j],MAX(dist[i][k],dist[k][j]));
				}
			}
		}
		double ans = sqrt(dist[1][n]);
		cout<<"Scenario #"<<c++<<"\n";
		cout<<setprecision(3)<<fixed<<"Frog Distance = "<<ans<<"\n\n";
	}
	return 0;
}