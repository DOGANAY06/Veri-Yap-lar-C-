#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct ciftb{
	int bilgi;
	struct ciftb *on;
	struct ciftb *arka;
}BAGLISTE;

BAGLISTE *ilk = NULL, *son =NULL;

void basaEkle(int sayi);
void arayaEkle(int key,int sayi);
void bastanSil();
void sondanSil();
void aradanSil(int key);
void  sonaEkle(int sayi);
int listele();
void yazEkrana(BAGLISTE *yazilacak);

int main()
{
	int sayi,sonuc,sayi2;
	char secim;
	do
	{
		cout<<"B= BASA EKLE "<<endl;
		cout<<"S= Sona ekle"<<endl;
		cout<<"A= Araya ekle"<<endl;
		cout<<"Y= yazdir cikmak \n Cikmak icin='Q' "<<endl;
		cout<<"P= BASTAN sil \n N = SONDAN SÝL \n Aradan sil =D \n";
		cin>>secim;
		switch(secim)
		{
			case 'B':
				cout<<"Basa eklenecek sayi giriniz =";
				cin>>sayi;
				basaEkle(sayi);
				break;
			case 'S':
				cout<<"Sona eklenecek sayiyi giriniz =";
				cin>>sayi;
				sonaEkle(sayi);
				break;
			case 'A':
				cout<<"Araya eklenecek sayiyi giriniz =";
				cin>>sayi;
				cout<<"Hangi sayidan once eklenecek = ";
				cin>>sayi2;
				arayaEkle(sayi,sayi2);
				break;
			case 'Y':
				sonuc = listele();
				if(sonuc==1)
				cout<<"\n Bos liste \n";
				break;
			case 'P':
				bastanSil();
				break;
			case 'N':
				sondanSil();
				break;
			case 'D':
				cout<<"Aradan silinecek sayi \n";
				cin>>sayi;
				aradanSil(sayi);
				break;
			default:
				cout<<"Hatali islem secimi \n";
				break;
		}
	}while(secim!='Q');
	cout<<"Islemler durduruldu";
	return 0;
}

void bastanSil()
{
	if(ilk ==NULL)
	{
		cout<<"Liste bostur \n";
	}
	else
	{
		if(ilk->arka == NULL)
		{
			delete ilk;
			ilk =NULL;
			cout<<"Listede tek eleman var onun icin sildim onuda";
		}
		else
		{
			BAGLISTE *temp =ilk->arka; //ilk eleman deðil ondan sonraki elemanlarý kontrol edicek
			delete ilk;
			cout<<"Bastaki eleman silindi";
			ilk = temp;
			ilk->on=NULL; //bir onceki dugumu sildim cünkü
		}
	}
}
void sondanSil()
{
	if(ilk ==NULL)
	{
		cout<<"Liste bostur \n";
	}
	else
	{
		if(ilk->arka == NULL)
		{
			delete ilk;
			ilk =NULL;
			cout<<"Listede tek eleman var onun icin sildim onuda";
		}
		else
		{
		    BAGLISTE *temp = ilk; //bastan baþladýk
			while(temp->arka!=NULL){
				//sonuna gelene kadar devam etsin
				temp = temp->arka;
			}	
			BAGLISTE *temp2 =temp->on; //temp son dugumdur temp2 son dugumden bir onceki dugum gosterir
			delete temp;
			temp2->arka=NULL; //temp2 son dugum oldu 
			cout<<"Sondan eleman silindi";
		}
	}
}

void aradanSil(int key)
{
	if(ilk==NULL)
	{
		cout<<"Liste bostur \n";
	}
	else
	{
		if(ilk->arka==NULL && ilk->bilgi==key)
		{
			delete ilk;
			ilk=NULL;
			cout<<"Listede tek dugum var onuda sildik \n";
		}
		else
		{
			BAGLISTE *temp =ilk; //en bastaki dugumu aldýk 
			while(temp->arka !=NULL) //son elemana gelene kadar devam et 
			{
				if(temp->bilgi==key) //istenen eleman bulunduysa 
				{
					BAGLISTE *temp2 = temp->on; //istenen elemandan onceki dugumu atadýk 
					BAGLISTE *temp3 = temp->arka; //tempten sonraki dugum 
					delete temp;
					//ara bosaldý degiskenleri birbirine baglicaz 
					temp2->arka=temp3;
					temp3->on=temp2;
					cout<<"Aradaki eleman silindi";
					break;
				}
				temp = temp->arka;
			}
		}
	}
}

