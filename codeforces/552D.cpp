#include <bits/stdc++.h>
#define N 2048

using namespace std;
typedef struct Point{
	int x;
	int y;
}Point;


Point tab[N];
int n;

bool Check(Point a, Point b, Point c)
{
	int x1=a.x-b.x;
	int y1=a.y-b.y;
	int x2=b.x-c.x;
	int y2=b.y-c.y;
	if(x1*y2==x2*y1)
		return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>tab[i].x>>tab[i].y;
	}
	long long int ans=0;
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			for(int k=j+1;k<n;++k)
			{
				if(Check(tab[i],tab[j],tab[k]))
					ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}