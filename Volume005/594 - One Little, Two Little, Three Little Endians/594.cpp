#include <bits/stdc++.h>
#define N 32

using namespace std;
int n,m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n)
	{
		m=0;
		int p=0;
		for(int i=0;i<32;++i)
		{
			if(i%8==0)
				p++;
			if(n&(1<<i))
				m|=(1<<((4-p)*8+i%8));
		}
		cout<<n<<" converts to "<<m<<endl;
	}

	return 0;
}