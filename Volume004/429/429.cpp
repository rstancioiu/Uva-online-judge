// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/4/429.html
#include <string>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#define N 220

using namespace std;
vector<string> dict;
vector<int> pairs[N];
int visited[N];
int distances[N];
int n;

bool isPair(string a, string b)
{
    if(a.length() != b.length())
        return false;
    int change=0;
    for(int i=0; i<a.length(); ++i)
    {
        if(a[i]!=b[i])
            change++;
    }
    if(change==1)
        return true;
    else return false;
}

int Bfs(int s,int e)
{
    if(s==e || dict[s]==dict[e])
        return 0;
    int p;
    vector<int> :: iterator it;
    queue<int> fifo;
    for(int i=0; i<n; ++i)
    {
        visited[i]=0;
        distances[i]=0;
    }
    fifo.push(s);
    visited[s]=1;
    bool found = false;
    while(!fifo.empty() && !found)
    {
        p = fifo.front();
        fifo.pop();
        for(it=pairs[p].begin(); it!=pairs[p].end(); ++it)
        {
            if(!visited[*it])
            {
                if(*it == e)
                {
                    found = true;
                    distances[e]=distances[p]+1;
                    break;
                }
                else
                {
                    visited[*it]=1;
                    fifo.push(*it);
                    distances[*it]=distances[p]+1;
                }
            }
        }
    }
    while(!fifo.empty()) fifo.pop();
    return distances[e];
}

int main()
{
    string s,a,b;
    int t;
    cin>>t;
    getline(cin,s);
    getline(cin,s);
    for(int i=0;i<t;++i)
    {
        if(i>0)
            cout<<endl;
        bool problem =false;
        n=0;
        while(!problem)
        {
            getline(cin,s);
            istringstream iss(s);
            iss>>s;
            if(s=="*")
                problem=true;
            else
            {
                for(int k=0; k<n; ++k)
                {
                    if(isPair(dict[k],s))
                    {
                        pairs[k].push_back(n);
                        pairs[n].push_back(k);
                    }
                }
                dict.push_back(s);
                n++;
            }
        }
        problem=false;
        while(!problem && !cin.eof())
        {
            getline(cin,s);
            istringstream iss(s);
            if(iss>>a>>b)
            {
                int i,j;
                for(int k=0; k<n; ++k)
                {
                    if(dict[k]==a)
                        i=k;
                    if(dict[k]==b)
                        j=k;
                }
                int res = Bfs(i,j);
                cout<<a<<" "<<b<<" "<<res<<endl;
            }
            else
            {
                problem=true;
            }
        }
        dict.clear();
        for(int i=0; i<n; ++i)
        {
            pairs[i].clear();
        }
    }
    return 0;
}
