#include <iostream>

using namespace std;
int x,k,t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>x>>k;
		cout<<k-(x%k)<<" "<<x%k<<endl;
	}
	return 0;
}