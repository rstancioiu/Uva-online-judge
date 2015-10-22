#include <bits/stdc++.h>
#define N 1024

using namespace std;
int nx,ny;
double w,pass;
double x[N],y[N];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>nx>>ny>>w && !(nx==0 && ny==0 && w==0))
	{
		for(int i=0;i<nx;++i)
			cin>>x[i];
		for(int i=0;i<ny;++i)
			cin>>y[i];
		sort(x,x+nx);
		sort(y,y+ny);
		bool check=true;
		if(x[0]-w>0)
			check=false;
		pass=w;
		for(int i=1;i<nx;++i)
		{
			if(pass>=x[i])
				pass=x[i]+w/2;
			else if(w/2>=x[i]-pass)
				pass+=x[i]-pass+w/2;
			else
				check=false;
		}
		if(pass<75)
			check=false;
		if(y[0]-w>0)
			check=false;
		pass=w;
		for(int i=1;i<ny;++i)
		{
			if(pass>=y[i])
				pass=y[i]+w/2;
			else if(w/2>=y[i]-pass)
				pass+=y[i]-pass+w/2;
			else
				check=false;
		}
		if(pass<100)
			check=false;
		if(check)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}