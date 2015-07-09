// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/4/481.html
#include <vector>
#include <cstdio>

using namespace std;
 
vector<int> seq; 
vector<int> lis;

void find_lis()
{
	vector<int> p(seq.size());
	int low, high;
 
	if (seq.empty()) return;
 
	lis.push_back(0);
 
	for (int i=1;i<seq.size(); i++) 
    {
		if (seq[lis.back()] < seq[i]) 
   	    { 
	 		p[i] = lis.back();
		    lis.push_back(i);
				continue;
			} 
		for (low=0,high=lis.size()-1;low<high;) 
        {
			int mid =low+(high-low)/2;
			if (seq[lis[mid]]<seq[i]) low=mid+1; else high=mid;
		}
		if (seq[i] <= seq[lis[low]]) 
        {
			if (low > 0) p[i] = lis[low-1];
			lis[low] = i;
		}	
	}
 
	for (low = lis.size(), high = lis.back(); low--; high = p[high]) lis[low] = high;
}
 
int main()
{                  
	int number;         
 	while(scanf("%d",&number)==1)
 	{
 		seq.push_back(number);
 	}
 	find_lis();
 	printf("%d\n-\n",lis.size());
	for (int i = 0; i < lis.size(); i++)
	{
		printf("%d\n", seq[lis[i]]);
	}    
 
	return 0;
}