#include <bits/stdc++.h>

using namespace std;
inline long long int MIN(long long int a,long long int b){return (a>b)?b:a;}
int t;
long long int n,m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		long long int dif=m-n;
		cout<<MIN(n*dif+(n-1)*n/2,m*(m-1)/2-dif*(dif-1)/2)<<endl;
	}
	return 0;
}