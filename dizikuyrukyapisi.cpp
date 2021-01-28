#include <iostream>
#include <stdlib.h>
using namespace std;
#define n 5 
int Yveri[n] = {0},on =0, arka =0;



int ekle(int deger);
int al();
void kaydir();
void listele();
void bosalt();

int main()
{
	int sayi;
	char secim;
	do{
		cout<<"Ekleme icin = E \n Alma icin = A \n Bosaltma icin B \n Listele = L \n Cikis icin = Q \n";
		cin>>secim;
		switch(secim)
		{
			case 'E':
				cout<<"Eklemek istediginiz sayiyi giriniz = \n";
				cin>>sayi;
				ekle(sayi);
				break;
			case 'A':
				al();
				break;
			case 'B':
				bosalt();
				break;
			case 'L':
			    listele();
				break;
			case 'Q':
			    cout<<"Cikis islemi secildi \n"<<endl;
				break;
			default:
			    cout<<"Hatali secim tekrar deneyiniz \n";	
		}
	}while(secim!='Q');
	cout<<"Cikis islemi yapiliyor"<<endl;
}

void bosalt()
{
	arka = 0;
}

void listele()
{
	if(arka<=0)
	{
		cout<<"Kuyruk bos ! ";
	}
	for(int i= 0;i<arka;i++)
	{
		cout<<"Kuyruk bilgisi = \n"<<Yveri[i]<<endl;
	}
}

void kaydir()
{
	for(int i=1;i<=arka;i++) //ilk elemandan baslasin son elemana esit olana kadar artsýn sonra son elemaný son elemandan bir kucuk sayiya atsin 
	{
		Yveri[i-1]=Yveri[i]; //bu amacla ilk olan elemaný yok ediyoruz
	}
}

int al()
{
	if (Yveri[n]==NULL)
	{
		cout<<"Liste bos \n";
	}
	else
	{
		int tmp=Yveri[0]; //ilk elemani alacagýmýz icin 0. indis secildi
		kaydir();
		arka--;
		return tmp;
	}
}

int ekle(int deger)
{
	if(arka>n)
	{
		cout<<"Kuyruk dolu \n ";
		return -1;
	}
	else
	{
		Yveri[arka]=deger;
		arka++;
	}
}
