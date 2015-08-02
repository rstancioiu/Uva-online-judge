#include <bits/stdc++.h>
#define M 1000001

using namespace std;

int tab[M];
int c[M]={0};
int cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cnt=0;
	tab[1]=0;
	for(int i=2;i<M;++i)
	{
		tab[i]=tab[i-1];
		int s=sqrt(i);
		for(int k=2;k<=s;++k)
		{
			if(i%k==0)
			{
				c[i]=c[i/k]+c[k];
				break;
			}
		}
		if(c[i]==0)
		{
			tab[i]++;
			c[i]++;
		}
		else
			tab[i]+=c[i];
	}
	int n;
	while(cin>>n)
	{
		cout<<tab[n]<<endl;
	}

	return 0;
}