void yazEkrana(BAGLISTE *yazilacak)
{
	cout<<yazilacak->bilgi<<endl;
}
void arayaEkle(int key,int sayi){
	BAGLISTE *p;
	p = new BAGLISTE;
	p->bilgi=key;
	if(ilk ==NULL)
	{ //ilk elemansa 
		ilk =p;
		ilk->arka=NULL;
		ilk->on=NULL;
		cout<<"Ilk eleman eklendi \n";
	}
	else //bos deðilse yine ilk elemana ekle satýrý artýr
	{
		BAGLISTE *temp =ilk;
		while(temp->arka!=NULL)
		{
			if(temp->bilgi==sayi) //gecici bilgi esitse girilen bilgiye
			{
				BAGLISTE *temp2= temp->on; //gecici deðiþkenin oncesi 
				BAGLISTE *temp3 =temp; //tempin kendisi ve bironceki arasýna eklicez 
				//bunlarý tutuyoruz cünku bunlarýn arasýna koyacaz
				temp2->arka=p;
				p->on=temp2; //girilen elemandan onceki sayi tutulacak
				p->arka=temp3; //elemandan sonraki sayý gozukecek 
				cout<<"Araya ekleme yapildi"<<endl;
				break; //ekleme oldugu icin durdurabiliriz 
			}
			temp = temp->arka; //dongüyü artýran yer 
		}
			if(temp->bilgi==sayi) //gecici bilgi esitse girilen bilgiye
			{
				BAGLISTE *temp2= temp->on; //gecici deðiþkenin oncesi 
				BAGLISTE *temp3 =temp; //tempin kendisi ve bironceki arasýna eklicez 
				//bunlarý tutuyoruz cünku bunlarýn arasýna koyacaz
				temp2->arka=p;
				p->on=temp2; //girilen elemandan onceki sayi tutulacak
				p->arka=temp3; //elemandan sonraki sayý gozukecek 
				cout<<"Araya ekleme yapildi"<<endl; 
			}
	}
}

void basaEkle(int sayi){ //hangi sayidan önce eklenecek ve hangi sayý eklenecek
	BAGLISTE *p;
	p = new BAGLISTE;
	p->bilgi=sayi;
	if(ilk ==NULL)
	{
		ilk =p;
		ilk->arka=NULL;
		ilk->on=NULL;
		cout<<"Ilk eleman eklendi \n";
	}
	else //bos deðilse yine ilk elemana ekle satýrý artýr
	{
		p->on=ilk;
		ilk->arka=p;
		ilk=p;
		cout<<"Liste dolu olsa bile basa eleman eklendi \n";
	}
}

void sonaEkle(int sayi)
{
	BAGLISTE *p;
	p = new BAGLISTE;
	p->bilgi=sayi;
	if(ilk ==NULL)
	{
		ilk =p;
		ilk->arka=NULL;
		ilk->on=NULL;
		cout<<"Sona eleman eklendi \n";
	}
	else //bos deðilse yine ilk elemana ekle satýrý artýr
	{
		BAGLISTE *temp =ilk; //elemanin içindeki ilk elemaný atadýk 
		while(temp->arka!=NULL) //sonu bulunana kadar git
		{
			temp = temp->arka; //tempten önce gosterilen NULL degilse devam et 	
		}
		temp->arka =p; //son eleman artýk son eleman deðil son elemaný gösteren eleman 
		p->on =temp; //verecegimiz son eleman onceki elemaný onceki son elemaný gosterir 
		p->arka =NULL; //sonraki elemani boþu gösterecek cünkü son elemandaydýk 
		cout<<"son eleman eklendi "<<endl;
	}	
}
int listele()
{
	BAGLISTE *p; // structýrýmýzýn göstereceði adres
	p = new BAGLISTE ; //yeni bir liste olustur bellekte
	p = ilk ; //ilk elemaný esitledik
	if(p==NULL) //listelenecek liste boþþa
	{
		return 1; //boþ liste yazmasý için return 1 döndürdük 
	}
	while (p!=NULL){
		yazEkrana(p);
		p = p->arka; //listenin sonraki elemanlarýný gösterere ekrana yazdýr 
	}
	return 0;
}

