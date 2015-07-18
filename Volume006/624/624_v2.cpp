// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/6/624.html
#include <bits/stdc++.h>
#define N 1000000
#define T 32
using namespace std;
int n,t;
int tracks[T];
int tab[N];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>t)
	{
	    for(int i=0;i<=n;++i)
        {
            tab[i]=-1;
        }
		for(int i=0;i<t;++i)
		{
			cin>>tracks[i];
		}
		tab[0]=0;
		for(int i=0;i<t;++i)
        {
            for(int j=n;j>=tracks[i];--j)
            {
                if(tab[j]==-1 && tab[j-tracks[i]]>=0)
                {
                    tab[j]=j-tracks[i];
                }
            }
        }
        int sum;
        for(sum=n;sum>=0;--sum)
            if(tab[sum]>=0)
                break;
        int p=sum;
        stack<int> lifo;
        while(p!=0)
        {
            lifo.push(p-tab[p]);
            p=tab[p];
        }
        while(!lifo.empty())
        {
            int a=lifo.top();
            lifo.pop();
            cout<<a<<" ";
        }
		cout<<"sum:"<<sum<<endl;
	}
	return 0;
}
