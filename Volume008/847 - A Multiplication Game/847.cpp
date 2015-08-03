#include <bits/stdc++.h>

using namespace std;

bool Compute(unsigned int ans,unsigned int n,int cnt)
{
	if(ans>=n)
	{
		return (cnt-1)%2;
	}
	for(int i=9;i>=2;--i)
	{
		bool res=Compute(ans*i,n,cnt+1);
		if(res==cnt%2)
			return res;
	}
	return !(cnt%2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	unsigned int n;
	while(cin>>n)
	{
		unsigned int ans=1;
		bool res=Compute(ans,n,0);
		if(!res)
			cout<<"Stan wins."<<endl;
		else cout<<"Ollie wins."<<endl;
	}
	return 0;
}
