#include <iostream>
#define INF 0x3f3f3f3f

using namespace std;
int n,b,h,w,bh,a,bm,k;

int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>b>>h>>w)
	{
		bm=INF;
		for(int i=0;i<h;++i)
		{
			cin>>bh;
			k=n*bh;
			for(int j=0;j<w;++j)
			{
				cin>>a;
				if(a>=n && k<=b)
				{
					if(k<bm)
						bm=k;
				}
			}
		}
		if(bm!=INF) cout<<bm<<"\n";
		else cout<<"stay home\n";
	}

	return 0;
}