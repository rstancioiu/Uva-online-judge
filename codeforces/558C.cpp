#include <bits/stdc++.h>
#define N 100010

using namespace std;
int n,a;
pair<int,int> v[N]={pair<int,int>(0,0)};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a;
        int op=0;
        while(a!=0)
        {
            int p=a;
            int opaux=op;
            while(p<N)
            {
               if(v[p].second==i-1)
               {
                v[p].first+=opaux;
                v[p].second++;
               }
               else break;
               opaux++;
               p<<=1;
            }
            a>>=1;
            op++;
        }
    }
    int minimum=0x7fffffff;
    for(int i=1;i<N;++i)
    {
        if(v[i].second==n)
            minimum=(minimum>v[i].first)?v[i].first:minimum;
    }
    cout<<minimum<<endl;
    return 0;
}