// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/117/11752.html
#include <bits/stdc++.h>
#define N 65536
#define MAX 18446744073709551615

using namespace std;
vector<unsigned long long int> ans;
int tab[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
int visited[N]={0};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ans.push_back(1);
	int cntaux=64;
	for(int i=2;i<N;++i)
	{
	    if(!visited[i])
        {
            unsigned long long int p=i;
            int cnt=1;
            int j=0;
            while(MAX/p>=i && cnt<=cntaux)
            {
                if(p<N)
                    visited[p]=1;
                p*=i;
                cnt++;
                if(cnt==tab[j])
                {
                    j++;
                }
                else
                {
                    ans.push_back(p);
                }
            }
            cntaux=cnt;
        }
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();++i)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
