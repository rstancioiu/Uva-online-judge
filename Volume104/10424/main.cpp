#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string name1,name2;

int main()
{
	while(getline(cin,name1))
	{
		getline(cin,name2);
		int sum1=0;
		int sum2=0;
		for(int i=0;i<name1.length();++i)
		{
			if((name1[i]>='a' && name1[i]<='z') || (name1[i]>='A' && name1[i]<='Z'))
			{
				sum1+=(name1[i]-'A')%32+1;
			}
		}
		for(int i=0;i<name2.length();++i)
		{
			if((name2[i]>='a' && name2[i]<='z') || (name2[i]>='A' && name2[i]<='Z'))
			{
				sum2+=(name2[i]-'A')%32+1;
			}
		}
		while(sum1>=10)
		{
			int n=0;
			while(sum1!=0)
			{
				n+=sum1%10;
				sum1/=10;
			}
			sum1=n;
		}
		while(sum2>=10)
		{
			int n=0;
			while(sum2!=0)
			{
				n+=sum2%10;
				sum2/=10;
			}
			sum2=n;
		}
		if(sum1>sum2)
			printf("%.2f %%\n",(double)sum2/sum1*100);
		else
			printf("%.2f %%\n",(double)sum1/sum2*100);
	}
	return 0;
}