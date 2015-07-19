#include <bits/stdc++.h>

using namespace std;
double ax,ay,bx,by,cx,cy;
double a,b,c,p,S;
int t;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
    {   
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        c=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
        a=sqrt((cx-bx)*(cx-bx)+(cy-by)*(cy-by));
        b=sqrt((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy));
        p=(a+b+c)/2;
        S=sqrt(p*(p-a)*(p-b)*(p-c));
        cout<<(int)(S/7+0.5)<<endl;
    }
    return 0;
}