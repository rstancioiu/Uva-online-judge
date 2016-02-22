#include <bits/stdc++.h>
#define pb push_back
#define N 30100

using namespace std;
vector<int> cur;
double amount;
long long tab[N]={0};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cur.pb(5);cur.pb(10);
	cur.pb(20);cur.pb(50);
	cur.pb(100);cur.pb(200);
	cur.pb(500);cur.pb(1000);
	cur.pb(2000);cur.pb(5000);
	cur.pb(10000);
	tab[0]=1;
	for(int j=0;j<cur.size();++j)
	{
		int p = cur[j];
		for(int i=0;i<p;++i)
		{
			for(int t=i+p;t<N;t+=p)
			{
				tab[t]+=tab[t-p];
			}
		}
	}
	while(cin>>amount && amount!=0)
	{
		int sum = 100.000001*amount;
		cout<<right<<setw(6)<<fixed<<setprecision(2)<<amount<<setw(17)<<tab[sum]<<endl;
	}

	return 0;
}