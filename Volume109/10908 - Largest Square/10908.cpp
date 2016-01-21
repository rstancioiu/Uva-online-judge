#include <bits/stdc++.h>
#define N 128

using namespace std;
inline int MIN(int a,int b){return (a>b)?b:a;}
int t,n,m,a,b,q;
string tab[N];
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int p=0;p<t;++p)
	{
		cin>>n>>m>>q;
		for(int i=0;i<n;++i)
		{
			cin>>tab[i];
		}
		cout<<n<<" "<<m<<" "<<q<<"\n";
		for(int k=0;k<q;++k)
		{
			cin>>a>>b;
			int minimum=MIN(a,b);
			minimum = MIN(n-a-1,minimum);
			minimum = MIN(m-b-1,minimum);
			int s=0;
			for(s=0;s<minimum;++s)
			{
				bool square = true;
				int j=s+1;
				for(int i=a-j;i<=a+j;++i)
				{
					if(tab[i][b-j] != tab[a][b] || tab[i][b+j]!=tab[a][b])
					{
						square = false;
						break;
					}
				}

				for(int i=b-j;i<=b+j;++i)
				{
					if(tab[a-j][i] != tab[a][b] || tab[a+j][i]!=tab[a][b])
					{
						square = false;
						break;
					}
				}
				if(!square)
					break;
			}
			cout<<s*2+1<<"\n";
		}
	}

	return 0;
}