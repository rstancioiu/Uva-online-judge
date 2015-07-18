// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/109/10954.html
#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>,greater<int> > tab;
int a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin>>n && n!=0)
    {
        for(int i=0;i<n;++i)
        {   
            cin>>a;
            tab.push(a);
        }
        long long int sum=0;
        while(tab.size()>1)
        {
            int a=tab.top();
            tab.pop();
            int b=tab.top();
            tab.pop();
            tab.push(a+b);
            sum+=a+b;
        }
        cout<<sum<<endl;
        while(!tab.empty())tab.pop();
    }
    return 0;
}