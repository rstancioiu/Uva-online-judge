#include <bits/stdc++.h>

using namespace std;
int n,k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    int cnt=0;
    int aux=n-1;
    for(int i=0;i<k;++i)
    {
        int m,prev,a;
        cin>>m;
        cin>>prev;
        bool b=false;
        if(prev==1)
            b=true;
        for(int j=1;j<m;++j)
        {
            cin>>a;
            if(a==prev+1 && b)
            {
                aux--;
            }
            else
            {
                cnt++;
                b=false;
            }
            prev=a;
        }
    }
    cnt+=aux;
    cout<<cnt<<endl;
    return 0;
}