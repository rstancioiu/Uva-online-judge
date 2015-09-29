#include <bits/stdc++.h>


using namespace std;
vector<int> C;

int Find(int x){return ((C[x]==x)?x:Find(C[x]));}
int t,n,a,b;
string s;
char type;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	getline(cin,s);
	istringstream iss(s);
	iss>>t;
	getline(cin,s);
	int i=0;
	while(t--)
	{
		if(i++)
			cout<<"\n";
		getline(cin,s);
		istringstream iss(s);
		iss>>n;
		for(int i=0;i<=n;++i)
			C.push_back(i);
	    int a1=0,a2=0;
		while(getline(cin,s) && s!="")
		{
			istringstream iss(s);
			iss>>type>>a>>b;
			if(type=='c')
			{
				int c1=Find(a);
				int c2=Find(b);
				C[c2]=c1;
			}
			else if(type=='q')
			{
				int c1=Find(a);
				int c2=Find(b);
				if(c1==c2)
					a1++;
				else a2++;
			}
		}
		cout<<a1<<","<<a2<<"\n";
		C.clear();
	}
	return 0;
}