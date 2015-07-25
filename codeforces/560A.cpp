#include <bits/stdc++.h>

using namespace std;
int n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	bool ans=false;
	for(int i=0;i<n;++i)
	{
		int a;
		cin>>a;
		if(a==1)
			ans=true;
	}
	if(ans)
		cout<<-1<<endl;
	else cout<<1<<endl;
	return 0;
}