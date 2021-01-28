#include <iostream>

using namespace std;


int usal(int a,int b);
double usal(double a,double b);

int main()
{
	int x;
	double y;
	x=usal(2,10);
	y=usal(3.2,12.2);
	cout<<x <<endl;
	cout<<y<<endl;
}

int usal(int a,int b)
{
	return (a*a)+(b*b);
}
double usal(double a,double b)
{
	return (a*a)+(b*b);
}
