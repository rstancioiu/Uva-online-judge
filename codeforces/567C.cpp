#include <bits/stdc++.h>
#define N 200010

using namespace std;
int n,k,a;
int tab[N];

inline int MIN(int a,int b){return (a>b)?b:a;}
inline int MAX(int a,int b){return (a<b)?b:a;}
inline long long int ABS(long long int a){return (a>0)?a:-a;}

long long int LIM=1147483647;

map<int,vector<int> > m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        cin>>a;
        tab[i]=a;
        map<int,vector<int> >::iterator it=m.find(a);
        if(it==m.end())
        {
            vector<int> s;
            s.push_back(i);
            m.insert(make_pair(a,s));
        }
        else it->second.push_back(i);
    }
    long long int ans=0;
    map<int,vector<int> >::iterator it=m.find(0);
    if(it!=m.end() && k!=1)
    {
        long long int t=it->second.size();
        ans+=t*(t-1)*(t-2)/6;
    }
    if(k==1)
    {
        map<int,vector<int> >::iterator it=m.begin();
        for(;it!=m.end();++it)
        {
            long long int t=it->second.size();
            ans+=t*(t-1)*(t-2)/6;
        }
    }
    else
    {
        map<int,vector<int> >::iterator it1,it2,it3;
        for(it1=m.begin();it1!=m.end();++it1)
        {
            long long int a=it1->first;
            if(ABS(a*k*k)<LIM && a!=0)
            {
                it2=m.find(a*k);
                it3=m.find(a*k*k);
                if(it2!=m.end() && it3!=m.end())
                {
                    int l1=it1->second.size();
                    int l2=it2->second.size();
                    int l3=it3->second.size();
                    int i,j,p;
                    for(i=0,j=0,p=0;i<l1 && j<l2 && p<l3;)
                    {
                        if(it2->second[j]> it3->second[p])
                            p++;
                        else if(it1->second[i]>it2->second[j])
                        {
                            if(i>0 && it1->second[i-1]<it2->second[j])
                            {
                                ans+=(long long int)i*(l3-p);
                            }
                            j++;
                        }
                        else if(i==l1-1)
                        {
                            ans+=(long long int)l1*(l3-p);
                            j++;
                        }
                        else
                        {
                            i++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}