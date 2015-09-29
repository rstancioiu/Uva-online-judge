#include <bits/stdc++.h>
#define N 64

using namespace std;
int n,m;
string v[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
	}
	int cnt=0;
	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<m-1;++j)
		{
			int f=0;
			int a=0;
			int e=0;
			int c=0;
			for(int t1=0;t1<=1;++t1)
			{
				for(int t2=0;t2<=1;++t2)
				{
					if(v[i+t1][j+t2]=='a')
						a++;
					else if(v[i+t1][j+t2]=='f')
						f++;
					else if(v[i+t1][j+t2]=='c')
						c++;
					else if(v[i+t1][j+t2]=='e')
						e++;
				}
			}
			if(f==1 && a==1 && c==1 && e==1)
				cnt++;
		}
	}
	cout<<cnt<<"\n";
	return 0;
}