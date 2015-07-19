// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/103/10324.html
#include <bits/stdc++.h>
#define N 1000005

using namespace std;
string s;
int n;
int i,j;
int v[N];

inline int MIN(int a,int b){return (a>b)?b:a;}
inline int MAX(int a,int b){return (a>b)?a:b;}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(cin>>s && cin>>n)
    {
        v[0]=0;
        for(int p=1;p<=s.length();++p)
        {
            v[p]=v[p-1]+s[p-1]-'0';
        }
        cout<<"Case "<<t++<<":\n";
        for(int k=0;k<n;++k)
        {
            cin>>i>>j;
            int a=MIN(i,j);
            int b=MAX(i,j);
            a++;
            b++;
            if(a<=0) a=1;
            if(b>s.length()) b=s.length();
            if(v[a-1]==v[b] || v[b]-v[a-1]==b-a+1)
                cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}