#include <iostream>
#include <string>

using namespace std;
int n;
string a,b;

int main()
{
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		string res="";
		int i=0,t=0;
		while(t%10==0)
		{
			t/=10;
			if(i<a.length() && i<b.length())
				t=t+(a[i]-'0')+(b[i]-'0');
			else if(i < a.length())
				t=t+(a[i]-'0');
			else if(i < b.length())
				t=t+(b[i]-'0');
			i++;
		}
		res+=t%10+'0';
		t/=10;
		for(;i<a.length() || i<b.length() || t>0;++i,t/=10)
		{
			if(i<a.length() && i<b.length())
				t=t+(a[i]-'0')+(b[i]-'0');
			else if(i < a.length())
				t=t+(a[i]-'0');
			else if(i < b.length())
				t=t+(b[i]-'0');
			res+='0'+t%10;
		}
		cout<<res<<endl;
	}
	return 0;
}