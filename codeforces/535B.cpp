#include <bits/stdc++.h>

using namespace std;
string n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int ans=0;
    for(int i=0;i<n.length();++i)
    {
        if(n[i]=='4')
        {
            ans*=2;
        }
        else if(n[i]=='7')
        {   
            ans=(ans<<1)+1;
        }
    }
    cout<<ans-1+(1<<n.length())<<endl;
    return 0;
}