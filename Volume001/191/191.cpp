// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/1/191.html
#include <cstdio>


using namespace std;

int xs,ys,xe,ye,xl,yt,xr,yb;
int t;

int Compute()
{
	double b,c;
	b=(double)(xs-xe)/(ye-ys);
	c=-xs-b*ys;
	double x,y;
	y=(double)(-c-xl)/b;
	if(y>=yb && y<=yt && ((y>=ys && y<=ye)||(y<=ys && y>=ye)))
		return 1;
	y=(double)(-c-xr)/b;
	if(y>=yb && y<=yt && ((y>=ys && y<=ye)||(y<=ys && y>=ye)))
		return 1;
	x=(double)(-c-b*yt);
	if(x>=xl && x<=xr && ((x>=xs && x<=xe)||(x<=xs && x>=xe)))
		return 1;
	x=(double)(-c-b*yb);
	if(x>=xl && x<=xr && ((x>=xs && x<=xe)||(x<=xs && x>=xe)))
		return 1;
	return 0;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d %d %d %d %d",&xs,&ys,&xe,&ye,&xl,&yt,&xr,&yb);
		if(yb>yt)
		{
			int aux=yt;
			yt=yb;
			yb=aux;
		}
		if(xl>xr)
		{
			int aux=xl;
			xl=xr;
			xr=aux;
		}
		int result;
		if((xs<xl && xe<xl) || (xs>xr && xe>xr) || (ys<yb && ye<yb) || (ys>yt && ye>yt))
			result=0;
		else if((xs>=xl && xe>=xl) && (xs<=xr && xe<=xr) && (ys>=yb && ye>=yb) && (ys<=yt && ye<=yt))
			result=1;
		else
		result = Compute();
		if(result)
			printf("T\n");
		else printf("F\n");
	}

}