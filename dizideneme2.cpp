#include <iostream>

using namespace std;


int main()
{
	int dizi1[5]={12,32,12,213,431};
	int dizi2[5]={23,123,123,452,3};
	int dizi3[5];
	int i;
	int temporary;
	for(i=0;i<5;i++)
	{
		temporary=dizi1[i]+dizi2[i];
		dizi3[i]=temporary;
	}
	for(i=0;i<5;i++)
	{
		cout<<dizi3[i]<<endl;
	}
}
