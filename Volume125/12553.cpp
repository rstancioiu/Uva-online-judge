#include <bits/stdc++.h>
#define N 6
#define M 128
#define P 10010

using namespace std; 
inline int ABS(int a){return (a>0)?a:-a;}
typedef pair<int,string> is;
typedef pair<int,is> iis;
int num[N];
int target;
int t;
set<int> vis;
vector<is> tab[M];
map<int,int> mat[M];

string to_string(int t)
{
	stringstream ss;
	ss<<t;
	return(ss.str());
}
 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        queue<iis> Q;
        int t=1;
        for(int i=0;i<N;++i)
        {
            cin>>num[i];
            vis.insert(num[i]);
            tab[t].push_back(is(num[i],""));
            Q.push(make_pair(t,is(num[i],"")));
            mat[t][num[i]]++;
            t*=2;
        }
        cin>>target;
        cout<<"Target: "<<target<<"\n";
        if(vis.find(target)!=vis.end())
            cout<<"Best approx: "<<target<<"\n\n";
        else
        {
            int best=-0x3f3f3f3f;
            string bests="";
            int cnt=0;
            while(!Q.empty())
            {
                cnt++;
                iis p=Q.front();
                Q.pop();
                string s=p.second.second;
                int number=p.second.first;
                int hash=p.first;
                if(number==target)
                {
                    bests=s;
                    best=number;
                    break;
                }
                else if(ABS(number-target)<ABS(best-target))
                {
                    bests=s;
                    best=number;
                }
                for(int i=1;i<M;++i)
                {
                    if((i&hash)==0)
                    {
                        for(int j=0;j<tab[i].size();++j)
                        {
                            int add=tab[i][j].first+number;
                            int dif=ABS(tab[i][j].first-number);
                            int mul=tab[i][j].first*number;
                            int hash2=i|hash;
                            string s1=to_string(tab[i][j].first);
                            string s2=to_string(number);
                            string s3=to_string(add);
                            string adds=s+tab[i][j].second+s1+" + "+s2+" = "+s3+"\n";
                            s3=to_string(dif);
                            string difs="";
                            if(tab[i][j].first>number && !mat[hash2][dif])
                            {
                                difs=s+tab[i][j].second+s1+" - "+s2+" = "+s3+"\n";
                                Q.push(make_pair(hash2,make_pair(dif,difs)));
                                tab[hash2].push_back(is(dif,difs));
                                mat[hash2][dif]=1;
                            }
                            else if(tab[i][j].first<number && !mat[hash2][dif])
                            {
                                difs=s+tab[i][j].second+s2+" - "+s1+" = "+s3+"\n";
                                Q.push(make_pair(hash2,make_pair(dif,difs)));
                                tab[hash2].push_back(is(dif,difs));
                                mat[hash2][dif]=1;
                            }
                            s3=to_string(mul);
                            string muls=s+tab[i][j].second+s1+" * "+s2+" = "+s3+"\n";
                            if(!mat[hash2][add])
                            {
                            	Q.push(make_pair(hash2,make_pair(add,adds)));
                            	tab[hash2].push_back(is(add,adds));
                            	mat[hash2][add]=1;
                            }
                            if(!mat[hash2][mul])
                            {
                            	Q.push(make_pair(hash2,make_pair(mul,muls)));
                            	tab[hash2].push_back(is(mul,muls));
                            	mat[hash2][mul]=1;
                            }
                            if(tab[i][j].first%number==0)
                            {
                                int divi=tab[i][j].first/number;
                                if(!mat[hash2][divi])
                                {
                                	s3=to_string(divi);
                               	 	string divis=s+tab[i][j].second+s1+" / "+s2+" = "+s3+"\n";
                               		Q.push(make_pair(hash2,make_pair(divi,divis)));
                                	tab[hash2].push_back(is(divi,divis));
                                	mat[hash2][divi]=1;
                                }
                            }
                            else if(number%tab[i][j].first==0)
                            {
                                int divi=number/tab[i][j].first;
                                if(!mat[hash2][divi])
                                {
                                	s3=to_string(divi);
                                	string divis=s+tab[i][j].second+s2+" / "+s1+" = "+s3+"\n";
                               	 	Q.push(make_pair(hash2,make_pair(divi,divis)));
                                	tab[hash2].push_back(is(divi,divis));
                                	mat[hash2][divi]=1;
                            	}
                            }
                        }
                    }
                }
            }
            cout<<bests;
            cout<<"Best approx: "<<best;
            cout<<"\n\n";
        }
        vis.clear();
        while(!Q.empty()) Q.pop();
        for(int i=0;i<M;++i)
        {
        	tab[i].clear();
        	mat[i].clear();
        }
    }
    return 0;
}