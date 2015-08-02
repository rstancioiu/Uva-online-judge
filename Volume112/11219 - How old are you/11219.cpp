#include <bits/stdc++.h>

using namespace std;
string date1,date2;
int year1,year2;
int m1,m2;
int d1,d2;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>date2>>date1;
		d1=(date1[0]-'0')*10+(date1[1]-'0');
		m1=(date1[3]-'0')*10+(date1[4]-'0');
		year1=(date1[6]-'0')*1000+(date1[7]-'0')*100+(date1[8]-'0')*10+date1[9]-'0';
		d2=(date2[0]-'0')*10+(date2[1]-'0');
		m2=(date2[3]-'0')*10+(date2[4]-'0');
		year2=(date2[6]-'0')*1000+(date2[7]-'0')*100+(date2[8]-'0')*10+(date2[9]-'0');
		int age=year2-year1;
		if(age>=0)
		{
			if(m1>m2)
				age--;
			else if(m1==m2 && d1>d2)
				age--;
		}
		cout<<"Case #"<<i<<": ";
		if(age<0)
			cout<<"Invalid birth date";
		else if(age>130)
			cout<<"Check birth date";
		else cout<<age;
		cout<<endl;
	}
	return 0;
}