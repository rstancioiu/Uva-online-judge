#include <bits/stdc++.h>

using namespace std;

int k;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>k;
	if(k==1)
	{
		cout<<"YES\n";
		cout<<"2 1\n1 2\n";
	}
	else if(k%2==1)
	{
		cout<<"YES\n";
		cout<<2*k+4<<" "<<(k+2)*k<<"\n";
		for(int i=2;i<=k+1;++i)
		{
			cout<<"1 "<<i<<"\n";
		}
		for(int i=2;i<=k;++i)
		{
			cout<<i<<" "<<k+2<<"\n";
		}
		for(int i=2;i<k+1;++i)
		{
			if(i%2==0)
			{
				for(int j=i+2;j<=k+1;++j)
				{
					cout<<i<<" "<<j<<"\n";
				}
			}
			else
			{
				for(int j=i+1;j<=k+1;++j)
				{
					cout<<i<<" "<<j<<"\n";
				}
			}
		}
		cout<<k+2<<" "<<2*k+4<<"\n";

		for(int i=k+4;i<=2*k+3;++i)
		{
			cout<<k+3<<" "<<i<<"\n";
		}
		for(int i=k+4;i<=2*k+2;++i)
		{
			cout<<i<<" "<<2*k+4<<"\n";
		}
		for(int i=k+4;i<2*k+3;++i)
		{
			if(i%2==1)
			{
				for(int j=i+2;j<=2*k+3;++j)
				{
					cout<<i<<" "<<j<<"\n";
				}
			}
			else
			{
				for(int j=i+1;j<=2*k+3;++j)
				{
					cout<<i<<" "<<j<<"\n";
				}
			}
		}
	}
	else
	{
		cout<<"NO\n";
	}
	return 0;
}