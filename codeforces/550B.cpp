#include <bits/stdc++.h>
#define N 16

using namespace std;
vector<int> p;
int visited[N]={0};
int n,l,r,x,a;
int ans;

void BackTrack(int min,int max,int sum,int start)
{
	if(sum>=l && sum<=r && max-min>=x)
		ans++;
	else if(sum>r)
		return;
	for(int i=start+1;i<n;++i)
	{
		if(!visited[i])
		{
			visited[i]=1;
			BackTrack((min>p[i])?p[i]:min,(max<p[i])?p[i]:max,sum+p[i],i);
			visited[i]=0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>l>>r>>x;
	for(int i=0;i<n;++i)
	{
		cin>>a;
		p.push_back(a);
	}
	sort(p.begin(),p.end());
	BackTrack(0x1fffffff,0,0,-1);
	cout<<ans<<"\n";
	return 0;
}