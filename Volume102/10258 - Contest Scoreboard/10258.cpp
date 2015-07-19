#include <bits/stdc++.h>
#define N 101
#define P 10

using namespace std;
int C;
string s;
int c,p,t;
char l;
int tab[N][P];
int correct[N][P];
int solved[N];
int times[N];
int submission[N];
multimap<int,int> ans[P];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>C;
    getline(cin,s);
    getline(cin,s);
    for(int i=0;i<C;++i)
    {
        if(i)
            cout<<endl;
        for(int j=1;j<N;++j)
        {
            solved[j]=0;
            times[j]=0;
            submission[j]=0;
            for(int k=1;k<P;++k)
            {
                tab[j][k]=0;
                correct[j][k]=0;
            }
        }
        while(getline(cin,s))
        {
            if(s=="")
                break;
            istringstream iss(s);
            iss>>c>>p>>t;
            iss>>l;
            submission[c]++;
            if(l=='C')
            {
                if(!correct[c][p])
                {
                    correct[c][p]=1;
                    tab[c][p]+=t;
                    solved[c]++;
                    times[c]+=tab[c][p];
                }
            }
            else if(l=='I')
            {
                if(!correct[c][p])
                {
                    tab[c][p]+=20;
                }
            }
        }
        for(int j=0;j<N;++j)
        {
            if(submission[j])
            {
                ans[solved[j]].insert(make_pair(times[j],j));
            }
        }
        for(int j=P-1;j>=0;--j)
        {
            multimap<int,int>::iterator it;
            for(it=ans[j].begin();it!=ans[j].end();++it)
            {
                cout<<it->second<<" "<<j<<" "<<it->first<<endl;
            }
            ans[j].clear();
        }
    }
    return 0;
}