// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/6/661.html
#include <bits/stdc++.h>
#define N 32

using namespace std;
int n,m,c;
int dev[N];
int state[N];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("test.txt","r",stdin);
	int t=0;
	while(cin>>n>>m>>c && !(n==0 && m==0 && c==0))
	{
		for(int i=1;i<=n;++i)
		{
			cin>>dev[i];
			state[i]=0;
		}
		int cnt=0;
		int ans=0;
		for(int i=0;i<m;++i)
		{
			int a;
			cin>>a;
			if(!state[a])
			{
				cnt+=dev[a];
				ans=(cnt>ans)?cnt:ans;
				state[a]=1;
			}
			else
			{
				cnt-=dev[a];
				state[a]=0;
			}
		}
		t++;
		if(ans>c)
		{
			cout<<"Sequence "<<t<<endl;
			cout<<"Fuse was blown."<<endl;
		}
		else
		{
			cout<<"Sequence "<<t<<endl;
			cout<<"Fuse was not blown."<<endl;
			cout<<"Maximal power consumption was "<<ans<<" amperes."<<endl;
		}
		cout<<endl;

	}

	return 0;
}
