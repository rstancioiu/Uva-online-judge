#include <iostream>
#define N 10

using namespace std;
long long int m;
long long int h1,a1;
long long int x1,y1;
long long int h2,a2;
long long int x2,y2;


int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>m;
    cin>>h1>>a1;
    cin>>x1>>y1;
    cin>>h2>>a2;
    cin>>x2>>y2;
    int t1=0;
    int t2=0;
    int change1=0;
    int change2=0;
    long long int auxh1=h1;
    long long int auxh2=h2;
    while(t1<=m+2)
    {
        if(auxh1==a1)
        {
            break;
        }
        else
        {
            auxh1=(x1*auxh1+y1)%m;
            t1++;
        }
    }
    while(t2<=m+2)
    {
        if(auxh2==a2)
        {
            break;
        }
        else
        {
            auxh2=(x2*auxh2+y2)%m;
            t2++;
        }
    }
    if(t1>m+2||t2>m+2)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(t1==t2)
        cout<<t1<<endl;
    else
    {
        auxh1=a1;
        while(1)
        {
            auxh1=(x1*auxh1+y1)%m;
            change1++;
            if(auxh1==a1)
            {
                break;
            }
            else if(change1>=m*N)
            {
                break;
            }
        }
        auxh2=a2;
        while(1)
        {
            auxh2=(x2*auxh2+y2)%m;
            change2++;
            if(auxh2==a2)
            {
                break;
            }
            else if(change2>=m*N)
            {
                break;
            }
        }
        long long int ans=0;
        long long int aux1=t1;
        long long int aux2=t2;
        bool found1=false;
        if(change1<m*N && change2<m*N)
         {
            for(int p1=0;p1<=N*m && !found1;++p1)
            {
                if((aux1-t2)%change2==0 && aux1>=t2)
                {
                    ans=aux1;
                    found1=true;
                    break;
                }
                aux1+=change1;
            }
         }
        else if(change1<m*N)
        {
            for(int p1=0;p1<=N*m && !found1;++p1)
            {
                if(aux1==t2)
                {
                    ans=t2;
                    found1=true;
                    break;
                }
                else if(aux1>t2)
                    break;
                aux1+=change1;
            }
        
        }
        else if(change2<m*N)
        {    
            for(int p1=0;p1<=N*m;++p1)
            {
                if(aux2==t1)
                {
                    ans=t1;
                    found1=true;
                    break;
                }
                else if(t1<aux2)
                    break;
                else 
                    aux2+=change2;
            }
        }
        if(found1)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}