#include <bits/stdc++.h>
#define N 512
#define M 3

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int MIN(int a,int b){return (a<b)?a:b;}
inline int ABS(int a){return (a>0)?a:-a;}
typedef pair<int,int> ii;
typedef long long ll;
int mat[N][M];
int vis[N][M];
int t,n,m;
ii s;
string str;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
    	cin>>n>>m;
    	for(int i=0;i<N;++i)
    	{
    		for(int j=0;j<M;++j)
    		{
    			mat[i][j]=0;
    			vis[i][j]=0;
    		}
    	}
    	for(int j=0;j<M;++j)
    	{
    		cin>>str;
    		for(int i=0;i<n;++i)
    		{
    			if(str[i]=='s')
    				s=ii(i,j);
    			else if(str[i]>='A' && str[i]<='Z')
    			{
    				vis[i][j]=2;
    			}
    		}
    	}
    	queue<ii> Q;
    	Q.push(s);
    	bool found=false;
    	while(!Q.empty())
    	{
    		ii t=Q.front();
    		Q.pop();
    		if(t.first==n-1)
    		{
    			found=true;
    			break;
    		}
    		if(vis[t.first*3+1][t.second]!=2)
    		{
    			for(int j=-1;j<=1;++j)
    			{
    				if(t.second+j>=0 && t.second+j<M && !mat[t.first+1][t.second+j])
    				{
    					if(vis[t.first*3+1][t.second+j]!=2 && vis[t.first*3+2][t.second+j]!=2)
    					{
    						mat[t.first+1][t.second+j]=1;
    						Q.push(ii(t.first+1,t.second+j));
    					}
    				}

    			}
    		}
    	}
    	while(!Q.empty()) Q.pop();
    	if(found)
    		cout<<"YES\n";
    	else
    		cout<<"NO\n";
    }
    return 0;
}