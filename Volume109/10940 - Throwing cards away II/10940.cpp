#include <bits/stdc++.h>

using namespace std;

int Compute(int n)
{
    if(n<=2)
        return n;
    if(n%2==0)
        return Compute(n/2)*2;
    else
        return (Compute(n/2+1)-1)*2;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n && n!=0)
	{
	    cout<<Compute(n)<<endl;
	}
	return 0;
}
