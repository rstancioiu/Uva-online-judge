#include <iostream>
#define N 1002

using namespace std;
int t,n;
int aux[N];
int tab[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    t=1;
    tab[1]=1;
    for(int i=2;i<N;++i)
    {
        tab[i]=-1;
        int ans=0;
        for(int j=1;j<=i;++j)
        {
            if(i%j==0)
                ans+=j;
        }
        aux[i]=ans;
    }
    for(int i=2;i<N;++i)
    {
        if(aux[i]<N)
            tab[aux[i]]=i;
    }
    while(cin>>n && n!=0)
    {
        cout<<"Case "<<t++<<": "<<tab[n]<<endl;
    }
    return 0;
}
