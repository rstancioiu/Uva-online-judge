#include <iostream>
#include <string>

using namespace std;


int main()
{
	string s1,s2;
	while(cin>>s1>>s2)
	{
		if(s2.length()<s1.length())
		{
			cout<<"No"<<endl;
		}
		else
		{
			int i=0;
			int j=0;
			for(;i<s2.length() && j<s1.length();++i)
			{
				if(s2[i]==s1[j])
					j++;
			}
			if(j==s1.length())
				cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}