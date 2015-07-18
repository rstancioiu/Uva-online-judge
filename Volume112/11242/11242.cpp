// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/112/11242.html
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define eps 1e-6

using namespace std;

vector<double> ratio;
vector<int> front;
vector<int> rear;

int main()
{
	int f,r,a;
	while(cin>>f && f!=0)
	{
		cin>>r;
		for(int i=0;i<f;++i)
		{
			cin>>a;
			front.push_back(a);
		}
		for(int j=0;j<r;++j)
		{
			cin>>a;
			rear.push_back(a);
		}
		for(int i=0;i<f;++i)
		{
			for(int j=0;j<r;++j)
			{
				double r = (double)front[i]/rear[j];
				ratio.push_back(r);
			}
		}
		double rmax=0;
		sort(ratio.begin(),ratio.end());
		for(int i=0;i+1<ratio.size();++i)
		{
			if(ratio[i+1]/ratio[i]>rmax)
				rmax=ratio[i+1]/ratio[i];
		}
		printf("%0.2lf\n",rmax+eps);
		ratio.clear();
		front.clear();
		rear.clear();
	}
	return 0;
}