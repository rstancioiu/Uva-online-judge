#include <bits/stdc++.h>
#define N 2010

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int MIN(int a,int b){return (a<b)?a:b;}
inline int ABS(int a){return (a>0)?a:-a;}
typedef pair<int,int> ii;
typedef long long ll;
int p[N],s[N];
int n;
int a[N],b[N];
vector<ii> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
    	cin>>p[i];
    }
    for(int i=1;i<=n;++i)
    {
    	cin>>s[i];
    	b[s[i]]=i;
    }
    for(int i=1;i<=n;++i)
    {
    	if(p[i]==s[i])
    	{
    		p[i]=s[i]=0;
    	}
    }
    int cnt=0;
    for(int i=n-1;i>0;--i)
    {
    	if(p[i])
    	{
    		int prev=i;
    		for(int j=i+1;j<=n;++j)
    		{
    			if(p[j] && p[prev])
    			{
    				if(b[p[prev]]>b[p[j]] && prev>=b[p[j]] && j<=b[p[prev]]) 
    				{
    					cnt+=j-prev;
    					ans.push_back(ii(prev,j));
    					swap(p[prev],p[j]);
    					if(p[prev]==s[prev])
    					{
    						p[prev]=s[prev]=0;
    					}
    					if(p[j]==s[j])
    					{
    						p[j]=s[j]=0;
    					}
    				}
    				prev=j;
    			}
    			else if(p[j])
    				prev=j;
    		}
    	}
    }
    cout<<cnt<<"\n";
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();++i)
    	cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    return 0;
}