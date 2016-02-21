#include <bits/stdc++.h>
#define N 128

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
int mat[N][N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s1,s2;
	int c=1;
	while(getline(cin,s1) && s1!="#")
	{
		getline(cin,s2);
		int n = s1.length();
		int m = s2.length();
		for(int i=0;i<=n;++i)
			for(int j=0;j<=m;++j)
				mat[i][j]=0;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				if(s1[i]==s2[j])
					mat[i+1][j+1]=mat[i][j]+1;
				mat[i+1][j+1]=MAX(mat[i+1][j+1],mat[i][j+1]);
				mat[i+1][j+1]=MAX(mat[i+1][j+1],mat[i+1][j]);
			}
		}
		cout<<"Case #"<<c++<<": you can visit at most "<<mat[n][m]<<" cities.\n";
	}

	return 0;
}