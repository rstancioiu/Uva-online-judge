#include <bits/stdc++.h>
#define N 128

using namespace std;
int n;
int tab[N][N];
int aux[N][N];
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>s;
		for(int j=0;j<s.length();++j)
		{
			if(s[j]=='0')
				tab[i][j]=0;
			else tab[i][j]=1;
		}
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			aux[i][j]=tab[i][j];
	int maximum=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(aux[i][j]==0)
			{
				for(int p=0;p<n;++p)
				{
					if(aux[p][j]==0)
						aux[p][j]=1;
					else aux[p][j]=0;
				}
			}
		}
		int cnt=0;
		for(int j=0;j<n;++j)
		{
			int p;
			for(p=0;p<n;++p)
			{
				if(!aux[j][p])
					break;
			}
			if(p==n)
				cnt++;
		}
		if(cnt>maximum)
			maximum=cnt;
		for(int j=0;j<n;++j)
			for(int p=0;p<n;++p)
				aux[j][p]=tab[j][p];
	}
	cout<<maximum<<endl;
	return 0;
}