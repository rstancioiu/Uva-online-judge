#include <bits/stdc++.h>
#define N 2001

using namespace std;
int t,n,a;
unordered_map<int,int> v;
int tab[N];
int mp[N][N]={0};

int main()
{
    freopen("progr2.in","r",stdin);
    freopen("progr2.out","w",stdout);
    ios_base::sync_with_stdio(0);
    unordered_map<int,int>::iterator it;
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;++i)
        {
            cin>>tab[i];
            v.insert(make_pair(tab[i],i));
        }
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
                mp[i][j]=1; 
        long long int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                int p=tab[j]+tab[j]-tab[i];
                it=v.find(p);
                if(it!=v.end() && it->second>j)
                    mp[j][it->second]+=mp[i][j];
                else
                    ans+=mp[i][j]*(mp[i][j]+1)/2;
            }
        }    
        cout<<ans<<"\n";
        v.clear();
    }
    return 0;
}