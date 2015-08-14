#include <bits/stdc++.h>


using namespace std;
string s;
int n,m,a;
char c;
set<int> t;

int Compute(int k)
{
	if(k<=1)
		return 0;
	int p=0;
	while(k!=1)
	{
		p+=k/2;
		k=k/2+k%2;
	}
	return p;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	int cnt=0;
	int ans=0;
	t.insert(-1);
	t.insert(n);
	for(int i=0;i<n;++i)
	{
		if(s[i]=='.')
			cnt++;
		else
		{
			t.insert(i);
			if(cnt!=0)
				ans+=Compute(cnt);
			cnt=0;
		}
	}
	if(cnt!=0)
		ans+=Compute(cnt);
	for(int i=0;i<m;++i)
	{
		cin>>a>>c;
		if((s[a-1]!='.' && c!='.') || (s[a-1]=='.' && c=='.'))
		{
			cout<<ans<<endl;
			s[a-1]=c;
			continue;
		}
		if(s[a-1]=='.')
		{
			set<int>::iterator it=t.insert(a-1).first;
			set<int>::iterator it1,it2;
			it1=--it;
			++it;
			it2=++it;
			--it;
			ans-=Compute((*it2)-(*it1)-1)-Compute((*it2)-(*it)-1)-Compute((*it)-(*it1)-1);
		}
		else
		{
			set<int>::iterator it=t.find(a-1);
			set<int>::iterator it1,it2;
			it1=--it;
			++it;
			it2=++it;
			--it;
			ans+=Compute((*it2)-(*it1)-1)-Compute((*it2)-(*it)-1)-Compute((*it)-(*it1)-1);
			t.erase(it);
		}
		s[a-1]=c;
		cout<<ans<<endl;
	}
	return 0;
}