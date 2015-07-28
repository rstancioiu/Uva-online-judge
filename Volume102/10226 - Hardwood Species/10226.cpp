#include <bits/stdc++.h>

using namespace std;
string s;
map<string,int> pop;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("test.txt","r",stdin);
    int t;
    cin>>t;
	getline(cin,s);
    getline(cin,s);
	for(int i=0;i<t;++i)
	{
		if(i)
			cout<<endl;
		int cnt=0;
		while(getline(cin,s) && s!="")
		{
			map<string,int>::iterator it=pop.find(s);
			if(it==pop.end())
				pop.insert(make_pair(s,1));
			else it->second++;
			cnt++;
		}
		for(map<string,int>::iterator it=pop.begin();it!=pop.end();++it)
		{
			cout<<it->first<<" "<<fixed<<setprecision(4)<<(double)(it->second)*100/cnt<<endl;
		}
		pop.clear();
	}
	return 0;
}
