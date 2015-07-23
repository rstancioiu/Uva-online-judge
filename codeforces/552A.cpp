#include <iostream>
#define N 128

using namespace std;

int tab[N][N]={0};
int x1,x2,y1,y2,n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	long long int sum=0;
	for(int k=0;k<n;++k)
	{
		cin>>x1>>y1>>x2>>y2;
		for(int i=x1;i<=x2;++i)
		{
			for(int j=y1;j<=y2;++j)
				tab[i][j]++;
		}
	}
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
			sum+=tab[i][j];
	}
	cout<<sum<<endl;
	return 0;
}