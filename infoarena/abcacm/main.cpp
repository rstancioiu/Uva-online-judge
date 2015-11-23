#include <bits/stdc++.h>
#define MOD 9907 
 
using namespace std;
 
int a,b,c,n;
 
struct Matrix{
    int ax,ay,az,bx,by,bz,cx,cy,cz;
};
 
Matrix I={1,0,0,0,1,0,0,0,1};
 
Matrix multiply(Matrix i,Matrix j)
{
    Matrix ret;
    ret.ax=((i.ax*j.ax)%MOD + (i.ay*j.bx)%MOD + (i.az*j.cx)%MOD)%MOD;
    ret.ay=((i.ax*j.ay)%MOD + (i.ay*j.by)%MOD + (i.az*j.cy)%MOD)%MOD;
    ret.az=((i.ax*j.az)%MOD + (i.ay*j.bz)%MOD + (i.az*j.cz)%MOD)%MOD;
    ret.bx=((i.bx*j.ax)%MOD + (i.by*j.bx)%MOD + (i.bz*j.cx)%MOD)%MOD;
    ret.by=((i.bx*j.ay)%MOD + (i.by*j.by)%MOD + (i.bz*j.cy)%MOD)%MOD;
    ret.bz=((i.bx*j.az)%MOD + (i.by*j.bz)%MOD + (i.bz*j.cz)%MOD)%MOD;
    ret.cx=((i.cx*j.ax)%MOD + (i.cy*j.bx)%MOD + (i.cz*j.cx)%MOD)%MOD;
    ret.cy=((i.cx*j.ay)%MOD + (i.cy*j.by)%MOD + (i.cz*j.cy)%MOD)%MOD;
    ret.cz=((i.cx*j.az)%MOD + (i.cy*j.bz)%MOD + (i.cz*j.cz)%MOD)%MOD;
    return ret;
}
int main()
{
    freopen("abcacm.in","r",stdin);
    freopen("abcacm.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>n;
        Matrix m={b,1,0,a,0,0,c,0,1};
        Matrix ans=I;
        if(n<=2)
        	cout<<0<<"\n";
        else
        {
	        n-=2;
	        while(n)
	        {
	            if(n%2==1)
	            {
	                ans=multiply(m,ans);
	            }
	            m=multiply(m,m);
	            n>>=1;
	        }
	        cout<<ans.cx<<"\n";
	    }
    }
    return 0;
}