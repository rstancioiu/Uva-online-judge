#include <iostream>

using namespace std;

int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<"[";
	    int nb=0;
		while(a%b!=0)
		{
			if(nb++)
				cout<<a/b<<",";
			else cout<<a/b<<";";
			int aux=b;
			b=(a%b==0)?a:a%b;
			a=aux;
		}
		cout<<a/b<<"]\n";
	}
	return 0;
}