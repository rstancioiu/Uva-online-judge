#include <bits/stdc++.h>
#define N 32
#define M 26
#define P 128

using namespace std;
int n;
string s[N];
int t[N];
int check[M];
int res[M];
int ans;
int a[N];
int first[P];
int hash[P];
vector<int> pos;

bool compute()
{
	int res=0;
	for(int i=0;i<s[n-1].length();++i)
		res=res*10+hash[s[n-1][i]];
	int sum=0;
	for(int i=0;i<n-1;++i)
	{
		int a=0;
		for(int j=0;j<s[i].length();++j)
		{
			a=a*10+hash[s[i][j]];
		}
		sum+=a;
		if(sum>res)
			return false;
	}
	if(sum==res)
		return true;
	return false;
}

void backtrack(int j,int* a,int cnt)
{
	if(j==cnt)
	{
		for(int i=0;i<cnt;++i)
			hash[pos[i]]=a[i];
		if(compute())
			ans++;
		return;
	}
	for(int i=j;i<10;++i)
	{
		if(!(a[i]==0 && first[pos[j]]))
		{
			swap(a[i],a[j]);
			backtrack(j+1,a,cnt);
			swap(a[i],a[j]);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n)
	{
		for(int i=0;i<M;++i)
			check[i]=0;
		for(int i=0;i<P;++i)
			first[i]=0;
		for(int i=0;i<10;++i)
			a[i]=i;
		for(int i=0;i<n;++i)
			cin>>s[i];
		int cnt=0;
		ans=0;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<s[i].size();++j)
			{
				if(!check[s[i][j]-'A'])
				{
					check[s[i][j]-'A']=1;
					pos.push_back(s[i][j]);
					cnt++;
				}
			}
		}
		for(int i=0;i<n;++i)
			first[s[i][0]]=1;
		sort(pos.begin(),pos.end());
		backtrack(0,a,cnt);
		cout<<ans<<endl;
		pos.clear();
	}
}