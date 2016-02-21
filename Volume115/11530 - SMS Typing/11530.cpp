#include <bits/stdc++.h>

using namespace std;
int t;
string s;
map<char,int> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	m['a']=1;m['b']=2;m['c']=3;
	m['d']=1;m['e']=2;m['f']=3;
	m['g']=1;m['h']=2;m['i']=3;
	m['j']=1;m['k']=2;m['l']=3;
	m['m']=1;m['n']=2;m['o']=3;
	m['p']=1;m['q']=2;m['r']=3;m['s']=4;
	m['t']=1;m['u']=2;m['v']=3;
	m['w']=1;m['x']=2;m['y']=3;m['z']=4;
	m[' ']=1;
	cin>>t;
	getline(cin,s);
	for(int c=1;c<=t;++c)
	{
		getline(cin,s);
		int cnt=0;
		for(int i=0;i<s.length();++i)
		{
			cnt+=m[s[i]];
		}
		cout<<"Case #"<<c<<": "<<cnt<<"\n";
	}
	return 0;
}