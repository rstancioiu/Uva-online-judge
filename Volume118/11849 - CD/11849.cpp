#include <bits/stdc++.h>

using namespace std;
set<int> s;
int cd,n,m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>m && !(n==0 && m==0))
	{
		int ans=0;
		for(int i=0;i<n;++i)
		{
			cin>>cd;
            s.insert(cd);
		}
        for(int i=0;i<m;++i)
		{
			cin>>cd;
			set<int>::iterator it=s.find(cd);
			if(it!=s.end())
			  ans++;
		}
		cout<<ans<<endl;
		s.clear();
	}
	return 0;
}
