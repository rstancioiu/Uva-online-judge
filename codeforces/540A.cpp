#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
inline int MIN(int a,int b){return (a>b)?b:a;}
inline int ABS(int a){return (a>0)?a:-a;}
int n;
string s1,s2;

int main()
{
	cin>>n;
	cin>>s1;
	cin>>s2;
	int ans=0;
	for(int i=0;i<n;++i)
	{
		int a=s1[i]-'0';
		int b=s2[i]-'0';
		int minimum=MIN(ABS(a-b),ABS(a-b+10));
		minimum = MIN(minimum,ABS(a-b-10));
		ans+=minimum;
	}
	printf("%d\n",ans);
	return 0;
}