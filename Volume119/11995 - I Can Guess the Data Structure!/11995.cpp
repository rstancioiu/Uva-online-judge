#include <bits/stdc++.h>

using namespace std;
stack<int> S;
priority_queue<int> PQ;
queue<int> Q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int  n;
	int type,x;
	while(cin>>n)
	{
		bool s=true;
		bool pq=true;
		bool q=true;
		for(int i=0;i<n;++i)
		{
			cin>>type>>x;
			if(type==1)
			{
				S.push(x);
				PQ.push(x);
				Q.push(x);
			}
			else
			{
				if(S.empty())
					s=false;
				else if(s && S.top()!=x)
					s=false;
				else if(s) S.pop();
				if(PQ.empty())
					pq=false;
				if(pq && PQ.top()!=x)
					pq=false;
				else if(pq)
					PQ.pop();
				if(Q.empty())
					q=false;
				if(q && Q.front()!=x)
					q=false;
				else if(q)
					Q.pop();
			}
		}
		while(!S.empty()) S.pop();
		while(!PQ.empty()) PQ.pop();
		while(!Q.empty()) Q.pop();
		if(!s && !q && !pq)
			cout<<"impossible"<<endl;
		else if(s && !q && !pq)
			cout<<"stack"<<endl;
		else if(!s && q && !pq)
			cout<<"queue"<<endl;
		else if(!s && !q && pq)
			cout<<"priority queue"<<endl;
		else
			cout<<"not sure"<<endl;
	}
	return 0;
}