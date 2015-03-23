#include <cstdio>
#include <vector>
#include <stack>
#define N 2048

using namespace std;
vector<long long int> v[N];
char c[N][N];

int readInt()
{
	int n=0;
	char c=getchar();
	while(c<'0'|| c>'9') c=getchar();
	while(c>='0' && c<='9')
	{
		n=(n<<1)+(n<<3)+c-'0';
		c=getchar();
	}
	return n;
}

long long int largArea(vector<long long int> t)
{
	stack<int> s;
	int i=0;
	int n=t.size();
	long long int area_max=0;
	while(i<n)
	{
		if(s.empty() || t[s.top()]<t[i])
			s.push(i++);
		else
		{
		 	int p=s.top();
		 	s.pop();
		 	long long int area=t[p]*(s.empty() ? i : i-s.top()-1);
		 	if(area>area_max)
		 		area_max=area;
		}
	}
	while(!s.empty())
	{
		int p=s.top();
		s.pop();
		long long int area = t[p]*(s.empty() ? i : i-s.top()-1);
		if(area > area_max)
			area_max = area;
	}
	return area_max;
}



int main()
{
	int t,m,n;
	t=readInt();
	while(t--)
	{
		char ch;
		m=readInt();
		n=readInt();
		for(int i=0;i<m;++i)
		{
			v[i].clear();
			for(int j=0;j<n;++j)
			{
				char ch = getchar();  
                while(ch!='R' && ch!='F'){  
                    ch=getchar();  
                } 
				c[i][j]=ch;
			}
		}
		for(int i=0;i<n;++i)
		{
			if(c[0][i]=='F')
				v[0].push_back(1);
			else if(c[0][i]=='R') v[0].push_back(0);
		}
		for(int i=1;i<m;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(c[i][j]=='F')
				{
					v[i].push_back(v[i-1][j]+1);
				}
				else if(c[i][j]=='R')
					 v[i].push_back(0);
			}
		}
		long long int area_max=0;
		for(int i=0;i<m;++i)
		{
			long long int area=largArea(v[i]);
			if(area>area_max)
				area_max=area;
		}
		printf("%lld\n", area_max*3);
	}
	return 0;
}