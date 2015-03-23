#include <cstdio>
#include <string>


using namespace std;

int main()
{
	//freopen("test.txt","r",stdin);
	int a1,b1,c1,a2,b2,c2,a3,b3,c3;
	while(!feof(stdin) && scanf("%d%d%d%d%d%d%d%d%d\n",&a1,&b1,&c1,&a2,&b2,&c2,&a3,&b3,&c3)==9)
	{
		string s;
		int sa=a1+a2+a3;
		int sb=b1+b2+b3;
		int sc=c1+c2+c3;
		int min=a1+a2+a3+b1+b2+b3+c1+c2+c3;
		//1
		if((sa-a3+sb-b1+sc-c2)<=min)
		{
			min=sa-a3+sb-b1+sc-c2;
			s="GCB";
		}
		//2
		if((sa-a2+sb-b1+sc-c3)<=min)
		{
			min=sa-a2+sb-b1+sc-c3;
			s="GBC";
		}
		//3
		if((sa-a3+sb-b2+sc-c1)<=min)
		{
			min=sa-a3+sb-b2+sc-c1;
			s="CGB";
		}
		//4
		if((sa-a2+sb-b3+sc-c1)<=min)
		{
			min=sa-a2+sb-b3+sc-c1;
			s="CBG";
		}
		//5
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