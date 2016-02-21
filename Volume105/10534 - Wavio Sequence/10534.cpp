#include <bits/stdc++.h>
#define N 10010

using namespace std;
inline int MIN(int a,int b){return (a>b)?b:a;}
inline int MAX(int a,int b){return (a<b)?b:a;}
int n;
int tab[N];
int incr[N];
int desc[N];
int aux[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n)
	{
		for(int i=0;i<n;++i)
		{
			cin>>tab[i];
			incr[i]=desc[i]=aux[i]=0;
		}
		int len=1;
		incr[0]=1;
		aux[0]=tab[0];
		for(int i=1;i<n;++i)
		{
			if(tab[i]<aux[0]) aux[0]=tab[i],incr[i]=1;
			else if(tab[i]>aux[len-1])
			{
				aux[len++]=tab[i];
				incr[i]=len;
			}
			else
			{
				int low=-1;
				int high=len-1;
				while(low+1<high)
				{
					int m = (high+low)/2;
					if(aux[m]>=tab[i]) high = m;
					else low = m;
	
				}
				aux[high]=tab[i];
				incr[i] = high+1;
			}
		}
		for(int i=0;i<n;++i)
			aux[i]=0;
		len=1;
		desc[n-1]=1;
		aux[0]=tab[n-1];
		for(int i=n-2;i>=0;--i)
		{

			if(tab[i]<aux[0]) 
			{
				aux[0]=tab[i];
				desc[i]=1;
			}
			else if(tab[i]>aux[len-1])
			{
				aux[len++]=tab[i];
				desc[i]=len;
			}
			else
			{
				int low=-1;
				int high=len-1;
				while(low+1<high)
				{
					int m = (high+low)/2;
					if(aux[m]>=tab[i]) high = m;
					else low = m;
	
				}
				aux[high]=tab[i];
				desc[i] = high+1;
			}
		}
		int ans=0;
		for(int i=0;i<n;++i)
		{
			int p = MIN(incr[i],desc[i]);
			if(ans<p)
				ans=p;
		}
		cout<<2*ans-1<<"\n";
	}
	return 0;
}