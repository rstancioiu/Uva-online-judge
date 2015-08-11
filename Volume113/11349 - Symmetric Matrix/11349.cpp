#include <bits/stdc++.h>
#define N 128

using namespace std;

long long int m[N][N];
int T,n;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	char c1,c2;
	cin>>T;
	for(int t=1;t<=T;++t)
	{
		cin>>c1>>c2>>n;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				cin>>m[i][j];
		bool sym=true;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(m[i][j]!=m[n-i+1][n-j+1] || m[i][j]<0)
					sym=false;
		if(sym)
			cout<<"Test #"<<t<<": Symmetric."<<endl;
		else cout<<"Test #"<<t<<": Non-symmetric."<<endl;
	}
	return 0;
}