#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s,t,p;
	cin>>s;
	cin>>t;
	int count=0;
	for(int i=0;i<s.length();++i)
	{
		if(s[i]!=t[i])
			count++;
	}
	if(count%2==1)
		cout<<"impossible"<<endl;
	else
	{
		count/=2;
		int c=0;
		for(int i=0;i<s.length();++i)
		{
			if(s[i]!=t[i] && c<count)
			{
				cout<<s[i];
				c++;
			}
			else
				cout<<t[i];
		}
		cout<<endl;
	}

	return 0;
}