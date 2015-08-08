#include <bits/stdc++.h>

using namespace std;
string key,value;
string s;
map<string,pair<string,string> > dict;
vector<string> add;
vector<string> del;
vector<string> change;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    getline(cin,s);
    for(int k=0;k<t;++k)
    {
        getline(cin,s);
        bool turn=false;
        key="";
        value="";
        for(int i=1;i<s.length()-1;++i)
        {
            if(s[i]==':')
                turn=!turn;
            else if(s[i]==',')
            {
                turn=!turn;
                dict.insert(make_pair(key,make_pair(value,"")));
                key="";
                value="";
            }
            else if(!turn)
            {
                key+=s[i];
            }
            else 
                value+=s[i];
        }
        if(key!="" && value!="")
            dict.insert(make_pair(key,make_pair(value,"")));
        getline(cin,s);
        turn=false;
        key="";
        value="";
        for(int i=1;i<s.length()-1;++i)
        {
            if(s[i]==':')
                turn=!turn;
            else if(s[i]==',')
            {
                turn=!turn;
                map<string,pair<string,string> >::iterator it=dict.find(key);
                if(it==dict.end())
                    dict.insert(make_pair(key,make_pair(value,"add")));
                else if(value==it->second.first)
                    it->second.second="nochange";
                else
                    it->second.second="change";
                key="";
                value="";
            }
            else if(!turn)
            {
                key+=s[i];
            }
            else 
                value+=s[i];
        }
        if(key!="" && value!="")
        {
            map<string,pair<string,string> >::iterator it=dict.find(key);
            if(it==dict.end())
                dict.insert(make_pair(key,make_pair(value,"add")));
            else if(value==it->second.first)
                it->second.second="nochange";
            else
                it->second.second="change";
        }
        map<string,pair<string,string> >::iterator it;
        for(it=dict.begin();it!=dict.end();++it)
        {
            if(it->second.second=="")
                del.push_back(it->first);
            else if(it->second.second=="add")
                add.push_back(it->first);
            else if(it->second.second=="change")
                change.push_back(it->first);
        }
        sort(add.begin(),add.end());
        sort(change.begin(),change.end());
        sort(del.begin(),del.end());
        if(del.size()==0 && add.size()==0 && change.size()==0)
            cout<<"No changes"<<endl;
        if(add.size()!=0)
        {
            cout<<"+"<<add[0];
            for(int i=1;i<add.size();++i)
                cout<<","<<add[i];
            cout<<endl;
        }
        if(del.size()!=0)
        {
            cout<<"-"<<del[0];
            for(int i=1;i<del.size();++i)
                cout<<","<<del[i];
            cout<<endl;
        }
        if(change.size()!=0)
        {
            cout<<"*"<<change[0];
            for(int i=1;i<change.size();++i)
                cout<<","<<change[i];
            cout<<endl;
        }
        cout<<endl;
        dict.clear();
        add.clear();
        del.clear();
        change.clear();
    }
    return 0;
}