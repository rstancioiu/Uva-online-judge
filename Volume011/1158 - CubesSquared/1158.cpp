#include <bits/stdc++.h>
#define N 400100

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int MIN(int a,int b){return (a<b)?a:b;}
inline int ABS(int a){return (a>0)?a:-a;}

int ans[N]={0};
vector<int> v,a,b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int sum=1;
	for(int i=2;sum<N;++i)
	{
		ans[sum]=1;
		v.push_back(sum);
		sum+=i*i;
	}
	for(int i=1;i*i*i<N;++i)
	{
		int p=i*i*i;
		if(!ans[p])
		{
			ans[p]=1;
			v.push_back(p);
		}
	}
	sort(v.begin(),v.end());
	int cnt=N-1-v.size();
	a=v;
	int l=1;
	while(cnt)
	{
		l++;
		for(int i=0;i<a.size();++i)
		{
			for(int j=0;j<v.size();++j)
			{
				int k=a[i]+v[j];
				if(k<N && !ans[k])
				{
					b.push_back(k);
					ans[k]=l;
				}
			}
		}
		cnt-=b.size();
		v=b;
		b.clear();
	}
	int n;
	while(cin>>n && n!=-1)
	{
		cout<<ans[n]<<"\n";
	}
	return 0;
}