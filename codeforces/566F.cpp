#include <bits/stdc++.h>
#define N 1000010

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
int v[N]={0};
int n,a;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a;
		v[a]++;
	}
	for(int i=0;i<N;++i)
	{
		if(v[i])
		{
			for(int j=i+i;j<N;j+=i)
			{
				if(v[j])
					v[j]=MAX(v[j],v[i]+1);
			}
		}
	}
	int ans=0;
	for(int i=0;i<N;++i)
		ans=MAX(ans,v[i]);
	cout<<ans<<endl;
	return 0;
}