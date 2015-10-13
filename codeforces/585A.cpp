#include <bits/stdc++.h>
#define N 4010

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int MIN(int a,int b){return (a<b)?a:b;}
inline int ABS(int a){return (a>0)?a:-a;}
typedef pair<int,int> ii;
typedef long long ll;
int v[N],d[N],p[N];
int n;
vector<int> ans;
vector<int> neg;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
    	cin>>v[i]>>d[i]>>p[i];
    for(int i=1;i<=n;++i)
    {
    	if(p[i]>=0)
    	{
    		ans.push_back(i);

    		for(int k=v[i],j=i+1;j<=n && k>0;j++)
    		{
    			if(p[j]>=0)
    			{
    				p[j]-=k;
    				--k;
    				if(p[j]<0)
    					neg.push_back(j);
    			}
    		}
    		if(neg.size()>0)
    		{
    			int sum=d[neg[0]];
    			for(int i=neg[0]+1,j=1;i<=n;++i)
    			{
    				if(j<neg.size() && i==neg[j])
    				{
    					j++;
    					sum+=d[i];
    				}
    				else if(p[i]>=0)
    				{
    					p[i]-=sum;
    					if(p[i]<0)
    					{
    						sum+=d[i];
    					}
    				}
    			}
    			neg.clear();
    		}
    	}
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i)
    	cout<<ans[i]<<" ";
    return 0;
}