// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/116/11687.html
#include <bits/stdc++.h>

using namespace std;
string x0;

int NbDigits(int a)
{
	int cnt=0;
	while(a!=0)
	{
		a/=10;
		cnt++;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>x0 && x0!="END")
	{
		int p=x0.length();
		int cnt=1;
		if(p==1 && x0=="1")
		{
			cout<<cnt<<endl;
		}
		else
		{
			int k=NbDigits(p);
			while(k!=p)
			{
				p=k;
				k=NbDigits(p);
				cnt++;
			}
			cout<<cnt+1<<endl;
		}
	}
	return 0;
}
