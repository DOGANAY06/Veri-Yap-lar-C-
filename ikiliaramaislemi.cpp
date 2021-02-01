#include <iostream>
using namespace std;

int ikili(int dizi[],int boyut,int aranan);
int main()
{
	int dizi[]={1,2,3,4,5,6,8,9,14};
	int boyut =10;
	int aranan;
	cout<<"Aradiginiz eleman nedir =\n";
	cin>>aranan;
	ikili(dizi,boyut,aranan);
	return 0;
}

int ikili(int dizi[],int boyut,int aranan)
{
	int enkucukindis=0;
	int enbuyukindis =boyut-1; //cünkü indis degeri dizide 0 dan baslar
	while(enbuyukindis>=enkucukindis)
	{
		int orta =(enkucukindis + enbuyukindis) /2;
		if(dizi[orta]==aranan)
		{
			cout<<"Aranan eleman bulundu \n";
			break;
		}
		if(dizi[orta]<aranan)
		{
			enkucukindis=orta+1;
		}
		if(dizi[orta]>aranan)
		{
			enbuyukindis = orta-1;
		}
	}
}

