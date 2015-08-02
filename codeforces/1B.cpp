#include <cstdio>

using namespace std;
char s[128];

void print(int x)
{
    if(x==0)
        return;
    if(x%26!=0)
    {
        print(x/26);
        printf("%c",x%26+'A'-1);
    }
    else
    {
        print((x-1)/26);
        printf("Z");
    }
}

int main()
{
    //freopen("test.txt","r",stdin);
    int n,x,y;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",&s);
        y=-1;
        if(sscanf(s,"R%dC%d",&x,&y) && y!=-1)
        {
            print(y);
            printf("%d\n",x);
        }
        else
        {
            x=y=0;
            int i=0;
            while(s[i]>='A'&&s[i]<='Z')
            {
                y*=26;
                y+=(s[i]-'A'+1);
                i++;
            }
            while(s[i])
            {
                x=(x<<1)+(x<<3)+s[i]-'0';
                i++;
            }
            printf("R%dC%d\n",x,y);
        }
    }
    return 0;
}