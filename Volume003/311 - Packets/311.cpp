//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/3/311.html
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{  
    int b1,b2,b3,b4,b5,b6;
    while (cin>>b1>>b2>>b3>>b4>>b5>>b6 && b1+b2+b3+b4+b5+b6>0)
    {
        int parcels=0;
        parcels+=b6;
        parcels+=b5;
        b1-=b5 * 11;
        parcels+=b4;
        b2 -= b4 * 5;
        parcels+=(b3+3)/4;
        if(b3%4==1)
        {
            b2-=5;
            b1-=7;
        }
        else if (b3%4==2)
        {
            b2-=3;
            b1-=6;
        }
        else if (b3%4==3)
        {
            b2-=1;
            b1-=5;
        }
        if (b2>0)
        {
            parcels+=(b2 + 8)/9;
            b2-=9*((b2 + 8)/9);
        }
        if (b2<0)
            b1+=b2 * 4;
        if (b1>0)
            parcels+= (b1 + 35) / 36;

        cout<< parcels <<endl;
    }
    return 0;
}