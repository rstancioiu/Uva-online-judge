#include <bits/stdc++.h>
#define N 100010

using namespace std;
map<int,pair<int,pair<int,int> >  > app;
int tab[N];
int n;
int l,r;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>tab[i];
    for(int i=0;i<n;++i)
    {
        map<int,pair<int,pair<int,int> > >::iterator it=app.find(tab[i]);
        if(it==app.end())
            app.insert(make_pair(tab[i],make_pair(1,make_pair(i,i))));
        else
        {
            it->second.first++;
            it->second.second.second=i;
        }
    }
    int maximum=0;
    r=n;
    l=0;
     map<int,pair<int,pair<int,int> > >::iterator it;
    for(it=app.begin();it!=app.end();++it)
    {
        if(it->second.first>maximum)
        {
            maximum=it->second.first;
            r=it->second.second.second;
            l=it->second.second.first;
        }
        else if(it->second.first==maximum)
        {
            if(it->second.second.second - it->second.second.first<r-l)
            {
                r=it->second.second.second;
                l=it->second.second.first;
            }
        }
    }
    cout<<l+1<<" "<<r+1<<endl;
    return 0;
}