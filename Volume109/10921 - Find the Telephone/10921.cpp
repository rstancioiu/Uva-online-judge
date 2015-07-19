// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/109/10921.html
#include <iostream>
#include <string>

using namespace std;

int v[256]={0};

int main()
{
	v['A']=2;
	v['B']=2;
	v['C']=2;

	v['D']=3;
	v['E']=3;
	v['F']=3;

	v['G']=4;
	v['H']=4;
	v['I']=4;

	v['J']=5;
	v['K']=5;
	v['L']=5;

	v['M']=6;
	v['N']=6;
	v['O']=6;

	v['P']=7;
	v['Q']=7;
	v['R']=7;
	v['S']=7;

	v['T']=8;
	v['U']=8;
	v['V']=8;

	v['W']=9;
	v['X']=9;
	v['Y']=9;
	v['Z']=9;
	string s;
	while(getline(cin,s))
	{
		for(int i=0;i<s.length();++i)
		{
			if(s[i]>='A'&&s[i]<='Z')
				cout<<v[s[i]];
			else cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}