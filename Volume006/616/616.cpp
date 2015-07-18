#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin>>n && n>=0)
    {
        int ans=-1;
        for(int i=2;i<=9;++i)
        {
            int p=n;
            int j;
            for(j=1;j<=i;++j)
            {
                if((p-1)%i==0)
                {
                    p-=1+p/i;
                }
                else break;
            }
            if(j>i && p%i==0)
            {
                ans=i;
            }
        }
        if(ans==-1)
            cout<<n<<" coconuts, no solution\n";
        else cout<<n<<" coconuts, "<<ans<<" people and 1 monkey\n";
    }
    return 0;
}
