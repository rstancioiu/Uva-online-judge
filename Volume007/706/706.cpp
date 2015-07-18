// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/7/706.html
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int nb=0;
	int s,k;
    while(1)
    {
        string t;
        string n;
        getline(cin,t);
        istringstream iss(t);
        iss>>s;
        iss>>n;
        if(nb++)
            cout<<endl;
        int i;
        if(s==0 && n.length()==1 && n[0]=='0')
            break;
        string str;
        for(int j=0; j<n.length(); ++j)
        {
            if(n[j]=='0')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
            }
            if(n[j]=='1')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+=' ';
                str+=' ';            
            }
            if(n[j]=='2')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
            }
            if(n[j]=='3')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
            }
            if(n[j]=='4')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+=' ';
                str+=' ';
            }
            if(n[j]=='5')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
            }
            if(n[j]=='6')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
            }
            if(n[j]=='7')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
            }
            if(n[j]=='8')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
            }
            if(n[j]=='9')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
            }
            if(j!=n.length()-1 && n[j]>='0' && n[j]<='9')
            	str+=' ';
        }
        cout<<str<<endl;

        for(int t=0; t<s; ++t)
        {
            str="";
            for(int j=0; j<n.length(); ++j)
            {
                if(n[j]=='0')
                {
                    str+='|';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
                }
                if(n[j]=='1')
                {
                    str+=' ';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
        
                }
                if(n[j]=='2')
                {
                    str+=' ';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
                  
                }
                if(n[j]=='3')
                {
                    str+=' ';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
                  
                }
                if(n[j]=='4')
                {
                    str+='|';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
                  
                }
                if(n[j]=='5')
                {
                    str+='|';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+=' ';
                  
                }
                if(n[j]=='6')
                {
                    str+='|';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+=' ';
                   
                }
                if(n[j]=='7')
                {
                    str+=' ';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
                
                }
                if(n[j]=='8')
                {
                    str+='|';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
                 
                }
                if(n[j]=='9')
                {
                    str+='|';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
                 
                }
                if(j!=n.length()-1 && n[j]>='0' && n[j]<='9')
                	str+=' ';
            }
            cout<<str<<endl;
        }

        str="";
        for(int j=0; j<n.length(); ++j)
        {
            if(n[j]=='0')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+=' ';
                str+=' ';
  
            }
            if(n[j]=='1')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+=' ';
                str+=' ';
          
            }
            if(n[j]=='2')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
         
            }
            if(n[j]=='3')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
            
            }
            if(n[j]=='4')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
           
            }
            if(n[j]=='5')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
          
            }
            if(n[j]=='6')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
  
            }
            if(n[j]=='7')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+=' ';
                str+=' ';
   
            }
            if(n[j]=='8')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
        
            }
            if(n[j]=='9')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';

            }
            if(j!=n.length()-1 && n[j]>='0' && n[j]<='9')
               str+=' ';
        }
        cout<<str<<endl;



        for(int t=0; t<s; ++t)
        {
            str="";
            for(int j=0; j<n.length(); ++j)
            {
                if(n[j]=='0')
                {
                    str+='|';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
        
                }
                if(n[j]=='1')
                {
                    str+=' ';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
      
                }
                if(n[j]=='2')
                {
                    str+='|';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+=' ';
        
                }
                if(n[j]=='3')
                {
                    str+=' ';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
        
                }
                if(n[j]=='4')
                {
                    str+=' ';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
         
                }
                if(n[j]=='5')
                {
                    str+=' ';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
            
                }
                if(n[j]=='6')
                {
                    str+='|';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
          
                }
                if(n[j]=='7')
                {
                    str+=' ';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
        
                }
                if(n[j]=='8')
                {
                    str+='|';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
       
                }
                if(n[j]=='9')
                {
                    str+=' ';
                    for(i=0; i<s; ++i)
                        str+=' ';
                    str+='|';
             
                }
                 if(j!=n.length()-1 && n[j]>='0' && n[j]<='9')
                	str+=' ';
            }
            cout<<str<<endl;
        }
        str="";
        for(int j=0; j<n.length(); ++j)
        {
            if(n[j]=='0')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
            }
            if(n[j]=='1')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+=' ';
                str+=' ';
            }
            if(n[j]=='2')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
            }
            if(n[j]=='3')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
            }
            if(n[j]=='4')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+=' ';
                str+=' ';
            }
            if(n[j]=='5')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
            }
            if(n[j]=='6')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
            }
            if(n[j]=='7')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+=' ';
                str+=' ';
            }
            if(n[j]=='8')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
            }
            if(n[j]=='9')
            {
                str+=' ';
                for(i=0; i<s; ++i)
                    str+='-';
                str+=' ';
            }
            if(j!=n.length()-1 && n[j]>='0' && n[j]<='9')
            	str+=' ';
        }
        cout<<str<<endl;
    }
    return 0;
}
