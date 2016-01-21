#include <bits/stdc++.h>
#define N 32

using namespace std;
inline int MIN(int a,int b){return (a>b)?b:a;}
inline int MAX(int a,int b){return (a<b)?b:a;}
typedef pair<int,int> ii;
string s;
int t;
int mat[N][N]={0};
int sum[N][N]={0};
int occ[N][N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	getline(cin,s);
	istringstream iss(s);
	iss>>t;
	getline(cin,s);
	int p=0;
	while(t--)
	{
		if(p++) cout<<"\n";
		int n=0;
		while(getline(cin,s) && s!="")
		{
			for(int j=0;j<s.length();++j)
			{
				mat[n+1][j+1]=s[j]-'0';
			}
			n++;
		}
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)
				occ[i][j]=0;
		for(int j=1;j<=n;++j)
		{
			int cnt=0;
			for(int i=1;i<=n;++i)
			{
				if(mat[i][j]) occ[i][j]=++cnt;
				else occ[i][j]=cnt=0;
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(mat[i][j])
				{
					int max_area=0;
					int minimum=0x7fffffff,k;
					for(k=j;k<=n && mat[i][k];++k)
					{
						minimum=MIN(minimum,occ[i][k]);
						max_area=MAX(max_area,(k-j+1)*minimum);
					}
					ans=MAX(ans,max_area);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}