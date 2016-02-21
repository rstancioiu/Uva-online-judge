#include <bits/stdc++.h>
#define N 10

using namespace std;
int t;
int tab[N];
int order[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	cout<<"Lumberjacks:\n";
	while(t--)
	{
		for(int i=0;i<N;++i)
		{
			cin>>tab[i];
			order[i]=tab[i];
		}
		sort(order,order+N);
		bool ordered = false;
		int i;
		for(i=0;i<N;++i)
			if(order[i]!=tab[i])
				break;
		if(i==N)
		{
			cout<<"Ordered\n";
			continue;
		}
		for(i=0;i<N;++i)
			if(order[N-i-1]!=tab[i])
				break;
		if(i==N)
		{
			cout<<"Ordered\n";
			continue;
		}
		cout<<"Unordered\n";
	}
	return 0;
}