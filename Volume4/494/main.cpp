#include <iostream>
#include <string>

using namespace std;


int main()
{
	string s;
	while(getline(cin,s))
	{
		int cnt=0;
		int word=1;
		for(int i=0;i<s.length();++i)
		{
			if((s[i]>='a'&& s[i]<='z')||(s[i]>='A'&& s[i]<='Z'))
			{
				if(word)
					cnt++;
				word=0;
			}
			else 
				word=1;
		}	
		cout<<cnt<<endl;
	}
	return 0;
}