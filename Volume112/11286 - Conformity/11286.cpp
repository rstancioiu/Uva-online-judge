#include <bits/stdc++.h>
#define M 5

using namespace std;
map<vector<int>,int> frosh;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,a;
	while(cin>>n && n!=0)
	{
		int ans=0;
		for(int i=0;i<n;++i)
		{
			vector<int> tab;
			for(int j=0;j<M;++j)
			{
				cin>>a;
				tab.push_back(a);
			}
			sort(tab.begin(),tab.end());
			map<vector<int>,int>::iterator it= frosh.find(tab);
			if(it==frosh.end())
			{
				frosh.insert(make_pair(tab,1));
			}
			else
                it->second++;
		}
		int maximum=0;
		for(map<vector<int>,int>::iterator it=frosh.begin();it!=frosh.end();++it)
        {
            if(maximum<it->second)
            {
                maximum=it->second;
                ans=maximum;
            }
            else if(maximum==it->second)
            {
                ans+=maximum;
            }
        }
		cout<<ans<<endl;
		frosh.clear();
	}
	return 0;
}
