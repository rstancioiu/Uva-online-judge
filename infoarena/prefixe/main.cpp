#include <bits/stdc++.h>
#define N 131077

using namespace std;
int t,n;
char s[N];
int pre[N];

void prefix()
{
	int k=0;
	pre[1]=0;
	cout<<0;
	for(int i=2;i<=n;++i)
	{
		while(k>0 && s[k+1]!=s[i])
			k=pre[k];
		if(s[k+1]==s[i])
			k++;
		cout<<" "<<k;
		pre[i]=k;
	}
}

int main()
{
	freopen("prefixe.in","r",stdin);
	freopen("prefixe.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>(s+1);
		n=strlen(s+1);
		prefix();
		cout<<"\n";
	}
	return 0;
}	