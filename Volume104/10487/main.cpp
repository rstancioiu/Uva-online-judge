#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define INF 0x1f1f1f1f

using namespace std;
vector<int> numbers;


int main()
{
	int n,m,a;
	int t=0;
	while(cin>>n && n!=0)
	{
		t++;
		for(int i=0;i<n;++i)
		{
			cin>>a;
			numbers.push_back(a);
		}
		sort(numbers.begin(),numbers.end());
		cout<<"Case "<<t<<":"<<endl;
		cin>>m;
		for(int i=0;i<m;++i)
		{
			cin>>a;
			int minimum=INF,sum=0;
			int j=0;
			for(int j=0;j<numbers.size();++j)
			{
				if(numbers[j]!=numbers[j+1])
				{
					for(int k=j+1;k<numbers.size();++k)
					{
						if(abs(a-numbers[k]-numbers[j]) < minimum)
						{
							minimum = abs(a-numbers[k]-numbers[j]);
							sum=numbers[k]+numbers[j];
						}
					}
				}
			}		
			cout<<"Closest sum to "<<a<<" is "<<sum<<"."<<endl;
		}
		numbers.clear();
	}
	return 0;
}