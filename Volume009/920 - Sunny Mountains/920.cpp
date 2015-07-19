// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/9/920.html
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

typedef pair<double,double> ii;
vector<ii> points;
int t,n;

bool myFunction(ii pr1,ii pr2)
{
	if(pr1.first<pr2.first)
		return true;
	else if(pr1.first>pr2.first)
		return false;
	else return (pr1.second>pr2.second);
}

double CalculatePos(ii pr1,ii pr2,double y)
{
	double b,c;
	b=(pr1.first-pr2.first)/(pr2.second-pr1.second);
	c=-pr1.first-b*pr1.second;
	return (-c-b*y);
}

double CalculateDistance(ii pr1,ii pr2)
{
	return sqrt((pr1.first-pr2.first)*(pr1.first-pr2.first)+(pr1.second-pr2.second)*(pr1.second-pr2.second));
}



int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ii pr;
		for(int i=0;i<n;++i)
		{
			scanf("%lf %lf",&pr.first,&pr.second);
			points.push_back(pr);
		}
		sort(points.begin(),points.end(),myFunction);
		int prev=n-1;
		double maximum=0;
		double sum=0;
		for(int i=n-2;i>=0;--i)
		{
			if(points[prev].second<points[i].second)
			{
				if(maximum<points[i].second)
				{
					double x =CalculatePos(points[i],points[prev],maximum);
					sum+=CalculateDistance(points[i],ii(x,maximum));
					maximum=points[i].second;
				}
			}
			prev=i;
		}
		printf("%.2f\n",sum);
		points.clear();
	}
	return 0;
}