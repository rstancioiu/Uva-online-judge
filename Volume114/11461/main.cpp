#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	while(cin>>a>>b && a!=0 && b!=0)
	{
		int rac1=sqrt(a);
		int rac2=sqrt(b);
		if(rac1*rac1!=a)
			rac1++;
		cout<<rac2-rac1+1<<endl;
	}

	return 0;
}