#include <iostream>
#include <string>

using namespace std;
const string too="too";
const string high="high";
const string low="low";

int main()
{
	string s1,s2;
	int n;
	while(cin>>n && n!=0)
	{
		int l=0,h=11;
		for(;;)
		{
			cin>>s1>>s2;
			if(s1==too)
			{
				if(s2==high)
				{
					if(n<h)
						h=n;
				}
				else if(s2==low)
				{
					if(n>l)
						l=n;
				}
			}
			else if(s1=="right")
			{
				if(n>l && n<h)
				{
					cout<<"Stan may be honest"<<endl;
				}
				else 
				{
					cout<<"Stan is dishonest"<<endl;
				}
				break;
			}
			cin>>n;
		}
	}
	return 0;
}