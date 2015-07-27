#include <bits/stdc++.h>
#define N 26
#define INF 0x1fffffff

using namespace std;
string a,b,c;
int ta[N]={0};
int tb[N]={0};
int tc[N]={0};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>a;
	cin>>b;
	cin>>c;
	for(int i=0;i<a.length();++i)
		ta[a[i]-'a']++;
	for(int i=0;i<b.length();++i)
		tb[b[i]-'a']++;
	for(int i=0;i<c.length();++i)
		tc[c[i]-'a']++;
	int count1=INF;
	int count2=INF;
	for(int i=0;i<N;++i)
	{
		if(tb[i]!=0)
		{
			int t=ta[i]/tb[i];
			if(count1>t)
				count1=t;
		}
		if(tc[i]!=0)
		{
			int t = ta[i]/tc[i];
			if(count2>t)
				count2=t;
		}
	}
	int maximum=(count1>count2)?count1:count2;
	int t1=(count1>count2)?count1:0;
	int t2=(count1>count2)?0:count2;
	for(int i=maximum+1;i<=count1+count2;++i)
	{
		int k;
		int j;
		for(j=i-count2;j<=count1;++j)
		{
			int p1=j;
			int p2=i-j;
			for(k=0;k<N;++k)
			{
				if(ta[k]<tb[k]*p1+tc[k]*p2)
					break;
			}
			if(k==N)
			{
				maximum=i;
				t1=p1;
				t2=p2;
				break;
			}
		}
		if(j>count1)
			break;
	}
	for(int i=0;i<t1;++i)
		cout<<b;
	for(int i=0;i<t2;++i)
		cout<<c;
	for(int i=0;i<N;++i)
	{
		ta[i]-=tb[i]*t1+tc[i]*t2;
	}
	for(int i=0;i<N;++i)
	{
		cout<<string(ta[i],i+'a');
	}
	cout<<endl;
	return 0;
}