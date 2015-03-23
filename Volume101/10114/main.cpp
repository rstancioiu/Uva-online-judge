#include <iostream>
#include <vector>

using namespace std;

double duration, downPayment,amountLoan,nDepreciation,rate;
vector<pair<int,double> > depreciation;

int main()
{
	vector<pair<int,double> >::iterator it;
	int month;
	double currentValue,d,currentDepreciation;
	while(cin>>duration && duration>=0)
	{
		cin>>downPayment>>amountLoan>>nDepreciation;
		currentValue=amountLoan+downPayment;
		rate=amountLoan/duration;
		for(int i=0;i<nDepreciation;++i)
		{
			cin>>month;
			cin>>d;
			depreciation.push_back(make_pair(month,d));
		}
		int nbMonth=0;
		currentDepreciation=0;
		it=depreciation.begin();
		if(it!=depreciation.end() && nbMonth==it->first)
		{
			currentDepreciation=it->second;
			it++;
			currentValue=currentValue*(1-currentDepreciation);
		}
		nbMonth++; 
		if(currentValue<=amountLoan)
		{
			while(1)
			{
				if(it!=depreciation.end() && nbMonth==it->first)
				{
					currentDepreciation=it->second;
					it++;
				}
				amountLoan-=rate;
				currentValue=currentValue*(1-currentDepreciation);
				if(currentValue>amountLoan)
				{
				nbMonth++;
					break;
				}
				else nbMonth++;
			}
		}
		nbMonth--;
		if(nbMonth==1)
			cout<<nbMonth<<" month\n";
		else cout<<nbMonth<<" months\n";
		depreciation.clear();
	}
	return 0;
}