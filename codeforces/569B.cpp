#include <bits/stdc++.h>
#define N 100010

using namespace std;
int tab[N];
int vis[N]={0};
int n;


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=0;i<n;++i)
  	cin>>tab[i];
  for(int i=0;i<n;++i)
  {
  	if(tab[i]<=n)
  		vis[tab[i]]=1;
	}
  int p=1;
  for(int i=0;i<n;++i)
  {
  	if(vis[tab[i]]==1)
  	{
  		cout<<tab[i]<<" ";
  		vis[tab[i]]++;
  	}
  	else
  	{
  		for(;p<=n;++p)
  		{
  			if(!vis[p])
  			{
  				vis[p]=2;
  				break;
			}
  		}
  		cout<<p<<" ";
  	}
  }
  cout<<endl;
  return 0;
}