// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/108/10855.html
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> big;
vector<string> small;
int N,n;


void rotate(int t)
{
	vector<string> aux=small;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			aux[j][n-i-1]=small[i][j];
		}
	}
	small=aux;
	aux.clear();
}

int count_found()
{
	int k,t;
	int count=0;
	string s;
	for(int i=0;i<=N-n;++i)
	{
		for(int j=0;j<=N-n;++j)
		{
			for(k=0;k<n;++k)
			{
				for(t=0;t<n;++t)
				{
					if(small[k][t]!=big[i+k][j+t])
						break;
				}
				if(t!=n)
					break;
			}
			if(k==n)
				count++;
		}
	}
	return count;
}

int main()
{
	string s;
	while(cin>>N>>n && !(N==0 && n==0))
	{
		for(int i=0;i<N;++i)
		{
			cin>>s;
			big.push_back(s);
		}
		for(int i=0;i<n;++i)
		{
			cin>>s;
			small.push_back(s);
		}
		cout<<count_found()<<" ";
		rotate(0);
		cout<<count_found()<<" ";
		rotate(1);
		cout<<count_found()<<" ";
		rotate(2);
		cout<<count_found()<<endl;
		big.clear();
		small.clear();
	}
	return 0;
}