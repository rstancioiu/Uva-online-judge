#include <bits/stdc++.h>

using namespace std;
int t,g,l;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>g>>l;
		if(l%g==0)
		{
			cout<<g<<" "<<l<<endl;
		}
		else
			cout<<-1<<endl;
	}
	return 0;
}