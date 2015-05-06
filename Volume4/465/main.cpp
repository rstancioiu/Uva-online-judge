#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;
const long long int k = 2147483647;

char a[10000];
char b[10000];
char c;

int main()
{
	while(cin>>a>>c>>b)
	{
		cout<<a<<" "<<c<<" "<<b<<endl;
		double da = atof(a);
		double db = atof(b);
		if(da>k)
			cout<<"first number too big"<<endl;
		if(db>k)
			cout<<"second number too big"<<endl;
		if(c=='+')
		{
			if(da+db>k)
					cout<<"result too big"<<endl;
		}
		if(c=='*')
		{
			if(da*db>k)
				cout<<"result too big"<<endl;
			
		}
	}
	return 0;
} 