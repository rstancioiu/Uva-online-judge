#include <bits/stdc++.h>
#define N 1000100

using namespace std;
int t,n,k;
string s;
int mat[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("parola.in","r",stdin);
	freopen("parola.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=0;i<n;++i)
			mat[i]=0;
		cin>>s;
		int sum=0;
		long long ans=0;
		mat[0]=1;
		for(int i=0;i<s.size();++i)
		{
			sum=(sum+s[i])%n;
			ans+=mat[(sum-k+n)%n];
			mat[sum]++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}