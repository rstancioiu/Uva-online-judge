#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int n,t;

vector<int> add(vector<int> number1,vector<int> number2)
{
	vector<int> res;
	reverse(number1.begin(),number1.end());
	reverse(number2.begin(),number2.end());
	vector<int>::iterator it1,it2;
	int t=0;
	for(it1=number1.begin(),it2=number2.begin();(it1!=number1.end() && it2!=number2.end()) || t>0;++it1,++it2)
	{
		t+=(*it1)+(*it2);
		res.push_back(t%10);
		t/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}


int main()
{
	vector<int> number1,number2;
	int a,b;
	cin>>t;
	int nb=0;
	while(t--)
	{	
		if(nb++) cout<<endl;
		number1.clear();
		number2.clear();
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>a>>b;
			number1.push_back(a);
			number2.push_back(b);
		}
		vector<int> res = add(number1,number2);
		vector<int>::iterator it;
		for(it=res.begin();it!=res.end();++it)
		{
			cout<<*it;
		}
		cout<<endl;
	}
	return 0;
}