#include <bits/stdc++.h>
#define N 128
#define M 4

using namespace std;
typedef pair<int,int> ii;
int n,m,c;
int mat[N][N];
int a,b;
string s;
ii dir[M]={{-1,0},{0,1},{1,0},{0,-1}};


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>m>>c && !(n==0 && m==0 && c==0))
	{
		int pos=0;
		for(int i=0;i<n;++i)
		{
			cin>>s;
			for(int j=0;j<s.length();++j)
			{
				if(s[j]=='*')
					mat[i][j]=1;
				else if(s[j]=='#')
					mat[i][j]=-1;
				else if(s[j]=='.')
					mat[i][j]=0;
				else
				{
					if(s[j]=='N')
						pos=0;
					else if(s[j]=='L')
						pos=1;
					else if(s[j]=='S')
						pos=2;
					else if(s[j]=='O')
						pos=3;
					a=i;
					b=j;
					mat[a][b]=0;
				}
			}
		}
		cin>>s;
		int ans=0;
		for(int i=0;i<s.length();++i)
		{
			if(s[i]=='D')
			{
				pos=(pos+1+M)%M;
			}
			else if(s[i]=='E')
			{
				pos=(pos-1+M)%M;
			}
			else
			{
				int t1=a+dir[pos].first;
				int t2=b+dir[pos].second;
				if(t1>=0 && t1<n && t2>=0 && t2<m && mat[t1][t2]!=-1)
				{
					a=t1;
					b=t2;
					ans+=mat[a][b];
					mat[a][b]=0;
				}
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}