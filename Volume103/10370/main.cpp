#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#define N 1028

using namespace std;
int grades[N];


int main()
{
	int t,n,a;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int sum=0;
		double avg;
		for(int i=0;i<n;++i)
		{
			cin>>grades[i];
			sum+=grades[i];
		}
		avg=(double)sum/n;
		int cnt=0;
		for(int i=0;i<n;++i)
		{
			if(grades[i]>avg)
				cnt++;
		}
		double res=(double)cnt/n*100;
		res=round(res*1000)/1000;
		printf("%.3f%c\n",res,'%');
	}	
	return 0;
}