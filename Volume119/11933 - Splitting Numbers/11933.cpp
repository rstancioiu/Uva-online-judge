#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n && n!=0)
	{
		int a=0,b=0;
		int turn=0;
		for(int i=0;i<31 && (1<<i)<=n;++i)
		{
			if((1<<i)&n)
			{
				if(turn)
					b|=(1<<i);
				else a|=(1<<i);
				turn=!turn;
			}
		}
		cout<<a<<" "<<b<<endl; 
	}
	return 0;
}