//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/1/111.html
//Description: Exercice of dynamic programming similar to LCS (Longest common subsequence)
#include <iostream>
#include <string>
#include <sstream>
#define N 32

using namespace std;

inline int MAX(int a,int b){return (a>b) ? a:b;}

int priority[N];
int cur[N];
int v[N][N]={0};

int main()
{
	int a,n;
	string s;
	cin>>n;
	getline(cin,s);
	getline(cin,s);
	istringstream iss(s);
	for(int i=1;i<=n;++i)
	{
		iss>>a;
		priority[a]=i;
	}
	while(getline(cin,s))
	{
		istringstream iss(s);
		for(int i=1;i<=n;++i)
		{
			iss>>a;
			cur[a]=i;
		}

		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(cur[i]==priority[j])
				{
					v[i][j]=v[i-1][j-1]+1;
				}
				else
				{
					v[i][j]=MAX(v[i-1][j],v[i][j-1]);
				}
			}
		}
		cout<<v[n][n]<<endl;
	}
	return 0;
}