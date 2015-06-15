#include <bits/stdc++.h>
#define N 32

using namespace std;
int n;
int b[N]={0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n && n!=0)
    {
        int parity=0;
        for(int i=0;i<N;++i)
        {
            b[N-i-1]=0;
            if(n&(1<<i))
            {
                parity++;
                b[N-i-1]=1;
            }
        }
        cout<<"The parity of ";
        int i;
        for(i=0;b[i]==0 && i<N;++i);
        for(;i<N;++i)
        {
            cout<<b[i];
        }
        cout<<" is "<<parity<<" (mod 2)."<<endl;
    }
    return 0;
}