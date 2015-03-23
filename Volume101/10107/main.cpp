#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v;
	int k;
	int n=0;
	v.push_back(0);
	while(cin>>k)
	{
		v.push_back(k);
		n++;
		sort(v.begin(),v.end());
		int avg=(n+1)/2;
		if(avg*2==n+1)
		{
			cout<<v[avg]<<endl;
		}
		else
		{
			cout<<(int)(v[avg]+v[avg+1])/2<<endl;
		}
	}
	return 0;
}