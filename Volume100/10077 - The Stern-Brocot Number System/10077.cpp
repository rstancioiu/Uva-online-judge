#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	while(cin>>a>>b && !(a==1 && b==1))
	{
		while(a!=0 && b!=0)
		{
			if(a>b)
			{
				cout<<string(a/b-1,'R');
				if(b!=1)
					cout<<'R';
				a%=b;
			}
			else
			{
				cout<<string(b/a-1,'L');
				if(a!=1)
					cout<<'L';
				b%=a;
			}
		}
		cout<<endl;
	}
	return 0;
}