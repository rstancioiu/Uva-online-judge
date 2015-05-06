//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/1/120.html
//Description: ad-hoc
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> pan;
int size,solved;

//finding the pancake with the biggest diameter
vector<int>::iterator max()
{
	vector<int>::iterator it;
	vector<int>::iterator pos=pan.begin();
	int maximum=(*pan.begin());
	for(it=pan.begin();it!=(pan.end()-solved);++it)
	{
		if((*it)>=maximum)
		{
			maximum=*it;
			pos=it;
		}
	}
	return pos;
}

void Solve()
{
	bool fine=false;
	while(!fine)
	{
		vector<int>::iterator pos=max();
		if(pan.end()-solved-1==pan.begin())
		{
			cout<<"0 ";
			fine =true;
		}
		if(pos!=pan.end()-solved-1)
		{
			if(pos!=pan.begin())
			{
				reverse(pan.begin(),pos+1);
				cout<<distance(pos,pan.end())<<" ";
			}
			reverse(pan.begin(),pan.end()-solved);
			cout<<solved+1<<" ";
			solved++;
		}
		else
		{
			solved++;
		}
	}
	cout<<endl;
}

int main()
{
	string Input;
	int p;
	while(getline(cin,Input))
	{
		solved=0;
		size=0;
		istringstream iss(Input);
		while(iss>>p)
		{
			cout<<p<<" ";
			pan.push_back(p);
			size++;
		}
		iss.clear();
		cout<<endl;
		Solve();
		pan.clear();
	}
	return 0;
}