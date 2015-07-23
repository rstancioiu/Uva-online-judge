#include <bits/stdc++.h>
#define N 200020

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int ABS(int a){return (a>0)?a:-a;}
inline double MIN(double a,double b){return (a>b)?b:a;}
int n;
double w;
int tab[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	cin>>w;
	for(int i=0;i<2*n;++i)
		cin>>tab[i];
	sort(tab,tab+2*n);
	double minimum=MIN(2*tab[0],tab[n]);
	minimum/=2;
	minimum = MIN(w,minimum*n*3);
	printf("%.6f\n",minimum);
	return 0;
}