#include <bits/stdc++.h>
#define N 1024

using namespace std;
int n,k;
long long mat[N][N];
long long tabr[N][N];
long long array[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t=0;
	while(cin>>n>>k)
	{
		if(t++) cout<<"\n";
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				cin>>mat[i][j];
		long long sum=0;
		for(int i=0;i<n;++i)
		{
			long long cnt=0;
			for(int j=0;j<k;++j)
			{
				cnt+=mat[i][j];
			}
			for(int j=0;j+k-1<n;++j)
			{
				tabr[i][j]=cnt;
				cnt+=mat[i][j+k]-mat[i][j];
			}
		}
		for(int i=0;i+k<n;++i)
			array[i]=0;
		for(int i=0;i<k;++i)
		{
			for(int j=0;j+k-1<n;++j)
			{
				array[j]+=tabr[i][j];
			}
		}
		for(int j=0;j+k-1<n;++j)
			cout<<array[j]<<"\n";
		for(int j=0;j+k-1<n;++j)
			sum+=array[j];
		for(int i=0;i+k<n;++i)
		{
			for(int j=0;j+k-1<n;++j)
			{
				array[j]+=tabr[i+k][j]-tabr[i][j];
				cout<<array[j]<<"\n";
				sum+=array[j];
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}