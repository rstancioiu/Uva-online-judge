//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/1/151.html
//Description: brute force algorithm
#include <iostream>
#define N 128

using namespace std;
// array of regions turned on or off
int turn[N];

int main()
{
	bool problem;
	// n the number of regions 
	// m is the searched 'random' number
	// turned is the number of regions that are 
	// still turned on
	int n,m,turned;
	while(cin>>n && n!=0)
	{
		// we search for the first 'random' number m that
		// makes the region 13 the last region selected 
		for(int i=1;;++i)
		{
			for(int j=1;j<=n;++j)
			{
				turn[j]=0;
			}
			turn[1]=1;
			int k=0;
			int p=2;
			turned=n-1;
			// the algorithm will continue till we find the region 13
			// that's when problem becomes true
			problem=false;
			while(turned!=0 && !problem)
			{
				if(p==n+1)
					p=1;
				if(!turn[p])
				{
					k++;
					if(k==i)
					{
						turn[p]=1;
						k=0;
						turned--;
						if(p==13)
							problem=true;
					}
				}
				p++;
			}
			if(problem && turned==0)
			{
				m=i;
				break;
			}
		}
		cout<<m<<endl;
	}
	return 0;
}