#include <bits/stdc++.h>


using namespace std;
int n,m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(n==1)
	{
		cout<<n<<endl;
	}
	else if(n-m>m-1)
		cout<<m+1<<endl;
	else cout<<m-1<<endl;
	return 0;
}