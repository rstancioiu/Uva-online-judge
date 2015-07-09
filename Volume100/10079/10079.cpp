// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/100/10079.html
#include <iostream>

using namespace std;


int main()
{
	long long int n;
	while(cin>>n && n>=0)
	{
		cout<<n*(n+1)/2+1<<endl;
	}
	return 0;
}