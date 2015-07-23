#include <bits/stdc++.h>
#define N 128

using namespace std;
int n;
int x,a;
vector<pair<int,int> > neg;
vector<pair<int,int> > pos;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>x>>a;
        if(x<0)
            neg.push_back(make_pair(-x,a));
        else pos.push_back(make_pair(x,a));
    }
    sort(neg.begin(),neg.end());
    sort(pos.begin(),pos.end());
    int maximum=0;
    int sum=0;
    for(int i=0;i<neg.size();++i)
    {
        sum+=neg[i].second;
        if(i<pos.size())
            sum+=pos[i].second;
        else break;
    }
    maximum=sum;
    sum=0;
    for(int i=0;i<pos.size();++i)
    {
        sum+=pos[i].second;
        if(i<neg.size())
            sum+=neg[i].second;
        else break;
    }
    maximum=(maximum>sum)?maximum:sum;
    cout<<maximum<<endl;
    return 0;
}