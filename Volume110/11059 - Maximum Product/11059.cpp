#include <bits/stdc++.h>
#define N 18

using namespace std;
int n;
long long tab[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c=1;
	while(cin>>n)
	{
		for(int i=0;i<n;++i)
			cin>>tab[i];
		long long maximum=0;
		for(int i=0;i<n;++i)
		{
			long long cnt=1;
			for(int j=i;j<n;++j)
			{
				cnt*=tab[j];
				if(cnt>maximum)
					maximum=cnt;
			}
		}
		cout<<"Case #"<<c++<<": The maximum product is "<<maximum<<".\n\n";
	}
	return 0;
}