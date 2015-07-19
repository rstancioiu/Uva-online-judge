// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/6/624.html
#include <bits/stdc++.h>
#define T 32
using namespace std;
int n,t;
int tracks[T];
int sum;
int current[T]={0};
int ans[T]={0};

void BackTrack(int start,int s)
{
    if(sum==n)
        return;
	if(s<=n && s>sum)
	{
		sum=s;
		for(int i=0;i<t;++i)
			ans[i]=current[i];
	}
	else if(s>n)
        return;
	for(int j=start;j<t;++j)
	{
		current[j]=1;
		BackTrack(j+1,s+tracks[j]);
		current[j]=0;
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>t)
	{
		for(int i=0;i<t;++i)
		{
			cin>>tracks[i];
			current[i]=0;
			ans[i]=0;
		}
		sum=0;
		BackTrack(0,0);
		for(int i=0;i<t;++i)
		{
			if(ans[i])
				cout<<tracks[i]<<" ";
		}
		cout<<"sum:"<<sum<<endl;
	}
	return 0;
}
