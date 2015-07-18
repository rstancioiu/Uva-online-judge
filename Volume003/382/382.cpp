//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/3/382.html
#include <iostream>

using namespace std;

int main()
{
	int n;
	cout<<"PERFECTION OUTPUT"<<endl;
	while(cin>>n)
	{	
		if(n==0)
			break;
		if(n==1)
		{
			cout<<"    1  DEFICIENT"<<endl;
			continue;
		}
		int sum=0;
		int i;
		for(i=1;i*i<n;++i)
		{
			if(n%i==0)
			{
				sum+=i;
				sum+=n/i;
			}
		}
		int t=0;
		if(i*i==n)
			sum+=i;
		int k=n;
		while(k!=0){t++;k/=10;}
		if(sum==2*n)
		{
			for(int i=0;i<5-t;++i)
				cout<<" ";
			cout<<n<<"  PERFECT"<<endl;
		}
		else if(sum>2*n)
		{
			for(int i=0;i<5-t;++i)
				cout<<" ";
			cout<<n<<"  ABUNDANT"<<endl;
		}
		else
		{
			for(int i=0;i<5-t;++i)
				cout<<" ";
			cout<<n<<"  DEFICIENT"<<endl;
		}

	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}