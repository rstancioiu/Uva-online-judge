#include <bits/stdc++.h>

using namespace std;
int t;
double ax,ay,bx,by;
double cx,cy,dx,dy;
double ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>ax>>ay>>bx>>by;
        //double x=(bx*ay - ax*by)/(ay+by);
        //double y=(bx*ay - ax*by)/(bx+ax);
        cx=ax-bx;
        cy=ay-by;
        dx=ax+bx;
        dy=ay+by;
        ans=sqrt(cx*cx+cy*cy)+sqrt(dx*dx+dy*dy);
        cout<<fixed<<setprecision(3)<<ans<<endl;
    }
    return 0;
}