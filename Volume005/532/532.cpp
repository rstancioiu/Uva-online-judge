// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/5/532.html
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <utility>
#define SIZE 32

using namespace std;

int l,r,c;
int visited[SIZE][SIZE][SIZE];
int prev[SIZE][SIZE][SIZE];
int distances[SIZE][SIZE][SIZE];
int s1,s2,s3,e1,e2,e3;


bool Bfs()
{
	int t1,t2,t3;
	queue<pair<int,pair<int,int> > > fifo;
	bool found=false;
	visited[s1][s2][s3]=1;
	fifo.push(make_pair(s1,make_pair(s2,s3)));
	while(!fifo.empty() && !found)
	{
		pair<int,pair<int,int> > p=fifo.front();
		fifo.pop();
		t1=p.first;
		t2=p.second.first;
		t3=p.second.second;
		if(t1>1 && !visited[t1-1][t2][t3])
		{
			distances[t1-1][t2][t3]=distances[t1][t2][t3]+1;
			visited[t1-1][t2][t3]=1;
			fifo.push(make_pair(t1-1,make_pair(t2,t3)));
		}
		if(t1<l && !visited[t1+1][t2][t3])
		{
			distances[t1+1][t2][t3]=distances[t1][t2][t3]+1;
			visited[t1+1][t2][t3]=1;
			fifo.push(make_pair(t1+1,make_pair(t2,t3)));
		}
		if(t2>1 && !visited[t1][t2-1][t3])
		{
			distances[t1][t2-1][t3]=distances[t1][t2][t3]+1;
			visited[t1][t2-1][t3]=1;
			fifo.push(make_pair(t1,make_pair(t2-1,t3)));
		}
		if(t2<r && !visited[t1][t2+1][t3])
		{
			distances[t1][t2+1][t3]=distances[t1][t2][t3]+1;
			visited[t1][t2+1][t3]=1;
			fifo.push(make_pair(t1,make_pair(t2+1,t3)));
		}
		if(t3>1 && !visited[t1][t2][t3-1])
		{
			distances[t1][t2][t3-1]=distances[t1][t2][t3]+1;
			visited[t1][t2][t3-1]=1;
			fifo.push(make_pair(t1,make_pair(t2,t3-1)));
		}
		if(t3<c && !visited[t1][t2][t3+1])
		{
			distances[t1][t2][t3+1]=distances[t1][t2][t3]+1;
			visited[t1][t2][t3+1]=1;
			fifo.push(make_pair(t1,make_pair(t2,t3+1)));
		}

		if(t1==e1 && t2==e2 && t3==e3)
		{
			found=true;
		}
	}
	return found;
}


int main()
{
	string s;
	while(getline(cin,s))
	{
		istringstream iss(s);
		iss>>l>>r>>c;
		if(l==0 && r==0 && c==0)
			break;
		for(int i=1;i<=l;++i)
		{
			if(i>1)
				getline(cin,s);
			for(int j=1;j<=r;++j)
			{
				getline(cin,s);
				istringstream iss1(s);
				char ch;
				for(int k=1;k<=c;++k)
				{	
					iss1>>ch;
					if(ch=='.')
					{
						visited[i][j][k]=0;
						distances[i][j][k]=0;
					}
					else if(ch=='#')
					{
						visited[i][j][k]=1;
						distances[i][j][k]=0;
					}
					else if(ch=='S')
					{
						s1=i;
						s2=j;
						s3=k;
						distances[i][j][k]=0;
						visited[i][j][k]=0;
					}
					else if(ch=='E')
					{
						e1=i;
						e2=j;
						e3=k;
						distances[i][j][k]=0;
						visited[i][j][k]=0;
					}
				}
			}
		}
		bool found = Bfs();
		if(found==true)
		{
			cout<<"Escaped in "<<distances[e1][e2][e3]<<" minute(s).\n";

		}
		else
		{
			cout<<"Trapped!\n";
		}
		getline(cin,s);
	}
	return 0;
}