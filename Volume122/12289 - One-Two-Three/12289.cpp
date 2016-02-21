#include <bits/stdc++.h>
#define N 3
#define X first
#define Y second

using namespace std;
typedef pair<int,string> is;
vector<is> tab;
int n;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	tab.push_back(is(1,"one"));
	tab.push_back(is(2,"two"));
	tab.push_back(is(3,"three"));
	cin>>n;
	for(int c=0;c<n;++c)
	{
		cin>>s;
		int pos;
		for(int i=0;i<N;++i)
		{
			if(s.length() == tab[i].Y.length())
			{	
				int dif=0;
				for(int j=0;j<s.length();++j)
					if(s[j]!=tab[i].Y[j])
						dif++;
				if(dif<=1)
					pos=i;
			}
		}
		cout<<tab[pos].X<<"\n";
	}
	return 0;
}