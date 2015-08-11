#include <bits/stdc++.h>

using namespace std;
map<int,int> s;
int t,n,m,a;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int ans=0;
		for(int i=0;i<n;++i)
		{
			cin>>a;
			map<int,int>::iterator it=s.find(a);
			if(it==s.end())
                s.insert(make_pair(a,1));
            else
                it->second++;
		}
		for(int i=0;i<m;++i)
		{
			cin>>a;
			map<int,int>::iterator it=s.find(a);
			if(it==s.end())
				ans++;
			else if(it->second>1) it->second--,n--;
			else
            {
                n--;
                s.erase(it);
            }
		}
		ans+=n;
		cout<<ans<<endl;
		s.clear();
	}

	return 0;
}
