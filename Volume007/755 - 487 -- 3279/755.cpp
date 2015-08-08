#include <bits/stdc++.h>

using namespace std;
int v[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
map<int,int> numbers;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,n;
	cin>>t;
	getline(cin,s);
	for(int k=0;k<t;++k)
	{
		if(k)
			printf("\n");
		getline(cin,s);
		getline(cin,s);
		istringstream iss(s);
		iss>>n;
		for(int i=0;i<n;++i)
		{
			getline(cin,s);
			int number=0;
			int j=0;
			for(int i=0;i<s.length();++i)
			{
				if(s[i]>='0' && s[i]<='9')
				{
					number=number*10+s[i]-'0';
				}
				else if(s[i]>='A' && s[i]<='Z' && s[i]!='Q' && s[i]!='Z')
				{
					number=number*10+v[s[i]-'A'];
				}	
			}
			map<int,int>::iterator it=numbers.find(number);
			if(it==numbers.end())
				numbers.insert(make_pair(number,1));
			else it->second++;
		}
		bool duplicates=false;
		for(map<int,int>::iterator it=numbers.begin();it!=numbers.end();++it)
			if(it->second>=2)
			{
				duplicates=true;
				printf("%.3d-%.4d %d\n",it->first/10000,it->first%10000,it->second);
			}
		if(!duplicates)
			printf("No duplicates.\n");
		numbers.clear();
	}
	return 0;
}