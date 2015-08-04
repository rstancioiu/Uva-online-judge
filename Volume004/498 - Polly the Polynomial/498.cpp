#include <bits/stdc++.h>

using namespace std;
string line1,line2;
vector<int> c;

int Compute(int x)
{
	int ret=c[0];
	for(int i=1;i<c.size();++i)
	{
		ret=ret*x+c[i];
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(getline(cin,line1) && getline(cin,line2))
	{
		istringstream iss1(line1);
		int i=0;
		while(iss1>>i)
			c.push_back(i);
		istringstream iss2(line2);
		int x;
		iss2>>x;
		cout<<Compute(x);
		while(iss2>>x)
			cout<<" "<<Compute(x);
		cout<<endl;
		c.clear();
	}
	return 0;
}
