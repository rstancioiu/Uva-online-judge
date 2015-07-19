// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/2/299.html
#include <bits/stdc++.h>
#define N 64

using namespace std;
int t,n;
int v[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;++i)
			cin>>v[i];
		int ans=0;
		for(int i=n-1;i>=0;--i)
		{
			for(int j=i+1;j<n;++j)
			{
				if(v[j]<v[j-1])
				{
					int aux=v[j];
					v[j]=v[j-1];
					v[j-1]=aux;
					ans++;
				}
			}
		}
		cout<<"Optimal train swapping takes "<<ans<<" swaps.\n";
	}

	return 0;
}
