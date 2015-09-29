#include <bits/stdc++.h>

using namespace std;
int t,s,q;


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t>>s>>q;
  int i;
  for(i=0;s<t;++i)
  {
  	s*=q;
  }
  cout<<i<<"\n";
  return 0;
}