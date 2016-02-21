#include <bits/stdc++.h>
#define N 128
#define DIR 8

using namespace std;
int n,m,q;
int t;
string mat[N];
string s;
int x[DIR]={0,0,1,-1,1,1,-1,-1};
int y[DIR]={1,-1,0,0,1,-1,1,-1};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int c=0;c<t;++c)
	{
		if(c) cout<<"\n";
		cin>>n>>m;
		for(int i=0;i<n;++i)
			cin>>mat[i];
		cin>>q;
		for(int p=0;p<q;++p)
		{
			cin>>s;
			bool sol = false;
			for(int i=0;i<n && !sol;++i)
			{
				for(int j=0;j<m && !sol;++j)
				{
					if((mat[i][j]-s[0])%32==0)
					{
						for(int k=0;k<DIR && !sol;++k)
						{
							int l;
							for(l=0;l<s.length();++l)
							{
								int p1=i+x[k]*l;
								int p2=j+y[k]*l;
								if(!(p1>=0 && p2>=0 && p1<n && p2<m && (mat[p1][p2]-s[l])%32==0))
									break;
							}
							if(l==s.length())
							{
								sol=true;
								cout<<i+1<<" "<<j+1<<"\n";
							}
						}
					}
				}
			}
		}
	}

	return 0;
}