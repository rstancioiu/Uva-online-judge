#include <bits/stdc++.h>
#define N 1024

using namespace std;
typedef pair<int,int> ii;
int n,m,b;
string s;
int a[N];
int v[N]={0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
    	cin>>a[i];
    int change=0;
    int cnt=0;
    while(cnt<n)
    {
    	if(change%2==0)
    	{
    		for(int i=1;i<=n;++i)
    		{
    			if(!v[i] && a[i]<=cnt)
    			{
    				cnt++;
    				v[i]=1;
    			}
    		}
    	}
    	else
    	{
    		for(int i=n;i>=1;--i)
    		{
    			if(!v[i] && a[i]<=cnt)
    			{
    				cnt++;
    				v[i]=1;
    			}
    		}
    	}
    	change++;
    }
    cout<<change-1<<endl;
    return 0;
}