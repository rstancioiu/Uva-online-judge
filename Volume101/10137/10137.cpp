// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/101/10137.html
#include <iostream>
#include <cmath>
#include <iomanip>
#define N 1028

using namespace std;
double v[N];


int main()
{
	int n;
	double d;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		double sum=0;
		for(int i=0;i<n;++i)
		{
			cin>>v[i];
			sum+=v[i];
		}
		double rest1=0,rest2=0;
		double avg=sum/n;
		for(int i=0;i<n;++i)
		{
			if(v[i]>=avg)
				rest1+=(floor((v[i]-avg)*100))/100;
			else if(v[i]<avg)
				rest2+=(floor((avg-v[i])*100))/100;
		}
		if(rest1<rest2)
			cout << '$' << setprecision(2) << fixed << rest2 << endl;
		else cout << '$' << setprecision(2) << fixed << rest1 << endl;
	}
	return 0;
}
