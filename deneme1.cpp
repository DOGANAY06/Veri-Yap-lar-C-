#include <iostream>
using namespace std;
int main()
{
	int i;
	int a[10]={1,3,4,5,7,93,2,3,5,78}; 
	int enbuyuk=a[0];
	for(i=0;i<10;i++)
	{
		if(enbuyuk<a[i])
		{
			enbuyuk=a[i];
		}
	}
	cout<<"En buyuk sayi: "<<enbuyuk<<endl;
	return 0;
}
