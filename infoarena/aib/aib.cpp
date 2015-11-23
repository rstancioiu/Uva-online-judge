#include <bits/stdc++.h>
#define N 100100

using namespace std;
int n,m;
int tab[N]={0};

void add(int x,int val)
{
	while(x<=n){
		tab[x]+=val;
		x+=x&(-x);
	}
}

int get(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=tab[x];
		x-=x&(-x);
	}
	return ret;
}

int posmin(int val)
{
	int high=n;
	int low=1;
	while(low<high)
	{
		int mid=(high+low)/2;
		int newval=get(mid);
		if(newval>=val)
			high=mid;
		else
			low=mid+1;
	}
	int test=get(high);
	if(test==val)
		return high;
	else
		return -1;
}

int t,a,b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("aib.in","r",stdin);
	freopen("aib.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		add(i,a);
	}
	for(int i=0;i<m;++i)
	{
		cin>>t;
		if(t==0)
		{
			cin>>a>>b;
			add(a,b);
		}
		else if(t==1)
		{
			cin>>a>>b;
			cout<<get(b)-get(a-1)<<"\n";
		}
		else
		{
			cin>>a;
			cout<<posmin(a)<<"\n";
		}
	}
}