#include <bits/stdc++.h>
#define N 128

using namespace std;
typedef pair<int,int> ii;
int n,m,a,b;
string s;
int tab1[N]={0};
int tab2[N]={0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n*n;++i)
    {
    	cin>>a>>b;
    	if(!tab1[a] && !tab2[b])
    	{
    		tab1[a]=1;
    		tab2[b]=1;
    		cout<<i<<" ";
    	}
    }
    return 0;
}