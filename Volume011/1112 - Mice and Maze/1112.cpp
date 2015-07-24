#include <bits/stdc++.h>
#define N 104

using namespace std;
vector<pair<int,int> > v[N];
int n,m,e,t;
int T;
int a,b,d;
int dist[N];
int check[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        cin>>e;
        cin>>t;
        cin>>m;
        for(int i=0;i<m;++i)
        {
            cin>>a>>b>>d;
            v[b].push_back(make_pair(a,d));
        }
        for(int i=1;i<=n;++i)
        {
            dist[i]=0x3f3f3f3f;
            check[i]=0;
        }

        queue<int> Q;
        Q.push(e);
        dist[e]=0;
        check[e]=1;
        while(!Q.empty())
        {
            int p=Q.top();
            check[p]=0;
            Q.pop();
            for(int i=0;i<v[p].size();++i)
            {
                 if(dist[v[p][i].first]>dist[p]+v[p][i].second)
                 {
                     dist[v[p][i].first] = dist[p]+v[p][i].second;
                     if(!check[v[p][i].first])
                     {
                    	 Q.push(v[p][i].first);
                    	 check[v[p][i].first]=1;
                     }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            if(dist[i]<=t)
                ans++;
        }
        for(int i=0;i<=n;++i)
        	v[i].clear();
        cout<<ans<<endl;
         if(T)
            cout<<endl;
    }
    return 0;
}