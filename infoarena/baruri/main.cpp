#include <bits/stdc++.h>
#define N (1<<17)

using namespace std;
int tab[N];
int sav[N];

int t,n,m,a,b,x,d,type;


void Update(int poz,int val)
{
	while(poz<=n)
	{
		tab[poz]+=val;
		poz+=(poz & -poz);
	}
}

int Query(int poz)
{
	int S=0;
	while(poz)
	{
		S+=tab[poz];
		poz-=(poz& -poz);
	}
	return S;
}


int main()
{
	freopen("baruri.in","r",stdin);
	freopen("baruri.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		fill(tab,tab+n+1,0);
		for(int i=1;i<=n;++i)
		{
			cin>>a;
			Update(i,a);
			sav[i]=a;
		}
		cin>>m;
		for(int i=0;i<m;++i)
		{
			cin>>type;
			if(type==0)
			{
				cin>>b>>d;
				int left=b-d-1,right=b+d;
				if(b-d-1<=0)
					left=0;
				if(b+d>=n)
					right=n;
				cout<<Query(right)-Query(left)-sav[b]<<"\n";

			}
			else if(type==1)
			{
				cin>>x>>b;
				sav[b]+=x;
				Update(b,x);
			}
			else if(type==2)
			{
				cin>>x>>b;
				sav[b]-=x;
				Update(b,-x);
			}
			else if(type==3)
			{
				cin>>x>>a>>b;
				sav[a]-=x;
				sav[b]+=x;
				Update(a,-x);
				Update(b,x);
			}
		}
	}
	return 0;
}
