#include <bits/stdc++.h>
#define N 1000004

using namespace std;
long long int tab[N];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tab[3]=0;
    for(long long int i=4;i<N;++i)
    {
        tab[i]=tab[i-1];
        if(i%2==0)
        {
            tab[i]+=(i-2)*(i-1)/2-(i-2)*((i-2)/2+1)/2;
        }
        else
        {
            tab[i]+=(i-3)*((i-3)/2+1)/2;
        }
    }
    while(cin>>n && n>=3)
    {
        cout<<tab[n]<<endl;
    }
    return 0;
}