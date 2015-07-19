// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/104/10422.html
#include <string>
#include <iostream>
#include <cstdio>
#define N 5

using namespace std;
char table[N][N];
char check[N][N]=
{
    '1','1','1','1','1',
    '0','1','1','1','1',
    '0','0',' ','1','1',
    '0','0','0','0','1',
    '0','0','0','0','0',
};

int moves;

bool checkTable()
{
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            if(table[i][j]!=check[i][j])
                return false;
        }
    }
    return true;
}

typedef struct Case
{
    int x;
    int y;
    int moves;
} Case;

void Swap(Case a,Case b)
{
    char aux=table[a.x][a.y];
    table[a.x][a.y]=table[b.x][b.y];
    table[b.x][b.y]=aux;
}

void Backtrack(Case current)
{
    if(current.x==2 && current.y==2)
    {
        if(checkTable())
        {
            if(current.moves<moves)
                moves = current.moves;
        }
    }
    if(current.moves<10)
    {
        if(current.x>=2 && current.y>=1)
        {
            Case future= {current.x-2,current.y-1,current.moves+1};
            Swap(current,future);
            Backtrack(future);
            Swap(current,future);
        }
        if(current.x>=1 && current.y>=2)
        {
            Case future= {current.x-1,current.y-2,current.moves+1};
            Swap(current,future);
            Backtrack(future);
            Swap(current,future);
        }
        if(current.x>=2 && current.y<4)
        {
            Case future= {current.x-2,current.y+1,current.moves+1};
            Swap(current,future);
            Backtrack(future);
            Swap(current,future);
        }
        if(current.x<4 && current.y>=2)
        {
            Case future= {current.x+1,current.y-2,current.moves+1};
            Swap(current,future);
            Backtrack(future);
            Swap(current,future);
        }
        if(current.x<4 && current.y<3)
        {
            Case future= {current.x+1,current.y+2,current.moves+1};
            Swap(current,future);
            Backtrack(future);
            Swap(current,future);
        }
        if(current.x<3 && current.y<4)
        {
            Case future= {current.x+2,current.y+1,current.moves+1};
            Swap(current,future);
            Backtrack(future);
            Swap(current,future);
        }
        if(current.x<3 && current.y>=1)
        {
            Case future= {current.x+2,current.y-1,current.moves+1};
            Swap(current,future);
            Backtrack(future);
            Swap(current,future);
        }
        if(current.x>=1 && current.y<3)
        {
            Case future= {current.x-1,current.y+2,current.moves+1};
            Swap(current,future);
            Backtrack(future);
            Swap(current,future);
        }
    }
}


int main()
{
    //freopen("test.txt","r",stdin);
    int t;
    string s;
    cin>>t;
    getline(cin,s);
    for(int k=0; k<t; ++k)
    {
        moves=11;
        for(int i=0; i<N; ++i)
        {
            getline(cin,s);
            for(int j=0; j<N; ++j)
            {
                table[i][j]=' ';
                if(j<s.length())
                    table[i][j]=s[j];
            }
        }
        Case first;
        for(int i=0; i<N; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(table[i][j]==' ')
                {
                    first.x=i;
                    first.y=j;
                }
            }
        }
        first.moves=0;
        Backtrack(first);
        if(moves>=11)
            cout<<"Unsolvable in less than 11 move(s)."<<endl;
        else
            cout<<"Solvable in "<<moves<<" move(s)."<<endl;
    }
    return 0;
}
