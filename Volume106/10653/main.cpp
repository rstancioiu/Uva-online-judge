#include <iostream>
#include <queue>
#include <utility>
#define N 1024

using namespace std;
int v[N][N]={0};
int visited[N][N]={0};
int r,c;

void Bfs(int xe,int ye,int xs,int ys)
{
	queue<pair<int,int> > fifo;
	fifo.push(make_pair(xe,ye));
   	bool found=false;
	if(xe==xs && ye==ys)
	{
		found=true;
		v[xs][ys]=v[xe][ye];
	}
	visited[xe][ye]=1;
	while(!fifo.empty() && !found)
	{
		int t1=fifo.front().first;
		int t2=fifo.front().second;
		fifo.pop();
		if(t1>0 && v[t1-1][t2]!=-1 && !visited[t1-1][t2])
		{
			visited[t1-1][t2]=1;
			v[t1-1][t2]=v[t1][t2]+1;
			fifo.push(make_pair(t1-1,t2));
			if(t1-1==xs && t2==ys)
				found=true;
		}
		if(t2>0 && v[t1][t2-1]!=-1 && !visited[t1][t2-1])
		{
			visited[t1][t2-1]=1;
			v[t1][t2-1]=v[t1][t2]+1;
			fifo.push(make_pair(t1,t2-1));
			if(t1==xs && t2-1==ys)
				found=true;
		}
		if(t1<r-1 && v[t1+1][t2]!=-1 && !visited[t1+1][t2])
		{
			visited[t1+1][t2]=1;
			v[t1+1][t2]=v[t1][t2]+1;
			fifo.push(make_pair(t1+1,t2));
			if(t1+1==xs && t2==ys)
				found=true;
		}
		if(t2<c-1 && v[t1][t2+1]!=-1 && !visited[t1][t2+1])
		{
			visited[t1][t2+1]=1;
			v[t1][t2+1]=v[t1][t2]+1;
			fifo.push(make_pair(t1,t2+1));
			if(t1==xs && t2+1==ys)
				found=true;
		}
	}
	while(!fifo.empty()) fifo.pop();
}

int main()
{
	int rows,xe,ye,xs,ys,t,k,a;
	while(cin>>r>>c && !(r==0 && c==0))
	{
		for(int i=0;i<r;++i)
		{
			for(int j=0;j<c;++j)
			{
				v[i][j]=0;
				visited[i][j]=0;
			}
		}
		cin>>rows;
		for(int i=0;i<rows;++i)
		{
			cin>>t>>k;
			for(int j=0;j<k;++j)
			{
				cin>>a;
				v[t][a]=-1;
			}
		}
		cin>>xe>>ye;
		cin>>xs>>ys;
		Bfs(xe,ye,xs,ys);
		cout<<v[xs][ys]<<endl;
	}
	return 0;
}