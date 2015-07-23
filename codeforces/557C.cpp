#include <bits/stdc++.h>
#define N 100020
#define M 201

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int ABS(int a){return (a>0)?a:-a;}
inline double MIN(double a,double b){return (a>b)?b:a;}
int n;
double w;
int l[N];
int d[N];
int v[M]={0};
int indices[N];

class sort_indices
{
   private:
     int* mparr;
   public:
     sort_indices(int* parr) : mparr(parr) {}
     bool operator()(int i, int j) { return mparr[i]>mparr[j]; }
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>l[i];
	}
	for(int i=0;i<n;++i)
	{
		cin>>d[i];
        v[d[i]]++;
	}
	for(int i=0;i<n;++i)
    {
        indices[i]=i;
    }
    sort(indices, indices+n, sort_indices(l));

	int sum=0x1fffffff;
	int sum1=0;
	for(int i=0;i<n;)
	{
		int a=l[indices[i]];
		int cnt=0;
		int sumaux=0;
		while(i<n && a==l[indices[i]])
		{
			cnt++;
			sumaux+=d[indices[i]];
			v[d[indices[i]]]--;
			i++;
		}
		int sum2=sum1;
		int j=n-i-cnt+1;
		int k=0;
        while(j!=0 && k<M)
        {
            if(v[k]>0)
            {
                if(j>v[k])
                {
                    sum2+=v[k]*k;
                    j-=v[k];
                }
                else
                {
                    sum2+=j*k;
                    j=0;
                }
            }
            k++;
        }
		if(sum2<sum)
			sum=sum2;
		sum1+=sumaux;
	}
	cout<<sum<<endl;
	return 0;
}