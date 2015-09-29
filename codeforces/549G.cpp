#include <bits/stdc++.h>
#define N 200010

using namespace std;
int n;
int tab[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)
    {
    	cin>>tab[i];
    	tab[i]+=i;
    }
    sort(tab,tab+n);
    for(int i=0;i<n;++i)
    {
    	tab[i]-=i;
    }
    for(int i=1;i<n;++i)
    {	
    	if(tab[i]<tab[i-1])
    	{
    		cout<<":("<<endl;
    		return 0;
    	}
    }
    cout<<tab[0];
    for(int i=1;i<n;++i)
    {
    	cout<<" "<<tab[i];
    }
    cout<<endl;
    return 0;
}