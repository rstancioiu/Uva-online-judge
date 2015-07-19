// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/126/12673.html
#include <bits/stdc++.h>
#define N 100010

using namespace std;
int n,g,s,r;
int dif[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>g)
	{
		for(int i=0;i<n;++i)
		{
			cin>>s>>r;
			dif[i]=s-r;
		}
		sort(dif,dif+n);
		int cnt=0;
		for(int i=n-1;i>=0;--i)
		{
			if(dif[i]>0)
				cnt+=3;
			else if(dif[i]+g>0)
			{
				g-=1-dif[i];
				cnt+=3;
			}
			else if(dif[i]+g==0)
			{
				g=0;
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}

	return 0;
}