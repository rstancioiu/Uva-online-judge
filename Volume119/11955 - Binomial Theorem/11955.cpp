#include <bits/stdc++.h>
#define N 64

using namespace std;
string a,b;
int k,t;
string s;
long long int comb[N][N]={0};

void GenerateComb()
{
	for(int i=1;i<N;++i)
	{
		comb[i][0]=1;
		comb[i][1]=i;
	}
	for(int i=1;i<N;++i)
	{
		for(int j=2;j<=i;++j)
		{
			comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	GenerateComb();
	cin>>t;
	for(int c=1;c<=t;++c)
	{
		a="";
		b="";
		k=0;
		cin>>s;
		int i;
		for(i=1;i<s.length() && s[i]!='+';++i)
			a+=s[i];
		for(i++;i<s.length()&&s[i]!=')';++i)
			b+=s[i];
		for(i+=2;i<s.length();++i)
			k=k*10+(s[i]-'0');
		if(k==1)
			cout<<"Case "<<c<<": "<<a<<"+"<<b<<endl;
		else
		{
			cout<<"Case "<<c<<": "<<a<<"^"<<k;
			for(int i=k-1;i>0;--i)
			{
                if(i!=1 && k-i!=1)
                    cout<<"+"<<comb[k][i]<<"*"<<a<<"^"<<i<<"*"<<b<<"^"<<k-i;
                else if(k-i!=1)
                    cout<<"+"<<comb[k][i]<<"*"<<a<<"*"<<b<<"^"<<k-i;
                else if(i!=1)
                    cout<<"+"<<comb[k][i]<<"*"<<a<<"^"<<i<<"*"<<b;
                else
                    cout<<"+"<<comb[k][i]<<"*"<<a<<"*"<<b;
			}
			cout<<"+"<<b<<"^"<<k<<endl;
		}
	}
	return 0;
}
