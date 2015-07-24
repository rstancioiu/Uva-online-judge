#include <bits/stdc++.h>
#define F 100
#define N 8

using namespace std;
inline int ABS(int a){return (a>0)?a:-a;}
vector<int> tab[N];
int T[F]; 
int m[N][F];
int v[N][F];
int n,k;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(getline(cin,s))
    {
        istringstream iss1(s);
        iss1>>n>>k;
        getline(cin,s);
        istringstream iss2(s);
        for(int i=1;i<=n;++i)
            for(int j=0;j<F;++j)
                m[i][j]=-1;
        for(int i=1;i<=n;++i)
        {
            iss2>>T[i];
        }
        for(int i=1;i<=n;++i)
        {
            getline(cin,s);
            istringstream iss3(s);
            int a;
            while(iss3>>a)
            {
                tab[i].push_back(a);
                m[i][a]=0x1fffffff;
            }
        }
        int i;
        for(i=1;i<=n;++i)
            if(m[i][k]!=-1)
                break;
        if(i==n+1)
            cout<<"IMPOSSIBLE\n";
        else
        {
            priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > Q;
            for(int i=1;i<=n;++i)
                for(int j=0;j<F;++j)
                    v[i][j]=0;
            for(int i=1;i<=n;++i)
            {
                if(m[i][0]!=-1)
                {
                    Q.push(make_pair(0,make_pair(i,0)));
                    v[i][0]=1;
                    m[i][0]=0;
               }
            }
            while(!Q.empty())
            {
                int t1 = Q.top().second.first;
                int t2 = Q.top().second.second;
                Q.pop();
                for(int j=0;j<tab[t1].size();++j)
                {
                    if(!v[t1][tab[t1][j]])
                    {
                        int d= ABS(tab[t1][j]-t2)*T[t1];
                        if(m[t1][tab[t1][j]]>m[t1][t2]+d)
                        {
                            m[t1][tab[t1][j]] =m[t1][t2]+d;
                            Q.push(make_pair(m[t1][tab[t1][j]],make_pair(t1,tab[t1][j])));
                        }
                    }
                }
                for(int i=1;i<=n;++i)
                {
                    if(!v[i][t2])
                    {
                        int d=60;
                        if(m[i][t2]>m[t1][t2]+d)
                        {
                            m[i][t2] =m[t1][t2]+d;
                            Q.push(make_pair(m[i][t2],make_pair(i,t2)));
                        }
                    }
                }
                v[t1][t2]=1;
            }
            int minimum=0x1fffffff;
            for(int i=1;i<=n;++i)
            {
                if(m[i][k]!=-1 && minimum>m[i][k])
                    minimum=m[i][k];
            }
            if(minimum==0x1fffffff)
                  cout<<"IMPOSSIBLE\n";
            else
                cout<<minimum<<endl;
            for(int i=1;i<=n;++i)
                tab[i].clear();
        }
    }

    return 0;
}