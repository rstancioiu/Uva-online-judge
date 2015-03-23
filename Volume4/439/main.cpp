#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <utility>
#define N 8

using namespace std;
int visited[N][N];
int table[N][N];

int bfs(int x1,int y1,int x2,int y2)
{
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
			visited[i][j]=0;
	}
	visited[x1][y1]++;
	queue<pair<int,int> > fifo;
	fifo.push(make_pair(x1,y1));
	while(!fifo.empty())
	{
		int t1=(fifo.front()).first;
		int t2=(fifo.front()).second;
		if(t1==x2 && t2==y2)
		{
			return visited[x2][y2]-1;
		}
		fifo.pop();
		if(t1>=2 && t2>=1 && visited[t1-2][t2-1]==0)
		{
			fifo.push(make_pair(t1-2,t2-1));
			visited[t1-2][t2-1]=visited[t1][t2]+1;
		}
		if(t1>=2 && t2+1<N && visited[t1-2][t2+1]==0)
		{
			fifo.push(make_pair(t1-2,t2+1));
			visited[t1-2][t2+1]=visited[t1][t2]+1;
		}

		if(t1>=1 && t2>=2 && visited[t1-1][t2-2]==0)
		{
			fifo.push(make_pair(t1-1,t2-2));
			visited[t1-1][t2-2]=visited[t1][t2]+1;
		}
		if(t1>=1 && t2+2<N && visited[t1-1][t2+2]==0)
		{
			fifo.push(make_pair(t1-1,t2+2));
			visited[t1-1][t2+2]=visited[t1][t2]+1;
		}

		if(t1+1<N && t2>=2 && visited[t1+1][t2-2]==0)
		{
			fifo.push(make_pair(t1+1,t2-2));
			visited[t1+1][t2-2]=visited[t1][t2]+1;
		}
		if(t1+1<N && t2+2<N && visited[t1+1][t2+2]==0)
		{
			fifo.push(make_pair(t1+1,t2+2));
			visited[t1+1][t2+2]=visited[t1][t2]+1;
		}

		if(t1+2<N && t2+1<N && visited[t1+2][t2+1]==0)
		{
			fifo.push(make_pair(t1+2,t2+1));
			visited[t1+2][t2+1]=visited[t1][t2]+1;
		}
		if(t1+2<N && t2>=1 && visited[t1+2][t2-1]==0)
		{
			fifo.push(make_pair(t1+2,t2-1));
			visited[t1+2][t2-1]=visited[t1][t2]+1;
		}
	}

}


int main()
{
	string s;
	string pos1,pos2;
	while(getline(cin,s))
	{
		istringstream iss(s);
		iss>>pos1>>pos2;
		int res=bfs(pos1[0]-'a',pos1[1]-'1',pos2[0]-'a',pos2[1]-'1');
		cout<<"To get from "<<pos1<<" to "<<pos2<<" takes "<<res<<" knight moves."<<endl;
	}
	return 0;
}