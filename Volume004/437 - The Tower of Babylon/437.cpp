// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/4/437.html
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define N 200

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
vector<iii> blocks;
int table[N][N];
int maximum[N];
int n,x,y,z;

inline int MAX (int a,int b)
{
	return (a>b)? a: b;
}

bool Compare(ii pair1,ii pair2)
{
	if(pair1.first>pair2.first && pair1.second > pair2.second)
		return true;
	else return false;
}


int main()
{
	int casenb=1;
	while(cin>>n && n!=0)
	{
		for(int i=0;i<n;++i)
		{
			cin>>x>>y>>z;
			blocks.push_back(iii(ii(x,y),z));
			blocks.push_back(iii(ii(y,x),z));
			blocks.push_back(iii(ii(z,y),x));
			blocks.push_back(iii(ii(y,z),x));
			blocks.push_back(iii(ii(x,z),y));
			blocks.push_back(iii(ii(z,x),y));
		}
		sort(blocks.rbegin(),blocks.rend());
		int k=6*n;
		for(int i=0;i<k;++i)
			maximum[i]=blocks[i].second;
		for(int i=0;i<k;++i)
		{
			for(int j=0;j<i;++j)
			{
				if(Compare(blocks[j].first,blocks[i].first))
				{
					if(maximum[i]<maximum[j]+blocks[i].second)
					{
						maximum[i]=maximum[j]+blocks[i].second;
					}
				}
			}
		}
		int maxim=0;
		for(int i=0;i<k;++i)
		{
			if(maxim<maximum[i])
				maxim=maximum[i];
		}
		cout<<"Case "<<casenb++<<": maximum height = "<<maxim<<endl;
		blocks.clear();
	}
	return 0;
}


