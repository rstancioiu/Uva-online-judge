#include <bits/stdc++.h>
#define N 10000

using namespace std;
const long long int MAX=2300000000;
long long int tab[N];
long long int p1,p2,p3,p4;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int cnt=0;
	for(p1=1;p1<MAX;p1*=2)
	{
		for(p2=p1;p2<MAX;p2*=3)
		{
			for(p3=p2;p3<MAX;p3*=5)
			{
				for(p4=p3;p4<MAX;p4*=7)
				{
                    tab[cnt++]=p4;
                }
			}
		}
	}
	sort(tab,tab+cnt);
	int n;
	while(cin>>n && n!=0)
	{
		cout<<"The "<<n;
		if(n%10==1 && n%100!=11)
			cout<<"st";
		else if(n%10==2 && n%100!=12)
			cout<<"nd";
		else if(n%10==3 && n%100!=13)
			cout<<"rd";
		else cout<<"th";
		cout<<" humble number is "<<tab[n-1]<<"."<<endl;
	}
	return 0;
}
