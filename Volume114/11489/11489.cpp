// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/114/11489.html
#include <bits/stdc++.h>
#define MOD 3

using namespace std;
string s;
int T;
queue<int> fifo[MOD];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	for(int t=1;t<=T;++t)
	{
		cin>>s;
		int sum=0;
		for(int i=0;i<s.length();++i)
		{
			int p=s[i]-'0';
			sum+=p;
			fifo[p%MOD].push(p);
		}
		int turn=0;
		for(int i=1;i<MOD;++i)
		{
			if(sum%MOD==i && !fifo[i].empty())
			{
				sum-=fifo[i].front();
				fifo[i].pop();
				turn++;
			}
		}
		while(1)
		{
			if(sum%MOD==0 && !fifo[0].empty())
			{
				sum-=fifo[0].front();
				fifo[0].pop();
				turn++;
			}
			else break;
		}
		for(int i=0;i<MOD;++i)
		{
			while(!fifo[i].empty())
				fifo[i].pop();
		}
		if(turn%2)
			cout<<"Case "<<t<<": S"<<endl;
		else cout<<"Case "<<t<<": T"<<endl;
	}
	return 0;
}
