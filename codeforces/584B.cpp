#include <bits/stdc++.h>
#define N 100100
#define MOD 1000000007

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int MIN(int a,int b){return (a<b)?a:b;}
inline int ABS(int a){return (a>0)?a:-a;}
typedef long long ll;
int n,t;
ll tab[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    long long int p1=27;
    long long int p2=7;
    long long int ans1=1,ans2=1;
    for(int i=0;(1<<i)<=n;++i)
    {
        if((1<<i)&n)
        {
            ans1=(ans1*p1)%MOD;
            ans2=(ans2*p2)%MOD;
        }
        p1=(p1*p1)%MOD;
        p2=(p2*p2)%MOD;
    }
    cout<<(ans1-ans2+MOD)%MOD<<endl;
    return 0;
}