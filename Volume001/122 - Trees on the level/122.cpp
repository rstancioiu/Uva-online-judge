#include <bits/stdc++.h>

using namespace std;
string s;

struct cmp
{
	bool operator()(string p1,string p2)
	{
		if(p1.length()!=p2.length())
			return p1.length()<p2.length();
		else 
			return (p1<p2);
	}
};


map<string,int,cmp > tab;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int p=0;
	bool complete=true;
	while(cin>>s)
	{
		if(s.length()>2)
		{
			p++;
			int n=0;
			string t="";
			bool change=false;
			for(int i=1;i<s.length()-1;++i)
			{
				if(s[i]==',')
				{
					change=!change;
				}
				else if(!change)
				{
					n=n*10+s[i]-'0';
				}
				else
				{
					t+=s[i];
				}
			}
			if(tab.find(t)==tab.end())
				tab.insert(make_pair(t,n));
			else complete=false;
		}
		else
		{
			int c=0;
			int t=0;
			int i;
			map<string,int>::iterator it=tab.begin();
			if(p && it->first!="")
				complete=false;
			else if(p)
			{
				for(it++;it!=tab.end();++it)
				{
					string t=it->first.substr(0,it->first.length()-1);
					if(tab.find(t)==tab.end())
					{
						complete=false;
						break;
					}

				}

			}
			if(complete)
			{
				it=tab.begin();
				if(it==tab.end())
					cout<<0;
				else
				{
					cout<<it->second;
					for(it++;it!=tab.end();++it)
					{
						cout<<" "<<it->second;
					}
				}
				cout<<endl;
			}
			else cout<<"not complete"<<endl;
			tab.clear();
			p=0;
			complete=true;
		}
	}

	return 0;
}