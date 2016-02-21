#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll z,i,m,l;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c=1;
	while(cin>>z>>i>>m>>l && !(z==0 && i==0 && m==0 && l==0))
	{
		l = (z*l+i)%m;
		ll a=l;
		int cnt=0;
		for(;;)
		{
			l = (z*l+i)%m;
			cnt++;	
			if(l==a)
				break;
		}
		cout<<"Case "<<c++<<": "<<cnt<<"\n";
	}

	return 0;
}