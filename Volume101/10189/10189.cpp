// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/101/10189.html
#include <iostream>
#include <string>
#define N 128

using namespace std;
int res[N][N];

int main()
{
	int n,m;
	int nb=0;
	string s;
	while(1)
	{
		cin>>n>>m;
		if(n==0 && m==0)
			break;
		if(nb++)
			cout<<endl;
		for(int i=0;i<n;++i)
		{
			cin>>s;
			for(int j=0;j<m;++j)
			{
				if(s[j]=='.')
				{
					res[i][j]=0;
				}
				else if(s[j]=='*')
				{
					res[i][j]=-1;
				}
			}
		}
		cout<<"Field #"<<nb<<":"<<endl;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				if(res[i][j]==0)
				{
					if(res[i-1][j]==-1 && i>0)
						res[i][j]++;
					if(res[i-1][j-1]==-1 && i>0 && j>0)
						res[i][j]++;
					if(res[i][j-1]==-1 && j>0)
						res[i][j]++;
					if(res[i+1][j]==-1 && i+1<n)
						res[i][j]++;
					if(res[i-1][j+1]==-1 && j+1<m && i>0)
						res[i][j]++;
					if(res[i+1][j-1]==-1 && i+1<n && j>0)
						res[i][j]++;
					if(res[i+1][j+1]==-1 && i+1<n && j+1<m)
						res[i][j]++;
					if(res[i][j+1]==-1 && j+1<m)
						res[i][j]++;
					cout<<res[i][j];
				}
				else
					cout<<"*";
			}
			cout<<endl;
		}
	}
	return 0;
}
