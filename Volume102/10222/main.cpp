#include <string>
#include <iostream>
#include <map>

using namespace std;
map<char,char> Code;

int main()
{
	Code.insert(make_pair('d','a'));
	Code.insert(make_pair('e','q'));
	Code.insert(make_pair('r','w'));
	Code.insert(make_pair('t','e'));
	Code.insert(make_pair('y','r'));
	Code.insert(make_pair('u','t'));
	Code.insert(make_pair('i','y'));
	Code.insert(make_pair('o','u'));
	Code.insert(make_pair('p','i'));
	Code.insert(make_pair('[','o'));
	Code.insert(make_pair(']','p'));
	Code.insert(make_pair('f','s'));
	Code.insert(make_pair('g','d'));
	Code.insert(make_pair('h','f'));
	Code.insert(make_pair('j','g'));
	Code.insert(make_pair('k','h'));
	Code.insert(make_pair('l','j'));
	Code.insert(make_pair(';','k'));
	Code.insert(make_pair('\'','l'));
	Code.insert(make_pair('c','z'));
	Code.insert(make_pair('v','x'));
	Code.insert(make_pair('b','c'));
	Code.insert(make_pair('n','v'));
	Code.insert(make_pair('m','b'));
	Code.insert(make_pair(',','n'));
	Code.insert(make_pair('.','m'));
	string s;
	cin>>s;
	for(int i=0;i<s.length();++i)
	{
		if(s[i]>='A'&&s[i]<='Z')
		{
			cout<<Code[(char)('a'+s[i]%32-1)];
		}
		else 
			cout<<Code[s[i]];
	}
	while(cin>>s)
	{
		cout<<" ";
		for(int i=0;i<s.length();++i)
		{
			if(s[i]>='A'&&s[i]<='Z')
			{
				cout<<Code[(char)('a'+s[i]%32-1)];
			}
			else 
				cout<<Code[s[i]];
		}
	}
	cout<<endl;
	return 0;
}