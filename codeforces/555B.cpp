#include <bits/stdc++.h>
#define N 200005
 
using namespace std;
int n,m;
typedef pair<long long int,long long int> ll; 
typedef pair<int,int> ii;
long long int l[N];
long long int r[N];
long long int x;
int marked[N]={0};
int pos[N]={0};
vector<ll> v;


int main()
{
   ios_base::sync_with_stdio(0);
   //cin.tie(0);
   cin>>n>>m;
   for(int i=0;i<n;++i)
   	cin>>l[i]>>r[i];
   for(int i=1;i<=m;++i)
   {
   	cin>>x;
   	v.push_back(make_pair(x,i));
   }
   if(m<n-1)
   {
   	cout<<"No";
   	return 0;
   }
   for(int i=1;i<n;++i)
   {
   	v.push_back(make_pair(r[i]-l[i-1],m+i));
   	v.push_back(make_pair(l[i]-r[i-1],-i));
   }
   sort(v.begin(),v.end());
   int cnt=0;
   priority_queue<ii,vector<ii>,greater<ii> > Q;
   for(int i=0;i<v.size();++i)
   {
   	if(v[i].second>m)
   		pos[v[i].second-m]=i;
   }
   for(int i=0;i<v.size();++i)
   {
   	if(v[i].second<0)
   	{
   		int p=-v[i].second;
   		Q.push(make_pair(pos[p],p));
   	}
   	else if(!Q.empty() && v[i].second<=m)
   	{
   		ii t=Q.top();
   		Q.pop();
   		marked[t.second]=v[i].second;
   	}
   	else if(v[i].second>m && !marked[v[i].second-m])
   	{
   		cout<<"No\n";
   		return 0;
   	}
   }
   if(Q.empty())
   {
   	cout<<"Yes\n";
  	 for(int i=1;i<n;++i)
   		cout<<marked[i]<<" ";
   }
   else
   {
   	cout<<"No\n";
   	while(!Q.empty()) Q.pop();
   }
   return 0;
}