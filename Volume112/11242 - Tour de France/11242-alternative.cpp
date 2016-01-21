#include <bits/stdc++.h>
#define N 128000

using namespace std;
typedef pair<int,int> ii;
int f,r;
int front[N];
int rear[N];
vector<double> ratio;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>f && f!=0)
	{
		cin>>r;
		for(int i=0;i<f;++i)
			cin>>front[i];
		for(int i=0;i<r;++i)
			cin>>rear[i];
		for(int i=0;i<f;++i)
		{
			for(int j=0;j<r;++j)
			{
				double rat= double(rear[j])/front[i];
				ratio.push_back(rat); 
			}
		}
		sort(ratio.begin(),ratio.end());
		double maximum=0;
		for(int i=0;i<ratio.size()-1;++i)
		{
			double d = ratio[i+1]/ratio[i];
			if(d>maximum)
				maximum=d;
		}
		ratio.clear();
		cout<<fixed<<setprecision(2)<<maximum<<"\n";
	}

	return 0;
}