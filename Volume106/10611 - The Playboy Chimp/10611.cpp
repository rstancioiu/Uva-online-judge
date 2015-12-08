#include <bits/stdc++.h>
#define N 50100

using namespace std;
int n,q,a;
int tab[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int j=0;
	cin>>tab[j++];
	for(int i=1;i<n;++i)
	{
		cin>>a;
		if(tab[j-1]!=a)
			tab[j++]=a;
	}
	cin>>q;
	for(int i=0;i<q;++i)
	{
		cin>>a;
		if(a<tab[0])
		{
			cout<<"X "<<tab[0]<<"\n";
		}
		else if(a==tab[0])
		{
			if(j==1)
			{
				cout<<"X X"<<"\n";
			}
			else 
				cout<<"X "<<tab[1]<<"\n";
		}
		else if(a==tab[j-1])
		{
			cout<<tab[j-2]<<" X"<<"\n";
		}
		else if(a>tab[j-1])
		{
			cout<<tab[j-1]<<" X"<<"\n";
		}
		else
		{
			int low=0;
			int high=j-1;
			while(low+1<high)
			{
				int middle = low+(high-low)/2;
				if(a>=tab[middle])
					low=middle;
				else 
					high=middle;
			}
			if(a==tab[low])
			{
				cout<<tab[low-1]<<" "<<tab[low+1]<<"\n";
			}
			else
			{
				cout<<tab[low]<<" "<<tab[low+1]<<"\n";
			}
		}
	}
	return 0;
}