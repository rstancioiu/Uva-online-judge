// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/2/256.html
#include <bits/stdc++.h>

using namespace std;

int ans2[3]={0,1,81};
int ans4[5]={0,1,2025,3025,9801};
int ans6[5]={0,1,88209,494209,998001};
int ans8[9]={0,1,4941729,7441984,24502500,25502500,52881984,60481729,99980001};


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	while(cin>>k)
	{
		if(k==2)
			for(int i=0;i<3;++i)
				printf("%.2d\n",ans2[i]);
		else if(k==4)
			for(int i=0;i<5;++i)
				printf("%.4d\n",ans4[i]);
		else if(k==6)
			for(int i=0;i<5;++i)
				printf("%.6d\n",ans6[i]);
		else if(k==8)
			for(int i=0;i<9;++i)
				printf("%.8d\n",ans8[i]);
	}
	return 0;
}
