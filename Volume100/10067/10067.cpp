// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/100/10067.html
#include <cstdio>
#include <queue>
#include <utility>
#define N 10
using namespace std;
int F[N][N][N][N];
int visited[N][N][N][N];
int t,n;
int s1,s2,s3,s4;
int t1,t2,t3,t4;
int f1,f2,f3,f4;
int minimum;
typedef struct Configuration{
	int x1;
	int x2;
	int x3;
	int x4;
}Configuration;
queue<pair<Configuration,int> > fifo;
int tab[8][4]={
	1,0,0,0,
	-1,0,0,0,
	0,1,0,0,
	0,-1,0,0,
	0,0,1,0,
	0,0,-1,0,
	0,0,0,1,
	0,0,0,-1
};

void Bfs()
{
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			for(int k=0;k<N;++k)
				for(int l=0;l<N;++l)
					visited[i][j][k][l]=0;
	Configuration start={s1,s2,s3,s4};
	visited[s1][s2][s3][s4]=1;
	fifo.push(make_pair(start,0));
	minimum=-1;
	bool found=false;
	while(!fifo.empty() && !found)
	{
		Configuration current=fifo.front().first;
		int t = fifo.front().second;
		fifo.pop();
		if(current.x1==t1 && current.x2==t2 
				&& current.x3==t3 && current.x4==t4)
		{
			minimum=t;
			found=true;
		}
		else
		{
			for(int i=0;i<8;++i)
			{
				int x1=(current.x1 +tab[i][0]+10)%10;
				int x2=(current.x2 +tab[i][1]+10)%10;
				int x3=(current.x3 +tab[i][2]+10)%10;
				int x4=(current.x4 +tab[i][3]+10)%10;
				if(!visited[x1][x2][x3][x4] && !F[x1][x2][x3][x4])
				{
					Configuration newConf={x1,x2,x3,x4};
					fifo.push(make_pair(newConf,t+1));
					visited[x1][x2][x3][x4]=1;
				}
			}
		}
	}
	while(!fifo.empty())
		fifo.pop();
	printf("%d\n",minimum);
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&s1,&s2,&s3,&s4);
		scanf("%d %d %d %d",&t1,&t2,&t3,&t4);
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				for(int k=0;k<N;++k)
					for(int l=0;l<N;++l)
						F[i][j][k][l]=0;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d %d %d %d",&f1,&f2,&f3,&f4);
			F[f1][f2][f3][f4]=1;
		}
		Bfs();
	}
	return 0;
}