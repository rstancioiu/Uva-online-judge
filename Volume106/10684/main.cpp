#include <iostream>
#define INF 0x3f3f3f3f

using namespace std;

inline int MAX(int a,int b) {return (a>b)?a:b;}

int main()
{
	int n,maximum,a,maxcurrent;
	while(cin>>n && n!=0)
	{
		cin>>a;
		maximum=a;
		maxcurrent=a;
		for(int i=1;i<n;++i)
		{
			cin>>a;
			maxcurrent=MAX(maxcurrent+a,a);
			if(maxcurrent>maximum)
				maximum=maxcurrent;
		}
		if(maximum >= 0)
		{
			cout<<"The maximum winning streak is "<<maximum<<".\n";
		}
		else
		{
			cout<<"Losing streak.\n";
		}
	}

	return 0;
}