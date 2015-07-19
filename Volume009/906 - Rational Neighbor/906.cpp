// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/9/906.html
#include <iostream>

using namespace std;

int main()
{
	long long int t,k,i;
	long long int a,b,c,d;
	double n,d1,d2,d3;
	while(cin>>a>>b)
	{
		cin>>n;
		d1=(double)a/b;
		d2=d1+n; 	
		for(long long int j=1;;j++)
		{
		    i=(long long int)(d2*j);
		    d3=(double)i/j;
		    if(d1<d3 && d3<=d2)
		    {
		    	d=j;
		    	c=i;
		    	break;
		    }
		}
		cout<<c<<" "<<d<<endl;
	}
	return 0;
}