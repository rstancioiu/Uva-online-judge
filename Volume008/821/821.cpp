// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/8/821.html
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#define N 128
#define INF 0x3f3f3f3f

using namespace std;

inline int MIN(int a,int b)
{
	return (a>b)?b:a;
}

int v[N][N];

int main()
{
	int a,b;
	int pnode;
	string s;
	int nb=0;
	while(getline(cin,s))
	{
		nb++;
		istringstream iss(s);
		iss>>a>>b;
		for(int i=1;i<N;++i)
		{
			for(int j=1;j<N;++j)
				v[i][j]=INF;
		}
		if(a==0 && b==0)
			break;
		else
		{
			v[a][b]=1;
		}
		while(iss>>a>>b && !(a==0 && b==0))
		{
			v[a][b]=1;
		}
		for(int i=1;i<N;++i)
			v[i][i]=0;
		for(int k=1;k<N;++k)
		{
			for(int i=1;i<N;++i)
			{
				for(int j=1;j<N;++j)
				{
					v[i][j]=MIN(v[i][j],v[i][k]+v[k][j]);
				}
			}
		}
		pnode=0;
		int sum=0;
		for(int i=1;i<N;++i)
		{
			for(int j=1;j<N;++j)
			{
				if(v[i][j]!=INF && i!=j)
				{
					pnode++;
					sum+=v[i][j];
				}
			}
		}
		printf("Case %d: average length between pages = %.3f clicks\n",nb,(double)sum/pnode);

	}

	return 0;
}