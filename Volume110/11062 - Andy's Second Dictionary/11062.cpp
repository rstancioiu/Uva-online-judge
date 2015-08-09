#include <bits/stdc++.h>

using namespace std;
set<string> dict;
string s,word;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    word="";
    while(getline(cin,s))
    {
        if(s!="")
        {
            int i;
            for(i=0;i<s.length()-1;++i)
            {
                if(s[i]>='A' && s[i]<='Z')
                    word+=(s[i]+32);
                else if(s[i]>='a' && s[i]<='z')
                    word+=s[i];
                else if(s[i]=='-')
                    word+=s[i];
                else if(word!="")
                {
                    set<string>::iterator it=dict.find(word);
                    if(it==dict.end())
                        dict.insert(word);
                    word="";
                }
            }
            if(s[i]>='A' && s[i]<='Z')
            {
                word+=(s[i]+32);
                set<string>::iterator it=dict.find(word);
                if(it==dict.end())
                    dict.insert(word);
                word="";
            }
            else if(s[i]>='a' && s[i]<='z')
            {
                word+=s[i];
                set<string>::iterator it=dict.find(word);
                if(it==dict.end())
                    dict.insert(word);
                word="";
            }
            else if(s[i]!='-' && word!="")
            {
                set<string>::iterator it=dict.find(word);
                if(it==dict.end())
                    dict.insert(word);
                word="";
            }
        }
        else if(word!=""){
            set<string>::iterator it=dict.find(word);
            if(it==dict.end()){
                dict.insert(word);
            }
            word="";
        }
    }
    if(word!="")
    {
        set<string>::iterator it=dict.find(word);
        if(it==dict.end())
            dict.insert(word);
            word="";
    }    
    set<string>::iterator it=dict.begin();
    for(;it!=dict.end();++it)
        cout<<*it<<endl;
    return 0;
}