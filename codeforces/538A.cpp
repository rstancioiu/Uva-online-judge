#include <bits/stdc++.h>

using namespace std;
string s;
const string check="CODEFORCES";

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	int i;
    for(i=0;i<check.length();++i)
        if(s[i]!=check[i])
            break;
    for(;i<check.length();++i)
    {
        if(s[i+s.length()-check.length()]!= check[i])
            break;
    }
    if(i==check.length())
        cout<<"YES\n";
    else cout<<"NO\n";
	return 0;
}