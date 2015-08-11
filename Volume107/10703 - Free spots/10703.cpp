#include <bits/stdc++.h>
#define N 512

using namespace std;
int w,h,n;
int xa,ya,xb,yb;
int m[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>w>>h>>n && !(w==0 && h==0 && n==0))
    {
        for(int i=1;i<=w;++i)
            for(int j=1;j<=h;++j)
                m[i][j]=0;
        for(int k=0;k<n;++k)
        {
            cin>>xa>>ya>>xb>>yb;
            if(xa>xb) swap(xa,xb);
            if(ya>yb) swap(ya,yb);
            for(int i=xa;i<=xb;++i)
                for(int j=ya;j<=yb;++j)
                    m[i][j]=1;
        }
        int ans=0;
        for(int i=1;i<=w;++i)
            for(int j=1;j<=h;++j)
                if(!m[i][j])
                    ans++;
        if(ans==0)
            cout<<"There is no empty spots."<<endl;
        else if(ans==1)
            cout<<"There is one empty spot."<<endl;
        else
            cout<<"There are "<<ans<<" empty spots."<<endl;
    }
    return 0;
}
