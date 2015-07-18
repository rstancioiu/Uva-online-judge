// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/102/10284.html
#include <iostream>
#include <string>
#define N 8

using namespace std;

char table[N][N];
int attacked[N][N]={0};

void AttackPawnWhite(int i,int j)
{
	if(i>0)
	{
		if(j>0)
			attacked[i-1][j-1]=1;
		if(j<N-1)
			attacked[i-1][j+1]=1;
	}
}

void AttackPawnBlack(int i,int j)
{
	if(i<N-1)
	{
		if(j>0)
			attacked[i+1][j-1]=1;
		if(j<N-1)
			attacked[i+1][j+1]=1;
	}
}

void AttackBishop(int i,int j)
{
	for(int k=1;i+k<N && j+k<N;++k)
	{
		if(table[i+k][j+k]=='0')
			attacked[i+k][j+k]=1;
		else break;
	}
	for(int k=1;i-k>=0 && j+k<N;++k)
	{
		if(table[i-k][j+k]=='0')
			attacked[i-k][j+k]=1;
		else break;
	}
	for(int k=1;i-k>=0 && j-k>=0;++k)
	{
		if(table[i-k][j-k]=='0')
			attacked[i-k][j-k]=1;
		else break;
	}
	for(int k=1;i+k<N && j-k>=0;++k)
	{
		if(table[i+k][j-k]=='0')
			attacked[i+k][j-k]=1;
		else break;
	}
}

void AttackKing(int i,int j)
{
	if(i>0)
		attacked[i-1][j]=1;
	if(j>0)
		attacked[i][j-1]=1;
	if(i>0 && j>0)
	{
		attacked[i-1][j-1]=1;
	}
	if(i>0 && j<N-1)
	{
		attacked[i-1][j+1]=1;
	}
	if(i<N-1)
		attacked[i+1][j]=1;
	if(i<N-1 && j>0)
	{
		attacked[i+1][j-1]=1;
	}
	if(j<N-1)
		attacked[i][j+1]=1;
	if(i<N-1 && j<N-1)
	{
		attacked[i+1][j+1]=1;
	}
}

void AttackRook(int i,int j)
{
	for(int k=j+1;k<N;++k)
	{
		if(table[i][k]=='0')
			attacked[i][k]=1;
		else 
			break;
	}
	for(int k=i+1;k<N;++k)
	{
		if(table[k][j]=='0')
			attacked[k][j]=1;
		else break;
	}
	for(int k=i-1;k>=0;--k)
	{
		if(table[k][j]=='0')
			attacked[k][j]=1;
		else break;
	}
	for(int k=j-1;k>=0;--k)
	{
		if(table[i][k]=='0')
			attacked[i][k]=1;
		else break;
	}
}

void AttackKnight(int i,int j)
{
	if(i>=2 && j>=1)
		attacked[i-2][j-1]=1;
	if(i>=2 && j<N-1)
		attacked[i-2][j+1]=1;
	if(i>=1 && j>=2)
		attacked[i-1][j-2]=1;
	if(i>=1 && j<N-2)
		attacked[i-1][j+2]=1;
	if(i<N-2 && j>=1)
		attacked[i+2][j-1]=1;
	if(i<N-2 && j<N-1)
		attacked[i+2][j+1]=1;
	if(i<N-1 && j>=2)
		attacked[i+1][j-2]=1;
	if(i<N-1 && j<N-2)
		attacked[i+1][j+2]=1;
}

int main()
{
	int i,j,pos;
	string fen;
	while(cin>>fen)
	{
		i=0;
		j=0;
		for(int k=0;k<fen.length();++k)
		{
			if(fen[k]>='0'&& fen[k]<='9')
			{
				pos=fen[k]-'0';
				while(pos--)
				{
					attacked[i][j]=0;
					table[i][j++]='0';
				}
			}
			else if(fen[k]=='/')
			{
				j=0;
				i++;
			}
			else
			{
				attacked[i][j]=1;
				table[i][j++]=fen[k];

			}
		}
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<N;++j)
			{
				if(table[i][j]=='k' || table[i][j]=='K')
				{
					AttackKing(i,j);
					continue;
				}
				if(table[i][j]=='r' || table[i][j]=='R')
				{
					AttackRook(i,j);
					continue;
				}
				if(table[i][j]=='b' || table[i][j]=='B')
				{
					AttackBishop(i,j);
					continue;
				}
				if(table[i][j]=='q' || table[i][j]=='Q')
				{
					AttackBishop(i,j);
					AttackRook(i,j);
					continue;
				}
				if (table[i][j]=='n' || table[i][j]=='N')
				{
					AttackKnight(i,j);
					continue;
				}
				if(table[i][j]=='p')
				{
					AttackPawnBlack(i,j);
					continue;
				}
				if(table[i][j]=='P')
				{
					AttackPawnWhite(i,j);
				}
			}
		}
		int cnt=0;
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<N;++j)
			{
				if(!attacked[i][j])
					cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}