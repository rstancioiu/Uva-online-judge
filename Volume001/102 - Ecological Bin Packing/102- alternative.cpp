#include <bits/stdc++.h>
#define N 3

using namespace std;
map<int,char> mat;
int tab[N][N];

int main()
{
	mat[0]='B';	
	mat[1]='G';
	mat[2]='C';
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>tab[0][0])
	{
		for(int i=1;i<9;++i)
		{	
			cin>>tab[i/N][i%N];
		}
		int sum=0;
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)		
				sum+=tab[i][j];	
		string answer;
		int minimum = 0x7fffffff;
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<N;++j)
			{
				for(int k=0;k<N;++k)
				{
					if(i!=j && j!=k && k!=i)
					{
						int tmp=sum-tab[0][i]-tab[1][j]-tab[2][k];
						if(tmp<=minimum)
						{
							string s="";
							s+=mat[i];
							s+=mat[j];
							s+=mat[k];
							if(tmp<minimum)
								answer=s;
							else
							{
								for(int p=0;p<N;++p)
								{
									if(answer[p]>s[p])
									{
										answer=s;
										break;
									}	
									else if(answer[p]<s[p])
									{
										break;
									}
								}
							}
							minimum=tmp;
						}

		
					}
				}
			}
		}
		cout<<answer<<" "<<minimum<<"\n";
	}
	return 0;
}