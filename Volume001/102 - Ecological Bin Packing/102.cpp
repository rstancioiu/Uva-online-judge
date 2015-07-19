// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/1/102.html
// Description: brute force problem
#include <cstdio>
#include <string>

using namespace std;

//a1,a2,a3 represent the number of brown bottles in bins 1,2 and 3
//b1,b2,b3 represent the number of green bottles in bins 1,2 and 3
//c1,c2,c3 represent the number of clear bottles in bins 1,2 and 3
int main()
{
	int a1,b1,c1,a2,b2,c2,a3,b3,c3;
	while(!feof(stdin) && scanf("%d%d%d%d%d%d%d%d%d\n",&a1,&b1,&c1,&a2,&b2,&c2,&a3,&b3,&c3)==9)
	{
		string s;
		int sa=a1+a2+a3; // total number of brown bottles in bins
		int sb=b1+b2+b3; // total number of green bottles in bins
		int sc=c1+c2+c3; // total number of clear bottles in bins
		// we set the minimum equal to the total number of bottles
		int min=a1+a2+a3+b1+b2+b3+c1+c2+c3; 
		// we find the combination of numbers a,b,c in order to have
		// the minimum number of bottle movements so that we have  
		// different types of bottles in each bin 
		if((sa-a3+sb-b1+sc-c2)<=min)
		{
			min=sa-a3+sb-b1+sc-c2;
			s="GCB";
		}
		if((sa-a2+sb-b1+sc-c3)<=min)
		{
			min=sa-a2+sb-b1+sc-c3;
			s="GBC";
		}
		if((sa-a3+sb-b2+sc-c1)<=min)
		{
			min=sa-a3+sb-b2+sc-c1;
			s="CGB";
		}
		if((sa-a2+sb-b3+sc-c1)<=min)
		{
			min=sa-a2+sb-b3+sc-c1;
			s="CBG";
		}
		if((sa-a1+sb-b2+sc-c3)<=min)
		{
			min=sa-a1+sb-b2+sc-c3;
			s="BGC";
		}
		if((sa-a1+sb-b3+sc-c2)<=min)
		{
			min=sa-a1+sb-b3+sc-c2;
			s="BCG";
		}
		printf("%s %d\n",s.c_str(),min);
	}
}