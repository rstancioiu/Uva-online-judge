#include <bits/stdc++.h>
#define N 10010
#define M 128

using namespace std;
int t,n,k,a;
int tab[N];
int vis[M];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		int sum = 0;
		cin>>n>>k;
		for(int i=0;i<n;++i)
		{
			cin>>tab[i];
			tab[i]=tab[i]%k;
			tab[i]=(tab[i]+k)%k;
			sum+=tab[i];
		}
		int p = sum%k;
		if(p==0)
			cout<<"Divisible\n";
		else if (k%2==0 && p%2==1)
			cout<<"Not divisible\n";
		else
		{
			int t;
			if(p%2==0)
				t=p/2;
			else
				t=(k+p)/2;
			for(int i=0;i<k;++i)
				vis[i]=0;
			for(int i=0;i<n;++i)
			{
				int a = tab[i];
				vector<int> aux;
				aux.push_back(a);
				for(int j=0;j<k;++j)
				{
					if(vis[j])
					{
						int l = (j+a)%k;
						aux.push_back(l);
					}
				}
				for(int i=0;i<aux.size();++i)
					vis[aux[i]]=1;
			}
			if(vis[t])
				cout<<"Divisible\n";
			else
				cout<<"Not divisible\n";
		}
	}
	return 0;
}