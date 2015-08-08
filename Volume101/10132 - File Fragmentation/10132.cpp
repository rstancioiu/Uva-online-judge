#include <bits/stdc++.h>

using namespace std;
map<string,int> v;
map<string,int> dict;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    string s,t;
    map<string,int>::iterator it;
    getline(cin,s);
    getline(cin,s);
    for(int i=0;i<T;++i)
    {
        if(i)
            cout<<endl;
        int cnt=0;
        while(getline(cin,s) && s!="")
        {
            int p=0;
             map<string,int>::iterator j=v.find(s);
            if(j==v.end())
            {
                v.insert(make_pair(s,1));
                p=1;
            }
            else
                p=++j->second;

            for(j=v.begin();j!=v.end();++j)
            {
                if((j->first!=s && j->second>=p)||(j->first==s && j->second%2==0))
                {
                    t=j->first+s;
                    it=dict.find(t);
                    if(it==dict.end())
                        dict.insert(make_pair(t,1));
                     else 
                        it->second++;
                    string prev=t;
                    t=s+j->first;
                    it=dict.find(t);
                    if(it==dict.end())
                        dict.insert(make_pair(t,1));
                    else if(prev!=t)
                        it->second++;
                }
            }
            cnt++;
        }
        for(it=dict.begin();it!=dict.end();++it)
        {
            if(it->second==cnt/2)
            {
                cout<<it->first<<endl;
                break;
            }
        }
        v.clear();
        dict.clear();
    }
    return 0;
}