// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/110/11088.html
#include <cstdio>
#define INF 0x1f1f1f1f
#define N 16

using namespace std;

int teams,n,c;
int p[N];
int visited[N];
int BackTrack(int nbTeams,int l)
{
	int sum=INF;
	int maxNbTeams=nbTeams;
	for(int i=l;i<n;++i)
	{
		if(!visited[i] && maxNbTeams<nbTeams + (n-i)/3)
		{
			for(int j=i+1;j<n;++j)
			{
				if(!visited[j] && maxNbTeams<nbTeams + (n-i)/3 )
				{
					for(int k=j+1;k<n;++k)
					{
						if(!visited[k] && maxNbTeams<nbTeams + (n-i)/3)
						{
							int sump=p[i]+p[j]+p[k];
							if(sump>=20)
							{
								visited[i]=visited[j]=visited[k]=1;
								int nbT=BackTrack(nbTeams+1,i+1);
								if(nbT>maxNbTeams)
									maxNbTeams=nbT;
								visited[i]=visited[j]=visited[k]=0;
							}
						}
					}
				}
			}
		}
	}
	return maxNbTeams;
}


int main()
{
	c=1;
	while(scanf("%d",&n)==1 && n!=0)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&p[i]);
			visited[i]=0;
		}
		teams=BackTrack(0,0);
		printf("Case %d: %d\n",c++,teams);
	}
	return 0;
}