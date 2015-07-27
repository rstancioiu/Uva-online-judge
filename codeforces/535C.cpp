#include <iostream>
#define N 1000010

using namespace std;
long long int A,B,n;
long long int t,m;
int l;
long long int tab[N];

int main()
{
    long long int sum[N];
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B>>n;
    tab[1]=A;
    sum[1]=A;
    for(int i=2;i<N;++i)
    {
        tab[i]=A+B*(i-1);
        sum[i]=sum[i-1]+tab[i];
    }

    for(int i=0;i<n;++i)
    {
        cin>>l>>t>>m;
        long long int p=t*m;
        if(tab[l]>t || tab[l]>p)
        {
            cout<<"-1"<<endl;
            continue;
        }
        int ans=-1;
        int aux1=l;
        int r=N-1;
        while(aux1<r)
        {
            int middle=aux1+(r-aux1)/2;
            long long int k=sum[middle]-sum[l-1];
            if(k>p)
                r=middle-1;
            else
                aux1=middle+1;
        }
        if(sum[aux1]-sum[l-1]>p)
            aux1--;
        int aux2=l;
        r=N-1;
        while(aux2<r)
        {
            int middle=aux2+(r-aux2)/2;
            if(tab[middle]>t)
                r=middle-1;
            else
                aux2=middle+1;
        }
        if(tab[aux2]>t)
            aux2--;
        cout<<((aux1>aux2)?aux2:aux1)<<endl;

    }
    return 0;
}