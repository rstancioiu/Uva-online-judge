// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/103/10327.html
#include <iostream>
#define N 1024

using namespace std;
int v[N];


int main()
{
	int n,a,aux;
	while(cin>>n)
	{
		for(int i=0;i<n;++i)
		{
			cin>>v[i];
		}
		int cnt=0;
		for(int i=0;i<n;++i)
		{
			for(int j=i;j>=1;--j)
			{
				if(v[j]<v[j-1])
				{
					aux=v[j];
					v[j]=v[j-1];
					v[j-1]=aux;
					cnt++;
				}
			}
		}
		cout<<"Minimum exchange operations : "<<cnt<<endl;
	}
	return 0;
}