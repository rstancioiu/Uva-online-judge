#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n,a;
	vector<int> v;
	vector<int>::iterator it;
	ios::sync_with_stdio(false);
	while(cin>>n)
	{
		if(n==0)
			break;
		for(int i=0;i<n;++i)
		{
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		for(it=v.begin();it!=v.end();++it)
		{
			if(it!=v.end()-1)
				cout<<*it<<" ";
			else cout<<*it;
		}
		v.clear();
		cout<<endl;
	}
	return 0;
}