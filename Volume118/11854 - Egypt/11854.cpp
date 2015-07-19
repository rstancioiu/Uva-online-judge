// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/118/11854.html
#include <iostream>

using namespace std;


int main()
{
	int a,b,c;
	while(cin>>a>>b>>c && (a!=0 && b!=0 && c!=0))
	{
		if(a==0 || b==0 || c==0)
		{
			cout<<"wrong"<<endl;
		}
		else if(a*a == b*b + c*c)
		{
			cout<<"right"<<endl;
		}
		else if(b*b == a*a + c*c)
		{
			cout<<"right"<<endl;
		}
		else if(c*c == a*a + b*b)
		{
			cout<<"right"<<endl;
		}
		else
		{
			cout<<"wrong"<<endl;
		}

	}
	return 0;
}