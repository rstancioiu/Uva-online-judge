#include <bits/stdc++.h>
#define N 100010

using namespace std;
int n;

inline int MIN(int a,int b){return (a>b)?b:a;}
inline int MAX(int a,int b){return (a<b)?b:a;}

set<int> s;
char type;
int id;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int ans=0;
    int maximum=0;
    for(int i=0;i<n;++i)
    {
        cin>>type>>id;
        if(type=='+')
        {
            s.insert(id);
            ans++;
            maximum=(maximum<ans)?ans:maximum;
        }
        else if(type=='-')
        {
            set<int>::iterator it=s.find(id);
            if(it==s.end())
                maximum++;
            else
            {
                ans--;
                s.erase(it);
            }
        }
    }
    cout<<maximum<<endl;
    return 0;
}