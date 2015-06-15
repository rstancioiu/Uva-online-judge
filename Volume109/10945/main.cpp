#include <bits/stdc++.h>

using namespace std;
string s;
vector<char> tab;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<26;++i)
    {
        tab.push_back('a'+i);
    }
    while(getline(cin,s) && s!="DONE")
    {
        int i=0;
        int j=s.length()-1;
        bool pali=true;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                s[i]=s[i]-'A'+'a';
            }
        }
        while(i<j)
        {
            int k1,k2;
            for(k1=0;k1<tab.size();++k1)
                if(s[i]==tab[k1])
                    break;
            for(k2=0;k2<tab.size();++k2)
                if(s[j]==tab[k2])
                    break;
            if(k1==tab.size() && k2==tab.size())
            {
                i++;
                j--;
            }
            else if(k1==tab.size() && k2<tab.size())
            {
                i++;
            }
            else if(k1<tab.size() && k2==tab.size())
            {
                j--;
            }
            else if(k1!=k2)
            {
                pali=false;
                break;
            }
            else 
            {
                i++;
                j--;
            }
        }
        if(!pali)
            cout<<"Uh oh..\n";
        else
            cout<<"You won't be eaten!\n";
    }
    return 0;
}