#include <iostream>
#include <string>
#define N 2024

using namespace std;

inline int MAX(int a,int b)
{
	return (a>b) ? a : b;
}

int v[N][N]={0};

int main()
{
	string s1,s2;
	while(getline(cin,s1))
	{
		getline(cin,s2);
		int n=s1.size();
		int m=s2.size();
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(s1[i-1]==s2[j-1])
				{
					v[i][j]=v[i-1][j-1]+1;
				}
				else
				{
					v[i][j]=MAX(v[i-1][j],v[i][j-1]);
				}
			}
		}
		cout<<v[n][m]<<endl;
	}
	return 0;
}