// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/101/10141.html
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int n,m,r,nb;
	double price,minPrice,compliance;
	nb=0;
	string s,res,p;
	while(1)
	{
		getline(cin,s);
		istringstream iss(s);
		iss>>n>>m;
		if(n==0 && m==0)
			break;
		compliance=0;
		minPrice=0;
		if(nb++)
			cout<<endl;
		for(int i=0;i<n;++i)
		{
			getline(cin,s);
		}
		for(int j=0;j<m;++j)
		{
			getline(cin,s);
			getline(cin,p);
			istringstream iss(p);
			iss>>price;
			iss>>r;
			if(compliance < (double)r/n)
			{
				compliance=(double)r/n;
				minPrice=price;
				res=s;
			}
			else if(compliance==(double)r/n && price<minPrice)
			{
				compliance=(double)r/n;
				minPrice=price;
				res=s;
			}
			for(int i=0;i<r;++i)
			{
				getline(cin,s);
			}
		}
		cout<<"RFP #"<<nb<<endl;
		cout<<res<<endl;
	}
	return 0;
}