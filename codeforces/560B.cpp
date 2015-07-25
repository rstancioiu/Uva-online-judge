#include <bits/stdc++.h>

using namespace std;
int a1,b1;
int a2,b2,a3,b3;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a1>>b1;
    cin>>a2>>b2>>a3>>b3;
    if(((a2+a3)<=a1 && b2<=b1 && b3<=b1)|| ((a2+b3)<=a1 && b2<=b1 && a3<=b1) 
            || ((a2+a3)<=b1 && b2<=a1 && b3<=a1) || ((a2+b3)<=b1 && b2<=a1 && a3<=a1))
        cout<<"YES"<<endl;
    else if(((b2+b3)<=b1 && a2<=a1 && a3<=a1)|| ((b2+a3)<=b1 && a2<=a1 && b3<=a1) 
            || ((b2+b3)<=a1 && a2<=b1 && a3<=b1) || ((b2+a3)<=a1 && a2<=b1 && b3<=b1))
            cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}