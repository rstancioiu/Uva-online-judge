#include <iostream>
#include <string>

using namespace std;

void Compute(int start,int end,string& s)
{
	if(end-start&1)
		return;
	int n = end-start;
	n/=2;
	Compute(start,start+n,s);
	Compute(start+n,end,s);
	bool change=false;
	for(int i=0;i<n;++i)
	{
		if(s[i+start]>s[i+n+start])
			{change=true;break;}
		else if(s[i+start]<s[i+n+start])
			break;
	}
	if(change)
		for(int i=0;i<n;++i)
			swap(s[i+start],s[i+n+start]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a,b;
	cin>>a;
	cin>>b;
	Compute(0,a.length(),a);
	Compute(0,b.length(),b);
	if(a==b)
		cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}