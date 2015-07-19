// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/6/674.html
#include <cstdio>
#define N 7490

using namespace std;

int main(){
   int n;
   int coins[]={50,25,10,5,1};
   long int ways[N]={0};
   ways[0]=1;
   for(int i=0;i<5;i++)
   {
   		for(int j=coins[i];j<=N;j++)
   		{
   			ways[j]+=ways[j-coins[i]];
   		}
   }
   
   while(scanf("%d",&n)==1 ){
      	printf("%d\n",ways[n]);
   }
   return 0;
}