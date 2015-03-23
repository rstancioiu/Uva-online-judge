#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#define N 3200

using namespace std;

inline int abs(int a)
{
	return (a>0) ? a: -a;
}


int main()
{
	int n;
	string s;
	while(getline(cin,s))
	{
		vector<int> v;
		istringstream iss(s);
		int a,last;
		if(!(iss>>n))
			break;
		for(int i=0;i<n;++i)
		{
			iss>>a;
			if(i!=0)
			{
				int t=abs(last-a);
				v.push_back(t);
			}
			last=a;
		}
		sort(v.begin(),v.end());
		int k=1;
		vector<int>::iterator it;
		for(it=v.begin();it!=v.end();++it)
		{
			if(k==(*it))
			{
				k++;
			}
			else break;
		}
		if(it==v.end())
			cout<<"Jolly\n";
		else cout<<"Not jolly\n";
	}
	return 0;
}