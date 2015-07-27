#include <bits/stdc++.h>
#define N 52

using namespace std;
int n;
long long int k;
long long int tab[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cin>>k;
    k--;
    tab[0]=0;
    tab[1]=1;
    for(int i=2;i<=n;++i)
    {
        tab[i]=tab[i-1]+tab[i-2];
    }
    vector<int> res;
    res.push_back(1);
    for(int j=n-1;j>=1;--j)
    {
        res.push_back(n-j+1);
        if(k>=tab[j+1])
        {
            k-=tab[j+1];
            int prev=res[res.size()-2];
            int aux=res[res.size()-1];
            res[res.size()-1]=prev;
            res[res.size()-2]=aux;

            for(int p=res.size()-3;p>=0;--p)
            {
                if(res[p]>prev)
                {
                    int aux=res[p];
                    res[p]=res[p+1];
                    res[p+1]=aux;
                    prev=res[p];
                }
                else break;
            }
        }
    }
    for(int i=0;i<res.size()-1;++i)
        cout<<res[i]<<" ";
    cout<<res[res.size()-1]<<endl;
    return 0;
}