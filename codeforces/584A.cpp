#include <bits/stdc++.h>
#define N 384
#define M 26

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int MIN(int a,int b){return (a<b)?a:b;}
inline int ABS(int a){return (a>0)?a:-a;}

int n,t;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>t;
    if(t==10 && n==1)
    {
        cout<<-1<<endl;
    }
    else if(t==10)
    {
        cout<<1;
        for(int i=0;i<n-1;++i)
            cout<<0;
        cout<<endl;
    }
    else
    {
        for(int i=0;i<n;++i)
            cout<<t;
        cout<<endl;
    }
    return 0;
}