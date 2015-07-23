#include <iostream>
#define N 10000

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int ABS(int a){return (a>0)?a:-a;}
string s;
int n;
int min1,max1;
int min2,max2;
int min3,max3;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	cin>>min1>>max1;
	cin>>min2>>max2;
	cin>>min3>>max3;
	int summin=min1+min2+min3;
	n-=summin;
	if(n>=max1-min1)
	{
		cout<<max1<<" ";
		n-=max1-min1;
	}
	else
	{
		cout<<min1+n<<" ";
		n=0;
	}
	if(n>=max2-min2)
	{
		cout<<max2<<" ";
		n-=max2-min2;
	}
	else
	{
		cout<<min2+n<<" ";
		n=0;
	}
	if(n>=max3-min3)
	{
		cout<<max3<<endl;
		n-=max3-min3;
	}
	else
	{
		cout<<min3+n<<endl;
		n=0;
	}

	return 0;
}