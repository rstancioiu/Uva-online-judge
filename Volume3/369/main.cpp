//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/3/369.html
#include <iostream>
#include <map>
#include <utility>
#define N 100

using namespace std;
int prime[N+5]; 

int main()
{
	for(int i=0;i<=N;++i)
		prime[i]=0;
	map<int,int> mp;
	for(int i=2;i<=N;++i)
	{
		if(prime[i]==0)
		{
			mp.insert(make_pair(i,0));
			for(int j=i*i;j<=N;j+=i)
			{
				prime[j]=1;
			}
		}
	}
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0 && m==0)
			break;
		map<int,int>::iterator it;
		for(int i=2;i<=n;++i)
		{
			int t=i;
			it=mp.begin();
			while(it!=mp.end() && t!=1)
			{
				if(t%(it->first)==0)
				{
					t/=it->first;
					it->second++;
				}
				else
					it++;
			}
		}
		for(int i=2;i<=m;++i)
		{
			int t=i;
			it=mp.begin();
			while(it!=mp.end() && t!=1)
			{
				if(t%(it->first)==0)
				{
					t/=it->first;
					it->second--;
				}
				else
					it++;
			}
		}
		for(int i=2;i<=n-m;++i)
		{
			int t=i;
			it=mp.begin();
			while(it!=mp.end() && t!=1)
			{
				if(t%(it->first)==0)
				{
					t/=it->first;
					it->second--;
				}
				else
					it++;
			}
		}
		long long int product=1;
		for(it=mp.begin();it!=mp.end();++it)
		{
			while(it->second!=0)
			{
				product*=it->first;
				it->second--;
			}
		}
		cout<<n<<" things taken "<<m<<" at a time is "<<product<<" exactly."<<endl;
	}
	return 0;
}