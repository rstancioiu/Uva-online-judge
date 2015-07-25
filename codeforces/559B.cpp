#include <bits/stdc++.h>

using namespace std;

string a,b;

bool Compare(int starta,int startb,int n)
{
    for(int i=0;i<n;++i)
        if(a[starta++]!=b[startb++])
            return false;
    return true;
}

bool Echiv(int starta,int startb,int n)
{
    if(Compare(starta,startb,n))
        return true;
    else
    {
        if(n%2==0)
        {
            n/=2;
            if((Echiv(starta,startb,n) && Echiv(starta+n,startb+n,n)) || (Echiv(starta,startb+n,n) && Echiv(starta+n,startb,n)))
                return true;
        }
    }
    return false;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a;
    cin>>b;
    string c=a;
    string d=b;
    sort(c.begin(),c.end());
    sort(d.begin(),d.end());
    if(c==d)
    {
    	if(Echiv(0,0,a.length()))
        	cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}