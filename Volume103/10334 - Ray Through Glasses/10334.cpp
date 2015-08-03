#include <bits/stdc++.h>
#define N 1001

using namespace std;
string tab[N];
int n;

string ADD(string a,string b)
{
	int t=0;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string ret="";
	for(int i=0;i<a.length() || i<b.length() || t!=0;i++,t/=10)
	{
		if(i<a.length() && i<b.length())
		{
			t+=a[i]-'0'+b[i]-'0';
			ret+=t%10+'0';
		}
		else if(i<a.length())
		{
			t+=a[i]-'0';
			ret+=t%10+'0';
		}
		else if(i<b.length())
		{
			t+=b[i]-'0';
			ret+=t%10+'0';
		}
		else
		{
			ret+=t%10+'0';
		}
	}
	reverse(ret.begin(),ret.end());
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	tab[0]="1";
	tab[1]="2";
	for(int i=2;i<N;++i)
		tab[i]=ADD(tab[i-1],tab[i-2]);
	while(cin>>n)
		cout<<tab[n]<<endl;
	return 0;
}
