#include <cstdio>
#include <vector>

using namespace std;


int main()
{
	int t,n,a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		vector<int> v;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a);
			v.push_back(a);
		}
		int cnt=0;
		for(int i=n-1;i>=0;--i)
		{
			for(int j=i;j<n-1;++j)
			{
				if(v[j]>v[j+1])
				{
					int aux=v[j];
					v[j]=v[j+1];
					v[j+1]=aux;
					cnt++;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n",cnt);
	}
	return 0;
}