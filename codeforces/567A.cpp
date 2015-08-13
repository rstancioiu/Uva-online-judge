#include <bits/stdc++.h>
#define N 100010

using namespace std;
string s;
int n;
pair<int,int> tab[N];
pair<int,pair<int,int> > ans[N];

inline int MIN(int a,int b){return (a>b)?b:a;}
inline int MAX(int a,int b){return (a<b)?b:a;}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)
    {
        tab[i].second=i;
        cin>>tab[i].first;
    }
    sort(tab,tab +n);
    ans[0].first=tab[0].second;
    ans[0].second.first=tab[1].first-tab[0].first;
    ans[0].second.second=tab[n-1].first-tab[0].first;
    ans[n-1].first=tab[n-1].second;
    ans[n-1].second.first=tab[n-1].first-tab[n-2].first;
    ans[n-1].second.second=tab[n-1].first-tab[0].first;
    for(int i=1;i<n-1;++i)
    {
        ans[i].first=tab[i].second;
        ans[i].second.first=MIN(tab[i].first-tab[i-1].first,tab[i+1].first-tab[i].first);
        ans[i].second.second=MAX(tab[i].first-tab[0].first,tab[n-1].first-tab[i].first);
    }
    sort(ans,ans+n);
    for(int i=0;i<n;++i)
    {
        cout<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
    }
    return 0;
}