#include <bits/stdc++.h>
#define N 6
#define M 16

using namespace std;
int tab[N];
int num[M];
int n;	

void compute(int i,int k)
{
	if(n-i<N-k)
		return;
	if(k==N)
	{
		for(int j=0;j<N-1;++j)
			cout<<tab[j]<<" ";
		cout<<tab[N-1]<<"\n";
		return;
	}
	for(int j=i;j<n;++j)
	{
		tab[k]=num[j];
		compute(j+1,k+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c=0;
	while(cin>>n && n!=0)
	{
		if(c++) cout<<"\n";
		for(int i=0;i<n;++i)
			cin>>num[i];
		compute(0,0);
	}
}