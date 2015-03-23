#include <iostream>
#include <string>
#include <queue>
#include <utility>
#define N 128

using namespace std;
int v[N][N];
int n,m;

void bfs(int t1,int t2)
{
	queue<pair<int,int> > fifo;
	fifo.push(make_pair(t1,t2));
	v[t1][t2]=1;
	while(!fifo.empty())
	{
		int i=fifo.front().first;
		int j=fifo.front().second;
		fifo.pop();
		if(i>0 && v[i-1][j]==0)
		{
			v[i-1][j]=1;
			fifo.push(make_pair(i-1,j));
		}
		if(j>0 && v[i][j-1]==0)
		{
			v[i][j-1]=1;
			fifo.push(make_pair(i,j-1));
		}
		if(i<n-1 && v[i+1][j]==0)
		{
			v[i+1][j]=1;
			fifo.push(make_pair(i+1,j));
		}
		if(j<m-1 && v[i][j+1]==0)
		{
			v[i][j+1]=1;
			fifo.push(make_pair(i,j+1));
		}
		if(i>0 && j>0 && v[i-1][j-1]==0)
		{
			v[i-1][j-1]=1;
			fifo.push(make_pair(i-1,j-1));
		}
		if(i>0 && j<m-1 && v[i-1][j+1]==0)
		{
			v[i-1][j+1]=1;
			fifo.push(make_pair(i-1,j+1));
		}		
		if(i<n-1 && j>0 && v[i+1][j-1]==0)
		{
			v[i+1][j-1]=1;
			fifo.push(make_pair(i+1,j-1));
		}		
		if(i<n-1 && j<m-1 && v[i+1][j+1]==0)
		{
			v[i+1][j+1]=1;
			fifo.push(make_pair(i+1,j+1));
		}
	}
}

int main()
{
	string s;
	while(1)
	{	
		cin>>n;
		cin>>m;
		if(n==0 && m==0)
			break;
		for(int i=0;i<n;++i)
		{
			cin>>s;
			for(int j=0;j<m;++j)
			{
				if(s[j]=='*')
					v[i][j]=-1;
				else if(s[j]=='@')
					v[i][j]=0;
			}
		}
		int cnt=0;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				if(v[i][j]==0)
				{
					cnt++;
					bfs(i,j);
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}