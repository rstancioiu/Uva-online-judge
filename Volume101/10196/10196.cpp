// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/101/10196.html
#include <iostream>
#include <string>
#define N 8


using namespace std;
char v[10][10];

bool checkPawnWhite(int i,int j)
{
	if(v[i+1][j+1]=='K' && i+1<N && j+1<N)
		return true;
	if(v[i+1][j-1]=='K'&& i+1<N && j-1>=0)
		return true;
	return false;
}
bool checkPawnBlack(int i,int j)
{
	if(v[i-1][j-1]=='k' && i-1>=0 && j-1>=0)
		return true;
	if(v[i-1][j+1]=='k'&& j+1<N && i-1>=0)
		return true;
	return false;
}

bool checkRookWhite(int i,int j)
{
	for(int t=i+1;t<N;++t)
	{
		if(v[t][j]!='.')
		{
			if(v[t][j]=='K')
				return true;
			else break;
		}
	}
	for(int t=i-1;t>=0;--t)
	{
		if(v[t][j]!='.')
		{
			if(v[t][j]=='K')
				return true;
			else break;
		}
	}
	for(int t=j+1;t<N;++t)
	{
		if(v[i][t]!='.')
		{
			if(v[i][t]=='K')
				return true;
			else break;
		}
	}
	for(int t=j-1;t>=0;--t)
	{
		if(v[i][t]!='.')
		{
			if(v[i][t]=='K')
				return true;
			else break;
		}
	}
	return false;
}

bool checkRookBlack(int i,int j)
{
	for(int t=i+1;t<N;++t)
	{
		if(v[t][j]!='.')
		{
			if(v[t][j]=='k')
				return true;
			else break;
		}
	}
	for(int t=i-1;t>=0;--t)
	{
		if(v[t][j]!='.')
		{
			if(v[t][j]=='k')
				return true;
			else break;
		}
	}
	for(int t=j+1;t<N;++t)
	{
		if(v[i][t]!='.')
		{
			if(v[i][t]=='k')
				return true;
			else break;
		}
	}
	for(int t=j-1;t>=0;--t)
	{
		if(v[i][t]!='.')
		{
			if(v[i][t]=='k')
				return true;
			else break;
		}
	}
	return false;
}

bool checkBishopWhite(int i,int j)
{
	int t1,t2;
	for(t1=i-1,t2=j-1;t1>=0 && t2>=0;--t1,--t2)
	{
		if(v[t1][t2]!='.')
		{
			if(v[t1][t2]=='K')
				return true;
			else break;
		}
	}
	for(t1=i-1,t2=j+1;	t1>=0 && t2<N ;--t1,++t2)
	{
		if(v[t1][t2]!='.')
		{
			if(v[t1][t2]=='K')
				return true;
			else break;
		}
	}
	for(t1=i+1,t2=j+1;t1<N && t2<N;++t1,++t2)
	{
		if(v[t1][t2]!='.')
		{
			if(v[t1][t2]=='K')
				return true;
			else break;
		}
	}
	for(t1=i+1,t2=j-1;t1<N && t2>=0;++t1,--t2)
	{
		if(v[t1][t2]!='.')
		{
			if(v[t1][t2]=='K')
				return true;
			else break;
		}
	}
	return false;
}


bool checkBishopBlack(int i,int j)
{
	int t1,t2;
	for(t1=i-1,t2=j-1;t1>=0 && t2>=0;--t1,--t2)
	{
		if(v[t1][t2]!='.')
		{
			if(v[t1][t2]=='k')
				return true;
			else break;
		}
	}
	for(t1=i-1,t2=j+1;t1>=0 && t2<N;--t1,++t2)
	{
		if(v[t1][t2]!='.')
		{
			if(v[t1][t2]=='k')
				return true;
			else break;
		}
	}
	for(t1=i+1,t2=j+1;t1<N && t2<N;++t1,++t2)
	{
		if(v[t1][t2]!='.')
		{
			if(v[t1][t2]=='k')
				return true;
			else break;
		}
	}
	for(t1=i+1,t2=j-1;t1<N && t2>=0;++t1,--t2)
	{
		if(v[t1][t2]!='.')
		{
			if(v[t1][t2]=='k')
				return true;
			else break;
		}
	}
	return false;
}

