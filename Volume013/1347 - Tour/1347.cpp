// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/13/1347.html
#include <bits/stdc++.h>

using namespace std;
double a,b;
int n;
typedef struct Point{
	double x;
	double y;
}Point;

vector<Point> points;

double CalculateDistance(Point a, Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("test.txt","r",stdin);
	while(cin>>n)
	{
		double ans=0;
		Point act;
		for(int i=0;i<n;++i)
		{
			cin>>act.x>>act.y;
			points.push_back(act);
		}
		double sum1=CalculateDistance(points[0],points[n-1]);
		double sum2=sum1;
		sum1=CalculateDistance(points[0],points[1])+CalculateDistance(points[1],points[n-1]);
		int prev1=1;
		int prev2=0;
		for(int i=2;i<n-1;++i)
        {
            double d1= CalculateDistance(points[prev1],points[i]);
            double d5= CalculateDistance(points[n-1],points[i]);
            double d2= CalculateDistance(points[prev1],points[n-1]);
            double d3= CalculateDistance(points[prev2],points[i]);
            double d4= CalculateDistance(points[n-1],points[prev2]);
            if(d1+d5-d2>d3+d5-d4)
            {
                sum2+=d3+d5-d4;
                prev2=i;
            }
            else
            {
                sum1+=d1+d5-d2;
                prev1=i;
            }
        }
        printf("%.2f\n",sum1+sum2);
        points.clear();
	}
	return 0;
}
