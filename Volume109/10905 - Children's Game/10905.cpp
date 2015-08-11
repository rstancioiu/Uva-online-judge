#include <bits/stdc++.h>

using namespace std;
int n;
vector<string> v;

struct compare{
	bool operator()(string a,string b){
	    return ((a+b)>(b+a));
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while(cin>>n && n!=0)
	{
		for(int i=0;i<n;++i)
		{
			cin>>s;
			v.push_back(s);
		}
		sort(v.begin(),v.end(),compare());
		for(int i=0;i<v.size();++i)
			cout<<v[i];
		cout<<endl;
		v.clear();
	}
	return 0;
}
