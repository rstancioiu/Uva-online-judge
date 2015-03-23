#include <iostream>
#include <string>


using namespace std;
int v[256]={0};

int main()
{
	v['B']=1;
	v['F']=1;
	v['P']=1;
	v['V']=1;
	v['C']=2;
	v['G']=2;
	v['J']=2;
	v['K']=2;
	v['Q']=2;
	v['S']=2;
	v['X']=2;
	v['Z']=2;
	v['D']=3;
	v['T']=3;
	v['L']=4;
	v['M']=5;
	v['N']=5;
	v['R']=6;		
	string s;
	while(getline(cin,s))
	{
		for(int i=0;i<s.length()-1;++i)
		{
			if(v[s[i]]!=0 && v[s[i]]!=v[s[i+1]])
				cout<<v[s[i]];
		}
		if(v[s[s.length()-1]]!=0)
			cout<<v[s[s.length()-1]];
		cout<<endl;

	}
	return 0;
}