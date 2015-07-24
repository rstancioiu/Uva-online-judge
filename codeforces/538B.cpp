#include <bits/stdc++.h>
#define N 8
#define M 1000004

using namespace std;
vector<int> tab[N];
int v[M];
int n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	tab[0].push_back(0);
	for(int i=1;i<=6;++i)
    {
        for(int j=0;j<tab[i-1].size();++j)
        {
            tab[i].push_back(tab[i-1][j]*10);
            tab[i].push_back(tab[i-1][j]*10+1);
        }
    }
    tab[7].push_back(1000000);
    for(int i=0;i<=n;++i)
        v[i]=0;
    v[0]=1;
    for(int i=1;i<=7;++i)
    {
        for(int j=0;j<tab[i].size();++j)
        {
            for(int k=tab[i][j];k<=n;++k)
            {
                if(v[k-tab[i][j]]>0)
                {
                    if(v[k]>0)
                        v[k]=(v[k]>(v[k-tab[i][j]]+1))?(v[k-tab[i][j]]+1):v[k];
                    else v[k]=v[k-tab[i][j]]+1;
                }

            }
        }
    }

    cout<<v[n]-1<<endl;
    int prev=n;
    bool first=true;
    while(prev)
    {
        for(int i=1;i<=7 && prev;++i)
        {
            for(int j=0;j<tab[i].size() && prev;)
            {
                if(prev>=tab[i][j] && v[prev]==v[prev-tab[i][j]]+1)
                {
                    if(first)
                    {
                        cout<<tab[i][j];
                        first=!first;
                    }
                    else cout<<" "<<tab[i][j];
                    prev-=tab[i][j];
                 }
                 else j++;
            }
        }
    }
    cout<<endl;
	return 0;
}