bool checkKnightWhite(int i,int j)
{
	if(v[i-2][j-1]=='K' && i-2>=0 && j-1>=0)
		return true;
	if(v[i-2][j+1]=='K' && i-2>=0 && j+1<N)
		return true;

	if(v[i-1][j-2]=='K' && i-1>=0 && j-2>=0)
		return true;
	if(v[i-1][j+2]=='K' && i-1>=0 && j+2<N)
		return true;

	if(v[i+2][j-1]=='K' && i+2<N && j-1>=0)
		return true;
	if(v[i+2][j+1]=='K' && i+2<N && j+1<N)
		return true;

	if(v[i+1][j-2]=='K' && i+1<N && j-2>=0)
		return true;
	if(v[i+1][j+2]=='K' && i+1<N && j+2<N)
		return true;

	return false;
}
bool checkKnightBlack(int i,int j)
{
	if(v[i-2][j-1]=='k' && i-2>=0 && j-1>=0)
		return true;
	if(v[i-2][j+1]=='k' && i-2>=0 && j+1<N)
		return true;
	if(v[i-1][j-2]=='k' && i-1>=0 && j-2>=0)
		return true;
	if(v[i-1][j+2]=='k' && i-1>=0 && j+2<N)
		return true;
	if(v[i+2][j-1]=='k' && i+2<N && j-1>=0)
		return true;
	if(v[i+2][j+1]=='k' && i+2<N && j+1<N)
		return true;
	if(v[i+1][j-2]=='k' && i+1<N && j-2>=0)
		return true;
	if(v[i+1][j+2]=='k' && i+1<N && j+2<N)
		return true;
	return false;
}


int main()
{
	string s;
	int nbPoints;
	int nb=0;
	while(1)
	{
		nbPoints=0;
		for(int i=0;i<N;++i)
		{
			getline(cin,s);
			for(int j=0;j<N;++j)
			{	
				v[i][j]=s[j];
				if(v[i][j]=='.')
					nbPoints++;
			}
		}
		if(nbPoints==N*N)
			break;
		getline(cin,s);
		bool whitecheck=false;
		//black in check
		for(int i=0;i<N && !whitecheck;++i)
		{
			for(int j=0;j<N && !whitecheck;++j)
			{
				if(v[i][j]=='p' && checkPawnWhite(i,j))
				{
					whitecheck=true;
				}
				if(v[i][j]=='n' && checkKnightWhite(i,j))
				{
					whitecheck=true;
				}
				if(v[i][j]=='b' && checkBishopWhite(i,j))
				{
					whitecheck=true;
				}
				if(v[i][j]=='r' && checkRookWhite(i,j))
				{
					whitecheck=true;
				}
				if(v[i][j]=='q' && (checkRookWhite(i,j) || checkBishopWhite(i,j)))
				{
					whitecheck=true;
				}
			}
		}
		bool blackcheck=false;
		for(int i=0;i<N && !blackcheck;++i)
		{
			for(int j=0;j<N && !blackcheck;++j)
			{
				if(v[i][j]=='P' && checkPawnBlack(i,j))
				{
					blackcheck=true;
				}
				if(v[i][j]=='N' && checkKnightBlack(i,j))
				{
					blackcheck=true;
				}
				if(v[i][j]=='B' && checkBishopBlack(i,j))
				{
					blackcheck=true;
				}
				if(v[i][j]=='R' && checkRookBlack(i,j))
				{
					blackcheck=true;
				}
				if(v[i][j]=='Q' && (checkRookBlack(i,j) || checkBishopBlack(i,j)))
				{
					blackcheck=true;
				}
			}
		}
		nb++;
		if(!blackcheck && whitecheck)
		{
			cout<<"Game #"<<nb<<": white king is in check."<<endl;
		}
		else if(!whitecheck && blackcheck)
		{
			cout<<"Game #"<<nb<<": black king is in check."<<endl;
		}
		else
		{
			cout<<"Game #"<<nb<<": no king is in check."<<endl;

		}
	}
	return 0;
}