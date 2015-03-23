#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main()
{
	string s;
	int t;
	cin>>t;
	getline(cin,s);
	while(t--)
	{
		getline(cin,s);
		stack<int> lifo1;
		stack<int> lifo2;
		int i;
		int cnt1=0;
		int cnt2=0;
		for(i=0;i<s.length();++i)
		{
			if(s[i]=='[')
			{
				lifo1.push(i);
				continue;
			}
			if(s[i]=='(')
			{
				lifo2.push(i);
				continue;
			}
			if(s[i]==']')
			{
				if(!lifo1.empty())
				{
					int k=lifo1.top();
					lifo1.pop();
					int cnt=0,j;
					for(j=k+1;j<i;++j)
					{
						if(s[j]=='(')
							cnt++;
						else if(s[j]==')')
						{
							cnt--;
							if(cnt<0)
								break;
						}
					}
					if(j!=i)
						break;
				}
				else
					break;
			}
			if(s[i]==')')
			{
				if(!lifo2.empty())
				{
					int k=lifo2.top();
					lifo2.pop();
					int cnt=0,j;
					for(j=k+1;j<i;++j)
					{
						if(s[j]=='[')
							cnt++;
						else if(s[j]==']')
						{
							cnt--;
							if(cnt<0)
								break;
						}
					}
					if(j!=i)
						break;					
				}
				else
					break;
			}
		}
		if(i==s.length() && lifo1.empty() && lifo2.empty())
		{
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
		while(!lifo1.empty()) lifo1.pop();
		while(!lifo2.empty()) lifo2.pop();
	}

	return 0;
}