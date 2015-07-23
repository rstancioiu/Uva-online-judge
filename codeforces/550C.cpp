#include <bits/stdc++.h>
#define M 1000

using namespace std;
int v[M];
int p[3];
int cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cnt=0;
	string number;
	cin>>number;
	for(int i=0;i<M;++i)
	{
		if(i%8==0)
			v[cnt++]=i;
	}
	int i;
	for(i=0;i<cnt;++i)
	{
		int j=v[i];
		int aux=0;
		if(j==0)
			p[aux++]=j;
		while(j!=0)
		{
			p[aux++]=j%10;
			j/=10;
			
		}
		j=aux-1;
		for(int k=0;k<number.size() && j>=0;++k)
		{
			if(number[k]==('0'+p[j]))
				j--;
		}
		if(j==-1)
		{
			cout<<"YES\n"<<v[i]<<"\n";
			break;
		}
	}
	if(i==cnt)
	{
		cout<<"NO\n";
	}
	return 0;
}