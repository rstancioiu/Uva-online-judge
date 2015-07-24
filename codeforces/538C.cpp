#include <bits/stdc++.h>

using namespace std;
int n,m;
int d,h;
inline int ABS(int a){return (a>0)?a:-a;}
inline int MAX(int a,int b){return (a>b)?a:b;}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>n>>m;
    bool problem=false;
    int prevd=0;
    int prevh=0;
    int maximum=0;
    cin>>d>>h;
    maximum=h+d-1;
    prevd=d;
    prevh=h;
    for(int i=1;i<m;++i)
    {
        cin>>d>>h;
        if(d-prevd<ABS(prevh-h))
            problem=true;
        int m=MAX(prevh,h);
        int a=ABS(prevh-h);
        int t=(-a+d-prevd)/2;
        maximum=MAX(maximum,m+t);
        prevd=d;
        prevh=h;
    }
    maximum=MAX(maximum,prevh+n-prevd);
    if(problem)
        cout<<"IMPOSSIBLE"<<endl;
    else cout<<maximum<<endl;
	return 0;
}