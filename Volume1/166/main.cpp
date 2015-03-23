#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int d[6]={1,2,4,10,20,40};
int sol[7];

int money[256][6];
int found[256];
int nbCoins[256];
inline int min(int a,int b)
{
	return (a>b)? b :a;
}

int findCoins(int x)
{
	int cnt=0;
	int p=5;
	while(x!=0)
	{
		cnt+=x/d[p];
		x-=d[p]*(x/d[p]);
		p--;
	}
	return cnt;
}

int main()
{
    int c1,c2,c4,c10,c20,c40;
    double nb;
    while(scanf("%d %d %d %d %d %d",&sol[0],&sol[1],&sol[2],&sol[3],&sol[4],&sol[5])==6)
    {
        if(sol[1]==0 && sol[2]==0 && sol[3]==0 && sol[4]==0 && sol[5]==0 && sol[0]==0)
            break;
        else
        {
            scanf("%lf",&nb);
            int asked=(int)(nb*20);
            for (int j=0;j<6;j++) 
            {
				money[0][j]=0;
			}
			for(int i=0;i<=200;++i)
			{
				found[i]=0;
				nbCoins[i]=0;
			}
			found[0]=1;
			for(int i=1;i<=200;++i)
			{
				for(int j=0;j<6;++j)
				{
					if(i>=d[j] && found[i-d[j]] && money[i-d[j]][j]<sol[j])
					{
						if(nbCoins[i]>1+nbCoins[i-d[j]] || nbCoins[i]==0)
						{
							nbCoins[i]=1+nbCoins[i-d[j]];
							for (int t=0;t<6;t++) 
            				{
								money[i][t]=money[i-d[j]][t];
							}
							found[i]=1;
							money[i][j]++;
						}
					}
				}
			}
			//printf("%d\n",asked);
			//printf("%d\n", nbCoins[asked]);
			for(int i=asked+1;i<=200;++i)
			{
				int coins=findCoins(i-asked);
				if((nbCoins[asked]>nbCoins[i]+coins || nbCoins[asked]==0) && nbCoins[i]!=0)
				{
					nbCoins[asked]=nbCoins[i]+coins;
				}
			}
			printf("%3d\n",nbCoins[asked]);
		}
    }
    return 0;
}
