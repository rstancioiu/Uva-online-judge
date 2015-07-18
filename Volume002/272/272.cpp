//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/2/272.html
#include <iostream>
#include <string>

using namespace std;


int main()
{	
	string s;
	int pos=0;
	while(getline(cin,s))
	{
		string t="";
		for(int i=0;i<s.length();++i)
		{
			if(s[i]=='"')
			{
				if(pos==0)
				{
					t+="``";
					pos=1;
				}
				else if(pos==1)
				{
					t+="''";
					pos=0;
				}
			}
			else
			{
				t+=s[i];
			}
		}
		cout<<t<<endl;
	}
	return 0;
}