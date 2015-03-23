#include <iostream>
#include <string>
#include <sstream>


using namespace std;


int main()
{
	string s="";
	while(getline(cin,s))
	{
		int poss=-1;
		istringstream iss(s);
		string t;
		int nb=0;
		int i=0;
		string p=s;
		while(p[i]==' ')
		{
			cout<<" ";
			i++;
		}
		while(iss>>t)
		{
			i+=t.length();
			for(int j=t.length()-1;j>=0;--j)
			{
				cout<<t[j];
			}
			while(p[i]==' ')
			{
				cout<<" ";
				i++;
			}
		}
		cout<<endl;

	}
	return 0;
}