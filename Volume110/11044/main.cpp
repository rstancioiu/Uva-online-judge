#include <cstdio>

using namespace std;

int main()
{
	int n,x,y,res;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		res=((int)(x/3))*((int)(y/3));
		printf("%d\n",res);
	}
	return 0;
}