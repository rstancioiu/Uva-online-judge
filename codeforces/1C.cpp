#include <cstdio>
#include <cmath>
#define PI 3.14159265
using namespace std;

int main()
{
    //freopen("test.txt","r",stdin);
    int n;
    double x1,y1,x2,y2,x3,y3;
    scanf("%lf%lf",&x1,&y1);
    scanf("%lf%lf",&x2,&y2);
    scanf("%lf%lf",&x3,&y3);
    double a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    double b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
    double c=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    double s=(a+b+c)/2;
    double Atriangle=sqrt(s*(s-a)*(s-b)*(s-c));
    double R=a*b*c/(4*Atriangle);
    double cosa=(b*b+c*c-a*a)/(2*b*c);
    double cosb=(a*a+c*c-b*b)/(2*a*c);
    double cosc=(b*b+a*a-c*c)/(2*b*a);
    double anglea=acos(cosa)*180.0/PI;
    double angleb=acos(cosb)*180.0/PI;
    double anglec=acos(cosc)*180.0/PI;
    for(int i=1;i<2000;++i)
    {
        double diffa=double(anglea*i/180)-round(double(anglea*i/180));
        double diffb=double(angleb*i/180)-round(double(angleb*i/180));
        double diffc=double(anglec*i/180)-round(double(anglec*i/180));
        if(abs(diffa)<0.0001 && abs(diffb) <0.0001 && abs(diffc) <0.0001)
        {
            n=i;
          break;
        }
    }
    double A=R*R*n*sin(2*PI/n)/2;
    printf("%lf\n",A);
    return 0;
}