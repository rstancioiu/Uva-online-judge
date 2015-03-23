#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n,m,a;

bool CompareFunction(int a,int b)
{
	if(a==b)
		return false;
	int modulusa=a%m;
	int modulusb=b%m;
	if(modulusa>modulusb)
		return false;
	else if(modulusa==modulusb)
	{
		if((a%2+2)%2==0 && (b%2+2)%2==1)
		{
			return false;
		}
		else if((a%2+2)%2==1 && (b%2+2)%2==0)
		{
			return true;
		}
		if((a%2+2)%2==0 && (b%2+2)%2==0)
		{
			return (a>b)?false:true;
		}
		else
		{
			return (a>b)?true:false;			
		}
	}
	else 
	{
		return true;
	}
}

int main()
{
	vector<int>::iterator it;
	for(;;)
	{
		cin>>n>>m;
		if(n==0 && m==0)
		{
			cout<<n<<" "<<m<<endl;
			break;
		}
		for(int i=0;i<n;++i)
		{	
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end(),CompareFunction);
		cout<<n<<" "<<m<<endl;
		for(it=v.begin();it!=v.end();++it)
		{
			cout<<*it<<endl;
		}
		v.clear();
	}
	return 0;
}