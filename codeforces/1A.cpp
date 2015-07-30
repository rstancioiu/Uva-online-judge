#include <cstdio>

using namespace std;

int main()
{
    long long int n,m,a;
    scanf("%I64d %I64d %I64d",&n,&m,&a);
    if(n%a==0)
    {
        n/=a;
    }
    else
    {
        n/=a;
        n++;
    }
    if(m%a==0)
    {
        m/=a;
    }
    else
    {
        m/=a;
        m++;
    }
    printf("%I64d\n",m*n);
    return 0;
}