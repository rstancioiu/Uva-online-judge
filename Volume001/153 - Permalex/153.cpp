// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/1/153.html
#include <bits/stdc++.h>
#define N 31

using namespace std;
string s;
int comb[N][N]={0};
int tab[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i=0;i<N;++i)
		comb[i][0]=1;
	for(int i=1;i<N;++i)
	{
		for(int j=1;j<=i;++j)
		{
			comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
		}
	}
	while(cin>>s && s!="#")
	{
		for(int i=0;i<N;++i)
			tab[i]=0;
		for(int i=0;i<s.length();++i)
			tab[s[i]-'a']++;
		int ans=0;
		int sum=s.length();
		for(int i=0;i<s.length();++i)
		{
			for(int j=0;j<N;++j)
			{
				if(tab[j]>0 && j!=s[i]-'a')
				{
					tab[j]--;
					int sumaux=sum-1;
					int prod=1;
					for(int k=0;k<N;++k)
					{
						prod*=comb[sumaux][tab[k]];
						sumaux-=tab[k];
					}
					ans+=prod;
					tab[j]++;
				}
				else if(j==s[i]-'a')
				{
					break;
				}
			}
			sum--;
			tab[s[i]-'a']--;
		}
		printf("%10d\n",ans+1);
	}
	return 0;
}