#include <string>
#include <cstdio>
#define N 10

using namespace std;
const string suffix="ay";
char c;
string word;
char vowel[N]={'a','e','i','o','u','A','E','I','O','U'};

int main()
{
	int check=0;
	while(scanf("%c",&c)==1)
	{
		if((c>='a' && c<='z')||(c>='A' && c<='Z'))
		{
			check=1;
			word+=c;
		}
		else
		{
			if(check)
			{
				int i;
				for(i=0;i<N;++i)
					if(word[0]==vowel[i])
						break;
				if(i!=N)
					printf("%s%s",word.c_str(),suffix.c_str());
				else 
				{
					for(int i=1;i<word.length();++i)
					{
						printf("%c",word[i]);
					}
					printf("%c",word[0]);
					printf("%s",suffix.c_str());
				}
				check=0;
				word.clear();
			}
			printf("%c",c);
		}
	}
	if(check)
	{
		int i;
		for(i=0;i<N;++i)
			if(word[0]==vowel[i])
				break;
		printf("%d\n",i);
		if(i==N)
			printf("%s%s",word.c_str(),suffix.c_str());
		else
		{
			for(int i=word.length()-1;i>=0;--i)
			{
				printf("%c",word[i]);
			}
			printf("%s",suffix.c_str());
		}
		check=0;
		word.clear();
	}
	return 0;
}