#include <bits/stdc++.h>
#define N 100000
#define M 16

using namespace std;
int w[N];
int p[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,t;
	while(cin>>t)
	{
		n=(1<<t);
		for(int i=0;i<n;++i)
			cin>>w[i];
		for(int i=0;i<n;++i)
		{
			int a=i;
			p[a]=0;
			for(int j=0;j<t;++j)
			{
				int s=a^(1<<j);
				p[a]+=w[s];
			}
		}
		int maximum=0;
		for(int i=0;i<n;++i){
			int a=i;
			for(int j=0;j<t;++j)
			{
				int s=a^(1<<j);
				if(maximum<p[a]+p[s])
					maximum=p[a]+p[s];
			}
		}
		cout<<maximum<<endl;
	}
	return 0;
}
