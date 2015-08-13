#include <bits/stdc++.h>
#define N 200010

using namespace std;
int n,m,k,a;
int tab[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k>>a>>m;
    set<int> s;
    s.insert(0);
    s.insert(n+1);

    for(int i=1;i<=m;++i)
        cin>>tab[i];
    int maximum=(n+1)/(a+1);
    if(maximum<k)
    {
        cout<<0<<endl;
        return 0;
    }
    int i;
    for(i=1;i<=m;++i)
    {
         set<int>::iterator it=s.find(tab[i]);
         if(it==s.end())
         {
             it=s.insert(tab[i]).first;
             set<int>::iterator prev=(--it);
             ++it;
             set<int>::iterator forw=(++it);
             it--;
             int dif=((*forw)-(*prev))/(a+1) - ((*forw)-(*it))/(a+1) -((*it)-(*prev))/(a+1);
             maximum-=dif;
             if(maximum<k)
                break;
         }
    }
    if(i==m+1)
        cout<<-1<<endl;
    else cout<<i<<endl;
    return 0;
}
