// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/106/10693.html
#include <bits/stdc++.h>

using namespace std;
int L,f;

int main()
{
	int tm = 3600;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>L>>f && !(L==0 && f==0))
	{
		double velocity=sqrt(2*f*L);
		double volume = velocity*tm/(2*L);
		cout<<fixed<<setprecision(8)<<velocity<<" "<<volume<<endl;
	}

	return 0;
}
