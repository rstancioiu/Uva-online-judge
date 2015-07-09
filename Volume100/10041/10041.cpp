// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/100/10041.html
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline int ABS(int a)
{
	return (a>0) ? a:-a;
}



int main()
{
	int t,n,a;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> v;
		for(int i=0;i<n;++i)
		{
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		int sum=0;
		for(int i=0;i<n;++i)
		{
			sum+=ABS(v[n-i-1]-v[i]);
		}
		cout<<sum/2<<endl;	
	}
	return 0;
}