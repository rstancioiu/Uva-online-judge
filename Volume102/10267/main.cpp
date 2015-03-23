#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <sstream>
#define N 256
#define M 256

using namespace std;
string v[M];
int visited[N][M];
int m,n;

void initialize()
{
	for(int i=0;i<n;++i)
		v[i]="";
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			v[i]+='O';
		}
	}	
}

void clear()
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			v[i][j]='O';
		}
	}
}

void drawVertical(int x, int y1,int y2 ,char c)
{
	if(y1>y2)
	{
		int aux=y1;
		y1=y2;
		y2=aux;
	}
	for(int i=y1;i<=y2;++i)
		v[i][x]=c;
}

void drawHorizontal(int x1,int x2,int y,char c)
{
	if(x1>x2)
	{
		int aux=x1;
		x1=x2;
		x2=aux;
	}
	for(int i=x1;i<=x2;++i)
	{
		v[y][i]=c;
	}
}

void drawRectangle(int x1,int x2,int y1,int y2,char c)
{
	if(x1>x2)
	{
		int aux=x1;
		x1=x2;
		x2=aux;
	}
	if(y1>y2)
	{
		int aux=y1;
		y1=y2;
		y2=aux;
	}
	for(int i=x1;i<=x2;++i)
	{
		for(int j=y1;j<=y2;++j)
		{
			v[j][i]=c;
		}
	}
}

void drawRegion(int x,int y,char c)
{
	if(v[x][y]==c)
	{
		return;
	}
	else
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				visited[i][j]=0;
			}
		}
		char c1=v[x][y];
		queue<pair<int,int> > queue;
		queue.push(make_pair(x,y));
		visited[x][y]=1;
		while(!queue.empty())
		{
			int t1=queue.front().first;
			int t2=queue.front().second;
			v[t1][t2]=c;
			queue.pop();
			if(t1-1>=0 && v[t1-1][t2]==c1 && !visited[t1-1][t2])
			{
				queue.push(make_pair(t1-1,t2));
				visited[t1-1][t2];
			}
			if(t1+1<n && v[t1+1][t2]==c1 && !visited[t1+1][t2])
			{
				queue.push(make_pair(t1+1,t2));
				visited[t1+1][t2]=1;
			}
			if(t2>0 && v[t1][t2-1]==c1 && !visited[t1][t2-1])
			{
				queue.push(make_pair(t1,t2-1));
				visited[t1][t2-1]=1;
			}
			if(t2+1<m && v[t1][t2+1]==c1 && !visited[t1][t2+1])
			{
				queue.push(make_pair(t1,t2+1));
				visited[t1][t2+1]=1;
			}
		} 
	}
}


void write(string name)
{
	cout<<name<<endl;
	for(int j=0;j<n;++j)
	{
		cout<<v[j]<<endl;
	}
}



int main()
{
	m=0;
	n=0;
	string name;
	int x,y,y1,y2,x1,x2;
	char color;
	string s;
	while(1)
	{
		getline(cin,s);
		istringstream iss(s);
		char c;
		iss>>c;
		if(c=='X')
			break;
		switch(c)
		{
			case 'I': 
				iss>>m>>n;
				initialize();
				break;
			case 'C': clear();
				break;
			case 'L': 
				iss>>x>>y;
				iss>>color;
				v[y-1][x-1]=color;
				break;
			case 'V':
				iss>>x>>y1>>y2;
				iss>>color;
				drawVertical(x-1,y1-1,y2-1,color);
				break;
			case 'H': 
				iss>>x1>>x2>>y;
				iss>>color;
				drawHorizontal(x1-1,x2-1,y-1,color);
				break;
			case 'K': 
				iss>>x1>>y1>>x2>>y2;
				iss>>color;
				drawRectangle(x1-1,x2-1,y1-1,y2-1,color);
				break;
			case 'F': 
				iss>>x>>y;
				iss>>color;
				drawRegion(y-1,x-1,color);
				break;
			case 'S': 
				iss>>name;
				write(name);
				break;
			default :
				break;
		}
	}
	return 0;
}