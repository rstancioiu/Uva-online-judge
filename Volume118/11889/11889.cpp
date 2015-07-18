// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/118/11889.html
#include <bits/stdc++.h>

using namespace std;
int t,a,c;

int gcd(int a,int b)
{
    while(b!=0)
    {
        int aux=a%b;
        a=b;
        b=aux;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for(int i=0;i<t;++i)
    {
        cin>>a>>c;
        if(c%a==0)
        {   
            int b=c/a;
            int gprev=1;
            int g=gcd(b,a);
            while(g!=gprev)
            {
                b*=g/gprev;
                gprev=g;
                g=gcd(b,a);
            }
            cout<<b<<endl;
        }
        else cout<<"NO SOLUTION"<<endl;
    }

    return 0;
}