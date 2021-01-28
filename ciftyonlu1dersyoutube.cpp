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
		cout<<"P= BASTAN sil \n N = SONDAN S�L \n Aradan sil =D \n";
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
			BAGLISTE *temp =ilk->arka; //ilk eleman de�il ondan sonraki elemanlar� kontrol edicek
			delete ilk;
			cout<<"Bastaki eleman silindi";
			ilk = temp;
			ilk->on=NULL; //bir onceki dugumu sildim c�nk�
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
		    BAGLISTE *temp = ilk; //bastan ba�lad�k
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
			BAGLISTE *temp =ilk; //en bastaki dugumu ald�k 
			while(temp->arka !=NULL) //son elemana gelene kadar devam et 
			{
				if(temp->bilgi==key) //istenen eleman bulunduysa 
				{
					BAGLISTE *temp2 = temp->on; //istenen elemandan onceki dugumu atad�k 
					BAGLISTE *temp3 = temp->arka; //tempten sonraki dugum 
					delete temp;
					//ara bosald� degiskenleri birbirine baglicaz 
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
	else //bos de�ilse yine ilk elemana ekle sat�r� art�r
	{
		BAGLISTE *temp =ilk;
		while(temp->arka!=NULL)
		{
			if(temp->bilgi==sayi) //gecici bilgi esitse girilen bilgiye
			{
				BAGLISTE *temp2= temp->on; //gecici de�i�kenin oncesi 
				BAGLISTE *temp3 =temp; //tempin kendisi ve bironceki aras�na eklicez 
				//bunlar� tutuyoruz c�nku bunlar�n aras�na koyacaz
				temp2->arka=p;
				p->on=temp2; //girilen elemandan onceki sayi tutulacak
				p->arka=temp3; //elemandan sonraki say� gozukecek 
				cout<<"Araya ekleme yapildi"<<endl;
				break; //ekleme oldugu icin durdurabiliriz 
			}
			temp = temp->arka; //dong�y� art�ran yer 
		}
			if(temp->bilgi==sayi) //gecici bilgi esitse girilen bilgiye
			{
				BAGLISTE *temp2= temp->on; //gecici de�i�kenin oncesi 
				BAGLISTE *temp3 =temp; //tempin kendisi ve bironceki aras�na eklicez 
				//bunlar� tutuyoruz c�nku bunlar�n aras�na koyacaz
				temp2->arka=p;
				p->on=temp2; //girilen elemandan onceki sayi tutulacak
				p->arka=temp3; //elemandan sonraki say� gozukecek 
				cout<<"Araya ekleme yapildi"<<endl; 
			}
	}
}

void basaEkle(int sayi){ //hangi sayidan �nce eklenecek ve hangi say� eklenecek
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
	else //bos de�ilse yine ilk elemana ekle sat�r� art�r
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
	else //bos de�ilse yine ilk elemana ekle sat�r� art�r
	{
		BAGLISTE *temp =ilk; //elemanin i�indeki ilk eleman� atad�k 
		while(temp->arka!=NULL) //sonu bulunana kadar git
		{
			temp = temp->arka; //tempten �nce gosterilen NULL degilse devam et 	
		}
		temp->arka =p; //son eleman art�k son eleman de�il son eleman� g�steren eleman 
		p->on =temp; //verecegimiz son eleman onceki eleman� onceki son eleman� gosterir 
		p->arka =NULL; //sonraki elemani bo�u g�sterecek c�nk� son elemandayd�k 
		cout<<"son eleman eklendi "<<endl;
	}	
}
int listele()
{
	BAGLISTE *p; // struct�r�m�z�n g�sterece�i adres
	p = new BAGLISTE ; //yeni bir liste olustur bellekte
	p = ilk ; //ilk eleman� esitledik
	if(p==NULL) //listelenecek liste bo��a
	{
		return 1; //bo� liste yazmas� i�in return 1 d�nd�rd�k 
	}
	while (p!=NULL){
		yazEkrana(p);
		p = p->arka; //listenin sonraki elemanlar�n� g�sterere ekrana yazd�r 
	}
	return 0;
}

