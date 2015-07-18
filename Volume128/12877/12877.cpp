#include <bits/stdc++.h>
#define N 10
#define M 27

using namespace std;
int tab[M];
vector<int> ch;
int v[M];
int head[M];
queue<int> visited;
string s[N];
vector<int> str[N];
int rsize;
int n;
int ans;

void Compute(int p)
{
    if(p==ch.size())
    {
        int t=0;
        for(int i=0;i<rsize ;++i)
        {
            for(int j=0;j<n-1;++j)
                if(i<str[j].size())
                    t+=tab[str[j][i]];
            if(t%10!=tab[str[n-1][i]])
                return;
            t/=10;
        }
        if(t==0)
            ans++;
    }
    else
    {
        int x=visited.size();
        for(int cnt=0;cnt<x;cnt++)
        {
            tab[ch[p]]=visited.front();
            visited.pop();
            if(head[ch[p]]!=1 || tab[ch[p]]!=0)
            {
                Compute(p+1);
            }
             visited.push(tab[ch[p]]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n)
    {
        ans=0;
        for(int i=0;i<M;++i)
        {
            v[i]=0;
            head[i]=0;
        }
        for(int i=0;i<n;++i)
            cin>>s[i];
        for(int i=0;i<n;++i)
            reverse(s[i].begin(),s[i].end());
        for(int i=0;i<=9;++i)
            visited.push(i);
        for(int i=0;i<n;++i)
        {
            int l =s[i].length();
            for(int j=0;j<l;++j)
            {
                str[i].push_back(s[i][j]-'A');
                if(!v[str[i][j]])
                {
                    ch.push_back(str[i][j]);
                    v[str[i][j]]=1;
                }
            }
            head[str[i][l-1]]=1;
        }
        rsize = str[n-1].size();
        Compute(0);
        cout<<ans<<endl;
        while(!visited.empty())
            visited.pop();
        ch.clear();
        for(int i=0;i<N;++i)
            str[i].clear();
    }

    return 0;
}
