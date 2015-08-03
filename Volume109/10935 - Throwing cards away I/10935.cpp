#include <bits/stdc++.h>

using namespace std;
queue<int> Q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n && n!=0)
	{
		for(int i=1;i<=n;++i)
		{
			Q.push(i);
		}
		if(n>1)
        {
            cout<<"Discarded cards: "<<Q.front();
            Q.pop();
            int t=Q.front();
            Q.pop();
            Q.push(t);
            while(Q.size()>1)
            {
                cout<<", "<<Q.front();
                Q.pop();
                int t=Q.front();
                Q.pop();
                Q.push(t);
            }
        }
        else cout<<"Discarded cards:";
		cout<<endl<<"Remaining card: "<<Q.front()<<endl;
		Q.pop();
	}

	return 0;
}
