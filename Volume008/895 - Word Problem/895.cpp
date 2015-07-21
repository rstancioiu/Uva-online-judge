#include <bits/stdc++.h>
#define N 1024
#define M 26

using namespace std;
string s;
int words[N][M]={0};
int lw[M]={0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt=0;
    while(getline(cin,s) && s!="#")
    {
        for(int i=0;i<s.length();++i)
        {
            words[cnt][s[i]-'a']++;
        }
        cnt++;
    }
    while(getline(cin,s) && s!="#")
    {
        for(int i=0;i<M;++i)
            lw[i]=0;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]>='a' && s[i]<='z')
                lw[s[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<cnt;++i)
        {
            int j;
            for(j=0;j<M;++j)
                if(lw[j]<words[i][j])
                    break;
            if(j==M)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}