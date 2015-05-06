#include <iostream>
#define N 16

using namespace std;

inline double MAX(double a,double b){return (a>b)?a:b;}
inline double MIN(double a,double b){return (a>b)?b:a;}

typedef struct Rectangle{
	double x1;
	double y1;
	double x2;
	double y2;
}Rectangle;

typedef struct Point{
	double x;
	double y;
}Point;

Rectangle array[N];

bool Contains(Rectangle& r,Point& p)
{
	return (MIN(r.x1,r.x2)<p.x && p.x<MAX(r.x1,r.x2) &&
			 p.y<MAX(r.y1,r.y2) && MIN(r.y1,r.y2)<p.y);
}

int main()
{
	char c;
	int i=0;
	while(cin>>c)
	{
		if(c=='*')
			break;
		else if(c=='r')
		{
			cin>>array[i].x1>>array[i].y1>>array[i].x2>>array[i].y2;
			i++;
		}
	}
	int count=1;
	Point point;
	bool isContained;
	while(cin>>point.x>>point.y && !(point.x==9999.9 && point.y==9999.9))
	{
		isContained=false;
		for(int j=0;j<i;++j)
		{
			if(Contains(array[j],point))
			{
				isContained=true;
				cout<<"Point "<<count<<" is contained in figure "<<j+1<<endl;
			}
		}
		if(!isContained)
			cout<<"Point "<<count<<" is not contained in any figure"<<endl;
		count++;
	}
	return 0;
}

