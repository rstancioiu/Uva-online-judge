#include <cstdio>
#define N 10010
#define INF 0x1f1f1f1f

using namespace std;
int t,n;
double x,y;
typedef struct Point{
	int x;
	int y;
}Point;
Point points[N];

double distance(Point a,Point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main()
{
	scanf("%d",&t);
	int pos1,pos2;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d %d",&points[i].x,&points[i].y);
		int dmin=INF;
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				int d=distance(points[i],points[j]);
				if(dmin>d)
				{
					dmin=d;
					pos1=i;
					pos2=j;
				}
			}
		}
		x=(double)(points[pos1].x+points[pos2].x)/2;
		y=(double)(points[pos1].y+points[pos2].y)/2;
		printf("%.3f %.3f\n",x,y);
	}
	return 0;
}