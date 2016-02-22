#include <bits/stdc++.h>
#define N 200

using namespace std;
map<int,int> tab;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i=2;i<=N;++i)
		tab.insert(make_pair(i*i*i,i));
	for(int i=2;i<=N;++i)
	{
		int p1 = i*i*i;
		for(int j=2;j<i;++j)
		{
			int p2 = j*j*j;
			for(int k=j;k<i;++k)
			{
				int p3=k*k*k;
				if(p2+p3>p1)
					break;
				int p4 = p1-p2-p3;
				map<int,int>::iterator it = tab.find(p4);
				if(it!=tab.end())
				{
					int l=it->second;
					if(l>=k)
						cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<l<<")"<<endl;
				}
			}
		}
	}


	return 0;

}