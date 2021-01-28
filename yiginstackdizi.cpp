#include <iostream>
#include <stdlib.h>

using namespace std;
#define n 50
int Yveri[n]={0}; //yigin verisi tanimlama
int yi =0;

int ekle(int veri);
int al();

void listele();
void bosalt();

void terscevir();

int main()
{
	int bilgi,sonuc;
	char secim;
	while(1)
	{
	cout<<"\n Ekleme icin =E \n Veri alma icin =A \n Bosaltmak icin B \n Listelemek icin = L \n Cikis yapmak = C \n tuslarýna basiniz \n";
	cin>>secim;
	switch(secim)
	{
		case 'E':
			cout<<"Kaydetmek istediginiz bilgiyi giriniz = \n";
			cin>>bilgi;
			ekle(bilgi);
			break;
		case 'A':
			sonuc =al();
			cout<<"Yigin verisi ="<<sonuc<<endl;
			break;
		case 'L':
			listele();
			break;
		case 'B':
			bosalt();
			break;
		case 'T':
			terscevir();
			break;
		case 'C':
			cout<<"Cikis yapiliyor \n";
			exit(0);
		default:
		    cout<<"Yanlis secim yapildi \n";	
		}
	}
}

int ekle(int veri)
{
	if (yi>n)
	{
		cout<<"Yigin dolu";
		return -1;
	}
	else{
		Yveri[yi]=veri; //gelen veriyi yýgýnýmýza ekle 
		yi++; //yigini 1 satýr arttýr
	}
}
int al()
{
	if (yi<=0)
	{
		cout<<"Yigin bos"<<endl;
	}
	else{
		yi=-1; //yi 1 azalttacagiz 
		return Yveri[yi];
	}
}

void listele()
{
	if (yi<=0)
	{
		cout<<"Yigin bos"<<endl;
	}
	int temp =yi;
	temp--;
	while(temp>=0)
	{
	    cout<<" \n Yigin verisi"<<Yveri[temp];	
	    temp--;
	}
}
void bosalt()
{
	yi=0; //0 a esitler veriyi 
}



