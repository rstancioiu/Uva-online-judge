// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/9/929.html
// First solution TLE with STL SET
// Second solution Accepted with STL PRIORITY_QUEUE
#include <set>
#include <iostream>
#include <queue>
#include <vector>
#define N 1024
#define INF 0x3f3f3f3f

using namespace std;
int t,n,m;
int maze[N][N];
int distances[N][N];
int visited[N][N];

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

// Time limit excedeed solution with STL SET
void DijkstraSet(int i,int j)
{
	int value,t1,t2;
	set<iii> Q;
	Q.insert(iii(maze[i][j],ii(i,j)));
	distances[i][j]=maze[i][j];
	while(!Q.empty())
	{
		iii p=(*Q.begin());
		value = p.first;
		t1= p.second.first;
		t2= p.second.second;
		Q.erase(*Q.begin());
		if(t1>0 && distances[t1-1][t2]>value + maze[t1-1][t2])
		{
			distances[t1-1][t2] = value + maze[t1-1][t2];
			Q.insert(iii(distances[t1-1][t2], ii(t1-1,t2)));
		}
		if(t1<n-1 && distances[t1+1][t2] > value + maze[t1+1][t2])
		{
			distances[t1+1][t2] = value + maze[t1+1][t2];
			Q.insert( iii(distances[t1+1][t2], ii(t1+1,t2)));		
		}
		if(t2>0 && distances[t1][t2-1] > value +maze[t1][t2-1])
		{
			distances[t1][t2-1] = value +maze[t1][t2-1];
			Q.insert( iii(distances[t1][t2-1], ii(t1,t2-1)));
		}
		if(t2<m-1 && distances[t1][t2+1] > value +maze[t1][t2+1])
		{
			distances[t1][t2+1] = value + maze[t1][t2+1];
			Q.insert( iii(distances[t1][t2+1], ii(t1,t2+1)));		
		}
	}
}

// Time limit excedeed solution with STL QUEUE
void DijkstraQueue(int i,int j)
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			visited[i][j]=0;
		}
	}
	int value,t1,t2;
	queue<ii> Q;
	Q.push(ii(i,j));
	distances[i][j]=maze[i][j];
	while(!Q.empty())
	{
		t1= Q.front().first;
		t2= Q.front().second;
		value = distances[t1][t2];
		visited[t1][t2]=0;
		Q.pop();
		if(t1>0 && !visited[t1-1][t2] && distances[t1-1][t2]>value + maze[t1-1][t2])
		{
			distances[t1-1][t2] = value + maze[t1-1][t2];
			Q.push(ii(t1-1,t2));
			visited[t1-1][t2]=1;
		}
		if(t1<n-1 && !visited[t1+1][t2] && distances[t1+1][t2] > value + maze[t1+1][t2])
		{
			distances[t1+1][t2] = value + maze[t1+1][t2];
			Q.push(ii(t1+1,t2));	
			visited[t1+1][t2]=1;	
		}
		if(t2>0 && !visited[t1][t2-1] && distances[t1][t2-1] > value +maze[t1][t2-1])
		{
			distances[t1][t2-1] = value +maze[t1][t2-1];
			Q.push(ii(t1,t2-1));
			visited[t1][t2-1]=1;
		}
		if(t2<m-1 &&!visited[t1][t2+1] && distances[t1][t2+1] > value +maze[t1][t2+1])
		{
			distances[t1][t2+1] = value + maze[t1][t2+1];
			Q.push(ii(t1,t2+1));
			visited[t1][t2+1]=1;		
		}
	}
}


// Solution with STL Priority Queue Accepted with 2.272
void DijkstraPriorityQueue(int i,int j)
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			visited[i][j]=0;
		}
	}
	int value,t1,t2;
	priority_queue<iii, vector<iii>, greater<iii> > Q;
	Q.push(iii(maze[i][j],ii(i,j)));
	distances[i][j]=maze[i][j];
	while(!Q.empty())
	{
		value = Q.top().first;
		t1= Q.top().second.first;
		t2= Q.top().second.second;
		visited[t1][t2]=0;
		Q.pop();
		if(t1>0 && !visited[t1-1][t2] && distances[t1-1][t2]>value + maze[t1-1][t2])
		{
			distances[t1-1][t2] = value + maze[t1-1][t2];
			Q.push(iii(distances[t1-1][t2],ii(t1-1,t2)));
			visited[t1-1][t2]=1;
		}
		if(t1<n-1 && !visited[t1+1][t2] && distances[t1+1][t2] > value + maze[t1+1][t2])
		{
			distances[t1+1][t2] = value + maze[t1+1][t2];
			Q.push(iii(distances[t1+1][t2],ii(t1+1,t2)));	
			visited[t1+1][t2]=1;	
		}
		if(t2>0 && !visited[t1][t2-1] && distances[t1][t2-1] > value +maze[t1][t2-1])
		{
			distances[t1][t2-1] = value +maze[t1][t2-1];
			Q.push(iii(distances[t1][t2-1],ii(t1,t2-1)));
			visited[t1][t2-1]=1;
		}
		if(t2<m-1 &&!visited[t1][t2+1] && distances[t1][t2+1] > value +maze[t1][t2+1])
		{
			distances[t1][t2+1] = value + maze[t1][t2+1];
			Q.push(iii(distances[t1][t2+1],ii(t1,t2+1)));
			visited[t1][t2+1]=1;		
		}
	}
}


int main()
{
	cin>>t;
	for(int k=0;k<t;++k)
	{	
		cin>>n;
		cin>>m;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				cin>>maze[i][j];
				distances[i][j]=INF;
			}
		}
		//DijkstraSet(0,0);
		DijkstraPriorityQueue(0,0);
		cout<<distances[n-1][m-1]<<endl;
	}
	return 0;
}