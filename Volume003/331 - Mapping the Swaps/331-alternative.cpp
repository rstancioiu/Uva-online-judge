#include <bits/stdc++.h>

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
int n,a;
vector<int> tab;
int answer;
int minimum;

void compute(vector<int> &v,int swaps)
{
	bool swapped=false;
	for(int i=0;i<v.size()-1;++i)
	{
		if(v[i]>v[i+1])
		{
			swap(v[i],v[i+1]);
			compute(v,swaps+1);
			swap(v[i],v[i+1]);
			swapped=true;
		}
	}
	if(!swapped)
	{
		if(swaps<minimum)
		{
			minimum=swaps;
			if(swaps==0)
				answer=0;
			else
				answer=1;
		}
		else if(swaps == minimum)
		{
			answer++;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c=1;
	while(cin>>n && n!=0)
	{
		for(int i=0;i<n;++i)
		{
			cin>>a;
			tab.push_back(a);
		}	
		minimum =0x7ffffff;
		answer=0;
		compute(tab,0);
		cout<<"There are "<<answer<<" swap maps for input data set "<<c++<<".\n"; 
		tab.clear();
	}
	return 0;
}