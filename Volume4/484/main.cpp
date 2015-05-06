#include <cstdio>
#include <vector>
#include <utility>

using namespace std;
vector<pair<int,int> > integers;

int n;

int main()
{
	vector<pair<int,int> >::iterator it;
	while(scanf("%d",&n)==1)
	{
		for(it=integers.begin();it!=integers.end();++it)
		{
			if(it->first == n)
			{
				it->second++;
				break;
			}
		}
		if(it==integers.end())
			integers.push_back(make_pair(n,1));
	}
	for(it=integers.begin();it!=integers.end();++it)
	{
		printf("%d %d\n",it->first,it->second);
	}
	return 0;
}