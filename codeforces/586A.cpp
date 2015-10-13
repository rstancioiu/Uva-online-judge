#include <bits/stdc++.h>
#define N 2010

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int MIN(int a,int b){return (a<b)?a:b;}
inline int ABS(int a){return (a>0)?a:-a;}
typedef pair<int,int> ii;
typedef long long ll;
int a[N]={0};
int n;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)
    	cin>>a[i];
    if(n==1)
    {
    	cout<<a[0]<<endl;
    	return 0;
    }
    int cnt=0;
    bool home=true;
    for(int i=0;i<n;++i)
	{
		if(a[i])
		{
			cnt++;
			home=false;
		}
		else if(!a[i] && !home)
		{
			if(a[i]==a[i-1])
			{
				home=true;
				cnt--;
			}
			else
				cnt++;
		}
	}
	if(a[n-1]==0 && a[n-1]!=a[n-2])
		cnt--;
	cout<<cnt<<endl;
    return 0;
}