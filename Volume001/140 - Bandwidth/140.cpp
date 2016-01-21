#include <bits/stdc++.h>
#define N 26

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int MIN(int a,int b){return (a<b)?a:b;}
inline int ABS(int a){return (a>0)?a:-a;}
string s;
int tab[N],ans[N];
int mat[N][N];
int best;

void backtrack(int pos, int size)
{
	if(pos==size)
	{
		int maximum=0;
		for(int i=0;i<size;++i)
		{
			for(int j=i+1;j<size;++j)
			{
				if(mat[tab[i]][tab[j]] || mat[tab[j]][tab[i]])
					maximum=MAX(maximum,j-i);
			}
		}
		if(maximum<best)
		{
			best=maximum;
			for(int i=0;i<size;++i)
				ans[i]=tab[i];
		}
		else if(maximum==best)
		{
			for(int i=0;i<size;++i)
			{
				if(ans[i]>tab[i])
				{
					for(int j=0;j<size;++j)
						ans[j]=tab[j];
					break;
				}
				else if(ans[i]<tab[i])
					break;
			}
		}
		return;
	}
	for(int i=pos;i<size;++i)
	{
		swap(tab[pos],tab[i]);
		backtrack(pos+1,size);
		swap(tab[pos],tab[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(getline(cin,s) && s[0]!='#')
	{
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				mat[i][j]=0;

		int c=s[0]-'A';
		for(int i=2;i<s.length();)
		{
			if(s[i]==';')
			{
				c=s[i+1]-'A';
				i+=3;
			}
			else
			{
				if(s[i]>='A' && s[i]<='Z')
				{
					mat[c][s[i]-'A']=1;
				}
				i++;
			}
		}
		vector<int> nodes;
		for(int i=0;i<s.length();++i)
		{
			if(s[i]>='A' && s[i]<='Z')
			{
				int j;
				int p = s[i]-'A';
				for(j=0;j<nodes.size();++j)
					if(p==nodes[j])
						break;
				if(j==nodes.size())
					nodes.push_back(p);
			}
		}
		sort(nodes.begin(),nodes.end());
		best=nodes.size()+1;
		for(int i=0;i<nodes.size();++i)
			tab[i]=nodes[i];
		backtrack(0,nodes.size());
		for(int i=0;i<nodes.size();++i)
			cout<<(char)(ans[i]+'A')<<" ";
		cout<<"-> "<<best<<endl;
	}
	return 0;
}