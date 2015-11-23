#include <bits/stdc++.h>
#define M 2000100
#define N 1024

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int MIN(int a,int b){return (a<b)?a:b;}
int n,m;
char s[M],p[M];
int match[N];
int kmpNext[M];
int cnt;

void preKmp()
{
	int k=0;
	kmpNext[1]=0;
	for(int i=2;i<=n;++i)
	{
		while(k>0 && p[i]!=p[k+1])
			k=kmpNext[k];
		if(p[k+1]==p[i])
			k++;
		kmpNext[i]=k;
	}
}

void KMP()
{
	cnt=0;
	preKmp();
	int k=0;
	for(int i=1;i<=m;++i)
	{
		while(k>0 && p[k+1]!=s[i])
			k=kmpNext[k];
		if(p[k+1]==s[i])
			k++;
		if(k==n)
		{
			++cnt;
			if(cnt<=1000)
				match[cnt]=i-n;
		}
	}
}

int main()
{
	freopen("strmatch.in","r",stdin);
	freopen("strmatch.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>p+1;
	cin>>s+1;
	m=strlen(s+1);
	n=strlen(p+1);
	KMP();
	long t=cnt;
	cout<<cnt<<"\n";
	if(cnt>1000)
		cnt=1000;
	for(int i=1;i<=cnt;++i)
	{
		cout<<match[i]<<" ";
	}
	cout<<"\n";
	return 0;
}