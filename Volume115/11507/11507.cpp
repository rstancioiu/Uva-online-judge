// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/115/11507.html
#include <iostream>
#include <string>

using namespace std;

int v[6][4]={
	1,2,4,5,
	3,1,0,1,
	2,3,2,0,
	4,5,1,2,
	0,4,3,4,
	5,0,5,3
};

int Index(string s)
{
	if(s=="+y")
		return 0;
	if(s=="+z")
		return 1;
	if(s=="-y")
		return 2;
	if(s=="-z")
		return 3;
	return -1;
}

int main()
{
	int n,current,indexS;
	string s;
	while(cin>>n)
	{
		if(n==0)
			break;
		current=0;
		for(int i=0;i<n-1;++i)
		{
			cin>>s;
			indexS=Index(s);
			if(indexS!=-1)
			{
				current=v[current][indexS];
			}
		}
		switch (current)
		{
			case 0: 
				cout<<"+x"<<endl;
				break;
			case 1: 
				cout<<"+y"<<endl;
				break;
			case 2:
				cout<<"+z"<<endl;
				break;
			case 3:
				cout<<"-x"<<endl;
				break;
			case 4:
				cout<<"-y"<<endl;
				break;
			case 5:
				cout<<"-z"<<endl;
				break;
		}
	}
	return 0;
}
