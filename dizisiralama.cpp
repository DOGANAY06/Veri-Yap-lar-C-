#include <iostream>

using namespace std;

int main()
{
	int mydizi[5]={1,2,5,8};
	for(int i=4;i>1;i--)
	{
		mydizi[i+1]=mydizi[i];
	}
	mydizi[2]=4;
	for(int i=0;i<5;i++)
	{
		cout<<"Elemanimiz ="<<mydizi[i]<<endl;
	}
}
