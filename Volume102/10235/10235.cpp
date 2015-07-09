// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/102/10235.html
#include <cstdio>
#include <cmath>

bool isPrime(int n)
{
	int root=sqrt(n);
	if(n%2==0 && n!=2)
		return false;
	for(int i=3;i<=root;i+=2)
		if(n%i==0)
			return false;
	return true;
}

int Reverse(int n)
{
	int reverse=0;
	while(n!=0)
	{
		reverse=(reverse*10)+n%10;
		n/=10;
	}
	return reverse;
}

int n;

int main()
{
	bool prime;
	while(scanf("%d",&n)==1)
	{
		prime=isPrime(n);
		if(prime)
		{
			int reverse=Reverse(n);
			if(reverse!=n && isPrime(reverse))
				printf("%d is emirp.\n",n);
			else printf("%d is prime.\n",n);
		}
		else printf("%d is not prime.\n",n);
	}
	return 0;
}