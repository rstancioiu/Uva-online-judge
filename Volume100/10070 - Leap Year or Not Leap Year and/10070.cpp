#include <bits/stdc++.h>

using namespace std;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c=0;
	while(getline(cin,s))
	{
		if(c++) cout<<endl;
		bool leap = false;
		bool huluculu = false;
		bool bulukulu = false;
		int l = s.length();
		int sum = 0;
		int n = 0;
		for(int i=0;i<l;++i)
			sum+=s[i]-'0';
		for(int i=l-4;i<l;++i)
			n = n*10+s[i]-'0';
		int r=0;
		for(int i=0;i<l;++i)
		{
			int p = s[i]-'0';
			if((l-i-1)%2==0)
				r+=p;
			else
				r-=p;
		}
		if((n%4==0 && n%100!=0) || n%400==0)
			leap = true;
		if(n%5==0 && sum%3==0)
			huluculu = true;
		if(leap && n%5==0 && r%11==0)
			bulukulu = true;
		if(leap)
			cout<<"This is leap year."<<endl;
		if(huluculu)
			cout<<"This is huluculu festival year."<<endl;
		if(bulukulu)
			cout<<"This is bulukulu festival year."<<endl;
		if(!leap && !huluculu && !bulukulu)
			cout<<"This is an ordinary year."<<endl;

	}


	return 0;
}