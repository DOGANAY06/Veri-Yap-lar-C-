#include <iostream>
using namespace std;

int main()
{
	int n;
	int a[5]={1,5,32,76,2};
	int *p=a;
	cout<<"Kacinci elemani gormek istersin"<<endl;
	cin>>n;
	cout<<"secilen ="<<a[n]<<" "<<*(p+n)<<endl;
}
