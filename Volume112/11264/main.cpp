#include <bits/stdc++.h>
#define N 1024

using namespace std;
int t;
long long int tab[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>tab[i];
		}
		long long int s=tab[0];
		int cnt=1;
		for(int i=1;i<n;++i)
		{
			if(s<tab[i])
			{
				s+=tab[i];
				cnt++;
			}
			else
			{
				s+=(tab[i]-tab[i-1]);
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}