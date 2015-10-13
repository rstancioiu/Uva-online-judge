#include <bits/stdc++.h>
#define N 100100
#define MOD 1000000007

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int MIN(int a,int b){return (a<b)?a:b;}
inline int ABS(int a){return (a>0)?a:-a;}
typedef long long ll;
int n,t;
string a,b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>t;
    cin>>a>>b;
    int doubles=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]==b[i])
            doubles++;
    }
    t=n-t;
    int singles = n - doubles;
    if(n+doubles<2*t)
    	cout<<-1<<endl;
    else
    {
    	string c=a;
    	int cnt=0;
    	for(int i=0;i<n;++i)
    	{
    		if(a[i]==b[i] && cnt<t)
    		{
    			cnt++;
    		}
    		else
    		{
    			for(int j=0;j<26;++j)
    			{
    				if(a[i]!='a'+j && b[i]!='a'+j)
    				{
    					c[i]='a'+j;
    					break;
    				}
    			}
    		}
    	}
    	if(cnt<t)
    	{
    		int cnta=cnt,cntb=cnt;
    		for(int i=0;i<n;++i)
    		{
    			if(cnta<t && a[i]!=b[i])
    			{
    				cnta++;
    				c[i]=a[i];
    			}
    			else if(cntb<t && a[i]!=b[i])
    			{
    				cntb++;
    				c[i]=b[i];
    			}
    		}
    	}
    	cout<<c<<endl;
    }
    return 0;
}