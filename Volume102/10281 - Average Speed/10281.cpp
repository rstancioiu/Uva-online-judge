// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/102/10281.html
#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

int main()
{
	int speed,currentSpeed=0;
	int hour,min,sec;
	int currentHour=0;
	int prevHour=0;
	string s;
	double km=0;
	while(getline(cin,s))
	{
		istringstream iss(s);
		iss>>s;
		int i=0;
		hour=min=sec=0;
		while(s[i]>='0' && s[i]<='9')
		{
			hour*=10;
			hour+=s[i]-'0';
			i++;
		}
		i++;
		while(s[i]>='0' && s[i]<='9')
		{
			min*=10;
			min+=s[i]-'0';
			i++;
		}
		i++;
		while(s[i]>='0' && s[i]<='9')
		{
			sec=sec*10 + s[i]-'0';
			i++;
		}
		currentHour=hour*3600+min*60+sec;
		if(!(iss>>speed))
		{
			km+=(double)(currentHour-prevHour)/3600*currentSpeed;
			prevHour=currentHour;
			printf("%s %.2f km\n",s.c_str(),km);
		}
		else
		{
			km+=(double)(currentHour-prevHour)/3600*currentSpeed;
			prevHour=currentHour;
			currentSpeed=speed;		
		}
	}
	return 0;
}