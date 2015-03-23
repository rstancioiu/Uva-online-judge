#include <iostream>

using namespace std;

int v[10];

int main()
{
	int n,s;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>s;
		for(int j=0;j<=9;++j)
			v[j]=0;
		for(int j=1;j<=s;++j)
		{
			int t=j;
			while(t!=0)
			{
				v[t%10]++;
				t/=10;
			}
		}
		for(int i=0;i<9;++i)
			cout<<v[i]<<" ";
		cout<<v[9]<<endl;
	}

}