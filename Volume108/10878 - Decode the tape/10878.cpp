#include <bits/stdc++.h>

using namespace std;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(getline(cin,s))
    {
        int n=0;
        for(int i=1;i<=s.length()-2;++i)
        {
            if(s[i]!='.')
            {
                n*=2;
                if(s[i]=='o')
                {
                    n++;
                }
            }
        }
        if(n!=0)
            cout<<char(n);
    }
    return 0;
}