#include <bits/stdc++.h>
#define N 2010

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int MIN(int a,int b){return (a<b)?a:b;}
inline int ABS(int a){return (a>0)?a:-a;}
typedef pair<int,int> ii;
typedef long long ll;
int a[N]={0},b[N]={0},c[N]={0};
int n;
vector<int> ans;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<n;++i)
    	cin>>b[i];
    for(int i=1;i<n;++i)
    	cin>>c[n-i];
    for(int i=0;i<n;++i)
    	cin>>a[i];
    for(int i=1;i<n;++i)
    {
    	b[i]+=b[i-1];
    	c[i]+=c[i-1];
    }
    for(int i=0;i<n;++i)
    {
    	int sum=a[i]+b[i]+c[n-i-1];
    	ans.push_back(sum);
    }
    sort(ans.begin(),ans.end());
    cout<<ans[0]+ans[1]<<endl;
    return 0;
}