// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/109/10924.html
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
	int root = sqrt(n);
	if(n%2==0 && n!=2)
		return false;
	for(int i=3;i<=root;i+=2)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

void Write(bool result)
{
	if(result)
		cout<<"It is a prime word."<<endl;
	else cout<<"It is not a prime word."<<endl;
}

int main()
{
	string s;
	while(cin>>s)
	{
		int sum=0;
		for(int i=0;i<s.length();++i)
		{
			if(s[i]>='a'&&s[i]<='z')
				sum+=s[i]-'a'+1;
			else if(s[i]>='A'&&s[i]<='Z')
				sum+=s[i]-'A'+27;
		}
		Write(isPrime(sum));
	}
	return 0;
}