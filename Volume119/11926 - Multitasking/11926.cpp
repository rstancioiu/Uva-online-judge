#include <bits/stdc++.h>
#define N 1000010

using namespace std;

int tab[N];
int aux[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("test.txt","r",stdin);
	int n,m;
	int a,b,d;
	while(cin>>n>>m && !(n==0 && m==0))
	{
		for(int i=0;i<N;++i)
		{
			tab[i]=0;
			aux[i]=0;
		}
		int c=0;
		for(int i=0;i<n;++i)
		{
			cin>>a>>b;
			c++;
			if(!tab[a])
				tab[a]=c;
			else aux[a]=c;
			if(!tab[b])
				tab[b]=c;
			else aux[b]=c;
		}

		for(int i=0;i<m;++i)
		{
			cin>>a>>b>>d;
			c++;
			for(int j=a;j+b-a<N;j+=d)
			{
				if(!tab[j])
					tab[j]=c;
				else aux[j]=c;
			    if(!tab[j+b-a])
					tab[j+b-a]=c;
				else aux[j+b-a]=c;
				c++;
			}
		}
		int prev=0;
		bool conflict=false;
		for(int i=0;i<N;++i)
		{
			if(!prev && tab[i])
            {
                if(aux[i])
                {
                    conflict=true;
                    break;
                }
                prev=tab[i];
            }
			else if(prev && tab[i])
			{
				if(prev==tab[i])
				{
					prev=aux[i];
				}
				else if(prev ==aux[i])
				{
					prev=tab[i];
				}
				else
				{
					conflict=true;
					break;
				}

			}
		}
		if(conflict)
			cout<<"CONFLICT"<<endl;
		else cout<<"NO CONFLICT"<<endl;
	}
	return 0;
}
