#include <cstring>
#include <cstdio>
#define N 1024
#define SN 20000

char a[SN];
char b[SN];
int tab1[N];
int tab2[N];
int t;
int k;
int Compute(char* s,int tab[N],int i,int nbPixel)
{
	if(i==strlen(s) || k==N)
		return 0;
	if(s[i]=='p')
		for(int j=1;j<=4;j++)
		{
			i = Compute(s,tab,i+1,nbPixel/4);
		}
	else if(s[i]=='f')
	{
		for(int j=k;j<k+nbPixel;j++)
			tab[j]=1;
		k+=nbPixel;
	}
	else if(s[i]=='e')
	{
		for(int j=k;j<k+nbPixel;j++)
			tab[j]=0;
		k+=nbPixel;
	}
	return i;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		scanf("%s",b);
		for(int i=0;i<N;++i)
		{
			tab1[i]=0;
			tab2[i]=0;
		}
		k=0;
		Compute(a,tab1,0,N);
		k=0;
		Compute(b,tab2,0,N);
		int count=0;
		for(int i=0;i<N;++i)
			if(tab1[i]==tab2[i])
				count+=tab1[i];
			else count+=tab1[i]+tab2[i];
		printf("There are %d black pixels.\n",count);
	}
	return 0;
}
