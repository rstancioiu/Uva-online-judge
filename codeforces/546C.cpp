#include <cstdio>
#include <queue>

using namespace std;
queue<int> s1;
queue<int> s2;


int main()
{
	int n1,n2;
	int n,a;
	scanf("%d",&n);
	scanf("%d",&n1);
	for(int i=0;i<n1;++i)
	{
		scanf("%d",&a);
		s1.push(a);
	}
	scanf("%d",&n2);
	for(int i=0;i<n2;++i)
	{
		scanf("%d",&a);
		s2.push(a);
	}
	int f=0;
	bool found=false;
	int winner=1;
	while(f<10000 && !found)
	{
		f++;
		int c1=s1.front();
		int c2=s2.front();
		s1.pop();
		s2.pop();
		if(c1>c2)
		{
			s1.push(c2);
			s1.push(c1);
		}
		else
		{
			s2.push(c1);
			s2.push(c2);
		}
		if(s1.empty())
		{
			winner=2;
			found=true;
		}
		if(s2.empty())
		{
			winner=1;
			found=true;
		}
	}
	while(!s1.empty())
		s1.pop();
	while(!s2.empty())
		s2.pop();
	if(f==10000)
		printf("-1\n");
	else
		printf("%d %d\n",f,winner);
	return 0;
}