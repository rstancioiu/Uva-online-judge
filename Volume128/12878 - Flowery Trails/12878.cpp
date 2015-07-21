#include <bits/stdc++.h>
#define N 10010

using namespace std;
typedef pair<int,int> ii;
vector<ii> v[N];
vector<ii> prev[N];
int visited[N];
int tab[N];
int p1,p2,l;
int p,t;
int ans;

void Dijkstra()
{
    int source=0;
    vector<ii>::iterator it;
    priority_queue<ii ,vector<ii>,less<ii> > pq;
    tab[source]=0;
    pq.push(make_pair(tab[source],source));
    while(!pq.empty())
    {
        ii p = pq.top();
        pq.pop();
        int d=p.first;
        int a=p.second;
        visited[a]=0;
        for(int i=0;i<v[a].size();++i)
        {
            if(tab[v[a][i].first]>tab[a]+v[a][i].second)
            {
                prev[v[a][i].first].clear();
                if(!visited[v[a][i].first])
                {
                   visited[v[a][i].first]=1;
                   pq.push(ii(tab[v[a][i].first],v[a][i].first));
                }
                prev[v[a][i].first].push_back(ii(a,v[a][i].second));
                tab[v[a][i].first]=tab[a]+v[a][i].second;
            }
            else if(tab[v[a][i].first]==tab[a]+v[a][i].second)
            {
                prev[v[a][i].first].push_back(ii(a,v[a][i].second));
            }
        }
    }
    queue<int> fifo;
    fifo.push(p-1);
    for(int i=0;i<p;++i)
        tab[i]=0;
    ans=0;
    while(!fifo.empty())
    {
        int t = fifo.front();
        fifo.pop();
        for(int i=0;i<prev[t].size();++i)
        {
            if(!tab[prev[t][i].first])
            {
                fifo.push(prev[t][i].first);
                tab[prev[t][i].first]=1;
            }
            ans+=prev[t][i].second;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.txt","r",stdin);
    while(cin>>p>>t)
    {
        for(int i=0;i<t;++i)
        {
            cin>>p1>>p2>>l;
            v[p1].push_back(make_pair(p2,l));
            v[p2].push_back(make_pair(p1,l));
        }
        for(int i=0;i<p;++i)
        {
            tab[i]=0x1fffffff;
        }
        Dijkstra();
        cout<<2*ans<<endl;
        for(int i=0;i<p;++i)
        {
            v[i].clear();
            prev[i].clear();
        }
    }
    return 0;
}
