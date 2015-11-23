#include <bits/stdc++.h>
#define N 500100

using namespace std;
int a[N];
int n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("algsort.in","r",stdin);
	freopen("algsort.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;++i)
		cout<<a[i]<<" ";
	return 0;
}