#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n && n!=0)
	{
		int s=sqrt(n);
		if(s*s==n)
		{
			if(s%2==0)
				cout<<s<<" 1"<<endl;
			else cout<<"1 "<<s<<endl;
		}
		else
		{
			int d=n-s*s;
			if((s+1)%2==1)
			{
			    if(d<=s+1)
                {
                    cout<<s+1<<" "<<d<<endl;
                }
                else cout<<2*(s+1)-d<<" "<<s+1<<endl;
			}
			else
            {
                if(d<=s+1)
                {
                    cout<<d<<" "<<s+1<<endl;
                }
                else cout<<s+1<<" "<<2*(s+1)-d<<endl;
            }
		}
	}

	return 0;
}
