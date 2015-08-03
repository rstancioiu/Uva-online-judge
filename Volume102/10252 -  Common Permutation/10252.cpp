#include <bits/stdc++.h>
#define N 26

using namespace std;
inline int MIN(int a,int b){return (a>b)?b:a;}
string a;
string b;
int taba[N];
int tabb[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(getline(cin,a))
	{
		getline(cin,b);
		for(int i=0;i<N;++i)
		{
			taba[i]=tabb[i]=0;
		}
		for(int i=0;i<a.length();++i)
			taba[a[i]-'a']++;
		for(int i=0;i<b.length();++i)
			tabb[b[i]-'a']++;
		for(int i=0;i<N;++i)
		{
			char c='a'+i;
			int t=MIN(taba[i],tabb[i]);
			for(int j=0;j<t;++j)
				cout<<c;
		}
		cout<<endl;
	}
	return 0;
}
