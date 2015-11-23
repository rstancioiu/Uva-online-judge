#include <bits/stdc++.h>

using namespace std;
long long a,n;

long long extended_euclid(long long a,long long b,long long &x,long long &y)
{
	long long xx=y=0;
	long long yy=x=1;
	while(b)
	{
		long long q=a/b;
		long long t=b;b=a%b;a=t;
		t=xx;xx=x-q*xx;x=t;
		t=yy;yy=y-q*yy;y=t;
	}
	return a;
}

long long invmodular(long long a,long long n)
{
	long long x,y;
	extended_euclid(a,n,x,y);
	return (x%n+n)%n;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("inversmodular.in","r",stdin);
	freopen("inversmodular.out","w",stdout);
	cin>>a>>n;
	cout<<invmodular(a,n)<<"\n";
	return 0;
}