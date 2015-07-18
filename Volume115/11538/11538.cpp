#include <iostream>

using namespace std;
long long int n,m;

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n>>m && !(n==0 && m==0))
    {
        if(n>m)
            swap(n,m);
        long long int ans=n*m*(n+m-2);
        ans+=2*n*(n-1)*(m+n-1)-4*n*(n-1)*(2*n-1)/3;
        cout<<ans<<endl;
    }
    return 0;
}