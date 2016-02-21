#include <bits/stdc++.h>

using namespace std;
struct Figure{
	char type;
	double a,b,c,d;
	Figure(char tx,double ax,double bx,double cx,double dx): type(tx),a(ax),b(bx),c(cx),d(dx){}
};
double a,b,c,d;
vector<Figure> tab;

double dist(double ax,double ay, double bx,double by)
{
	return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	char type;
	while(cin>>type)
	{
		if(type=='*')
			break;
		a = b = c = d = 0;
		if(type=='r')
		{
			cin>>a>>b>>c>>d;
			if(a>c)
				swap(a,c);
			if(b>d)
				swap(b,d);
		}
		else if(type=='c')
		{
			cin>>a>>b>>c;
		}
		Figure f(type,a,b,c,d);
		tab.push_back(f);
	}
	int cnt=0;
	while(cin>>a>>b && !(a==9999.9 && b==9999.9))
	{
		cnt++;
		bool found=false;
		for(int i=0;i<tab.size();++i)
		{
			if(tab[i].type=='r')
			{
				if(tab[i].a<=a && a<=tab[i].c && tab[i].b<=b && b<=tab[i].d)
				{
					found=true;
					cout<<"Point "<<cnt<<" is contained in figure "<<i+1<<"\n";
				}
			}
			else if(tab[i].type=='c')
			{
				double k =dist(tab[i].a,tab[i].b,a,b);
				if(k<=tab[i].c)
				{
					found=true;
					cout<<"Point "<<cnt<<" is contained in figure "<<i+1<<"\n";
				}
			}
		}
		if(!found)
		{
			cout<<"Point "<<cnt<<" is not contained in any figure\n";
		}
	}
	return 0;
}