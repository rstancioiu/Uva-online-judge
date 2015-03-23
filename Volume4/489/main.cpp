#include <iostream>
#include <string>
#include <sstream>
#define N 32

using namespace std;

int v[N]={0};

int main()
{
	int tries,nbLetters,n;
	string solution,sequence,s;
	for(;;)
	{
		getline(cin,s);
		istringstream iss(s);
		iss>>n;
		if(n==-1)
			break;
		getline(cin,solution);
		getline(cin,sequence);
		nbLetters=0;
		for(int i=0;i<solution.length();++i)
		{
			if(solution[i]>='a' && solution[i]<='z' && v[solution[i]-'a']==0)
			{
				v[solution[i]-'a']=1;
				nbLetters++;
			}
		}
		tries=7;
		for(int i=0;i<sequence.length();++i)
		{
			if(v[sequence[i]-'a']==1)
			{
				v[sequence[i]-'a']=0;
				nbLetters--;
				if(nbLetters==0)
					break;
			}
			else
			{
				tries--;
				if(tries==0)
					break;
			}
		}
		if(nbLetters==0)
		{
			cout<<"Round "<<n<<"\n";
			cout<<"You win.\n";
		}
		else if(tries==0)
		{
			cout<<"Round "<<n<<"\n";
			cout<<"You lose.\n";
		}
		else
		{
			cout<<"Round "<<n<<"\n";
			cout<<"You chickened out.\n";
		}
		for(int i=0;i<N;++i)
			v[i]=0;
	}
	return 0;
}