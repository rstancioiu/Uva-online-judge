#include <bits/stdc++.h>
#define N 12

using namespace std;
int tab[N];
int cnt[N];
string s1,s2,res;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<N;++i)
		{
			tab[i]=0;
			cnt[i]=0;
		}
		for(int i=0;i<3;++i)
		{
			cin>>s1>>s2>>res;
			if(res=="even")
			{
				for(int i=0;i<s1.length();++i)
				{
					tab[s1[i]-'A']='E';
					tab[s2[i]-'A']='E';
					cnt[s1[i]-'A']=0;
					cnt[s2[i]-'A']=0;
				}
			}
			else if(res=="up")
			{
				for(int i=0;i<s1.length();++i)
				{
					int t1=s1[i]-'A';
					int t2=s2[i]-'A';
					if(tab[t1]==0)
						tab[t1]='H';
					if(tab[t1]=='H')
						cnt[t1]++;
					if(tab[t2]==0)
						tab[t2]='L';
					if(tab[t2]=='L')
						cnt[t2]++;
				}
			}
			else if(res=="down")
			{
				for(int i=0;i<s1.length();++i)
				{
					int t1=s1[i]-'A';
					int t2=s2[i]-'A';
					if(tab[t1]==0)
						tab[t1]='L';
					if(tab[t1]=='L')
						cnt[t1]++;
					if(tab[t2]==0)
						tab[t2]='H';
					if(tab[t2]=='H')
						cnt[t2]++;
				}
			}
		}
		int i=0;
		int pos=-1;
		int maximum=0;
		for(i=0;i<N;++i)
		{
			if(tab[i]=='L' && maximum<cnt[i])
			{
				pos=i;
				maximum=cnt[i];
			}
			else if(tab[i]=='H' && maximum<cnt[i])
			{
				pos=i;
				maximum=cnt[i];
			}
			else if(tab[i]==0 && maximum==cnt[i])
				pos=i;
		}

		if(tab[pos]==0)
			cout<<char(pos+'A')<<" is the counterfeit coin and it is heavy."<<endl;
		else if(tab[pos]=='L')
			cout<<char(pos+'A')<<" is the counterfeit coin and it is light."<<endl;
		else if(tab[pos]=='H')
			cout<<char(pos+'A')<<" is the counterfeit coin and it is heavy."<<endl;
	}
	return 0;
}