#include <bits/stdc++.h>
#define N 1000010

using namespace std;

int gcd(int a,int b)
{
    while(b!=0)
    {
        int aux=a%b;
        a=b;
        b=aux;
    }
    return a;
}

int tab[N];

int r,s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n)
	{
		int p=0;
		for(int i=1;i<=n;++i)
			tab[i]=0;
		int sq=sqrt(n);
		for(int i=1;i<=sq;++i)
		{
			for(int j=i+1;j<=sq;++j)
			{
			    if(gcd(i+j,j-i)==1)
                {
                    int z=i*i+j*j;
                    int x=2*i*j;
                    int y=j*j-i*i;
                    if(z<=n)
                    {
                        p++;
                        int k=1;
                        while(z*k<=n)
                        {
                            tab[x*k]=1;
                            tab[y*k]=1;
                            tab[z*k]=1;
                            k++;
                        }
                    }
                }
			}
		}
		int r=0;
		for(int i=1;i<=n;++i)
			if(!tab[i])
				r++;
		cout<<p<<" "<<r<<endl;
	}

	return 0;
}
