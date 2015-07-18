// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/100/10082.html
#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;
map<char,char> m;

int main()
{
	m.insert(make_pair('W','Q'));
	m.insert(make_pair('E','W'));
	m.insert(make_pair('R','E'));
	m.insert(make_pair('T','R'));
	m.insert(make_pair('Y','T'));
	m.insert(make_pair('U','Y'));
	m.insert(make_pair('I','U'));
	m.insert(make_pair('O','I'));
	m.insert(make_pair('P','O'));
	m.insert(make_pair('[','P'));
	m.insert(make_pair(']','['));
	m.insert(make_pair('\'',';'));
	m.insert(make_pair('\\',']'));
	m.insert(make_pair('S','A'));
	m.insert(make_pair('D','S'));
	m.insert(make_pair('F','D'));
	m.insert(make_pair('G','F'));
	m.insert(make_pair('H','G'));
	m.insert(make_pair('J','H'));
	m.insert(make_pair('K','J'));
	m.insert(make_pair('L','K'));
	m.insert(make_pair(';','L'));
	m.insert(make_pair('X','Z'));
	m.insert(make_pair('C','X'));
	m.insert(make_pair('V','C'));
	m.insert(make_pair('B','V'));
	m.insert(make_pair('N','B'));
	m.insert(make_pair('M','N'));
	m.insert(make_pair(',','M'));
	m.insert(make_pair('.',','));
	m.insert(make_pair('/','.'));
	m.insert(make_pair('1','`'));
	m.insert(make_pair('2','1'));
	m.insert(make_pair('3','2'));
	m.insert(make_pair('4','3'));
	m.insert(make_pair('5','4'));
	m.insert(make_pair('6','5'));
	m.insert(make_pair('7','6'));
	m.insert(make_pair('8','7'));
	m.insert(make_pair('9','8'));
	m.insert(make_pair('0','9'));
	m.insert(make_pair('-','0'));
	m.insert(make_pair('=','-'));
	string s;
	map<char,char>::iterator it;
	while(getline(cin,s))
	{
		for(int i=0;i<s.length();++i)
		{
			it=m.find(s[i]);
			if(it==m.end())
			{
				cout<<s[i];
			}
			else cout<<it->second;
		}
		cout<<endl;
	}
	return 0;
}