#include <bits/stdc++.h>
#define N 2001
#define MOD 123567

using namespace std;
int t,n,a;
int tab[N];
vector<int> v[MOD];

void add(int val)
{
    int k=val%MOD;
    v[k].push_back(val);
}

int search(int val)
{
    int k=val%MOD;
    for(unsigned int i=0;i<v[k].size();++i)
        if(v[k][i]==val)
            return 1;
    return 0;
}

void erase()
{
    for(int i=0;i<MOD;++i)
        v[i].clear();
}

int main()
{
    freopen("progr.in","r",stdin);
    freopen("progr.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;++i)
        {
            cin>>tab[i];
            add(tab[i]);
        }
        sort(tab,tab+n);
        int ans=0;
        for(int i=0;i<n;++i)
        {
            int a=tab[i];
            for(int j=i+1;j<n;++j)
            {
                if(!search((tab[j]<<1)-a))
                    ans++;
            }
        }      
        cout<<ans<<"\n";
        erase();
    }
    return 0;
}