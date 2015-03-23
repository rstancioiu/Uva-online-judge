#include <iostream>
#define N 128

using namespace std;
int turn[N];

int main()
{
	bool problem;
	int n,m,turned;
	while(cin>>n && n!=0)
	{
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