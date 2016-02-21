#include <bits/stdc++.h>
#define N 128

using namespace std;
int n;
string tab[N];

void validate(int i,int j)
{
	if(i<0 || j<0 || i>=n || j>=n) return;
	if(tab[i][j]=='0') return;
	tab[i][j]='0';
	for(int p1=-1;p1<=1;++p1)
		for(int p2=-1;p2<=1;++p2)
			if(p1!=0 || p2!=0)
				validate(i+p1,j+p2);
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c=1;
	while(cin>>n)
	{
		for(int i=0;i<n;++i)
			cin>>tab[i];
		int ans=0;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(tab[i][j]=='1')
				{
					ans++;
					validate(i,j);
				}
			}
		}
		cout<<"Image number "<<c++<<" contains "<<ans<<" war eagles.\n";
	}
	return 0;
}