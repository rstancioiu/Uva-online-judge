#include <bits/stdc++.h>

using namespace std;

long long int SZ,P;
int line,column;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>SZ>>P && !(SZ==0 && P==0))
	{
		if(P==1)
		{
			column = line = SZ/2+1;
		}
		else
		{
			int s = sqrt(P);
			if(s%2==0)
				s++;
            else if(s*s!=P && s%2==1)
                s+=2;
			line=column=SZ/2+1;
			line+=s/2;
			column+=s/2-1;
			P-=(s-2)*(s-2)+1;
			column-=(P<=(s-2))?P:(s-2);
			P=(P<=(s-2))?0:(P-s+2);
			line-=(P<=(s-1))?P:(s-1);
			P=(P<=(s-1))?0:(P-s+1);
			column+=(P<=(s-1))?P:(s-1);
			P=(P<=(s-1))?0:(P-s+1);
			line+=(P<=(s-1))?P:(s-1);
			P=(P<=(s-1))?0:(P-s+1);
		}
		cout<<"Line = "<<line<<", column = "<<column<<".\n";
	}

	return 0;
}
