#include <iostream>

using namespace std;

typedef struct ciftb{
	int bilgi;
	char mesaj[100];
	struct ciftb *on;
	struct ciftb *arka;
}BAGLISTE;

BAGLISTE *ilk = NULL, *son = NULL;

BAGLISTE *ara(int),*okuKlavye();
void yazEkrana(BAGLISTE *yazilacak);
void arayaEkle(int sayi,int sayi2);
int listele();
int sil(int);
int ekle (BAGLISTE *ki);
int terscevir();

int main()
{
	BAGLISTE *eklenecek,*ki; //listeye eklenecek olan elemaný ki de listeyi gösterir
	int bilgi,sonuc,tmp,ters;
	int sayi,sayi2;
	char secim;
	do{
		cout<<"Ekleme = E \n"<<"Listeleme = L \n"<<"Arama = A \n  Ters cevirme = T \n"
		<<"Silme =S \n"<<"Araya ekleme icin ='M' \n "<<"Cikis = Q \n"<<"Secim yapiniz \n";
		cin>>secim;
		switch(secim)
		{
			case 'E':
				eklenecek = okuKlavye(); //ekleme islemi için liste yapýlacak klavyeden eleman girdisi alýnacak
				if(eklenecek!=NULL)
				//klavyeden okunan liste deðerleri ekle fonksiyonunda struct yapýmýza yazýlacak 
				ekle(eklenecek); //eklenecek listesi boþ deðilse direk ekleme listesine git 
				else
				cout<<"Ekleme icin bellek dolu \n";
				break;
			case 'L':
				sonuc = listele();
				if(sonuc==1)
				cout<<"\n Bos liste \n";
				break;
			case 'T':
				ters =terscevir();
				if(ters==1)
				cout<<"\n Bos liste \n";
				break;
			case 'M':
				cout<<"Araya eklenecek sayiyi giriniz = \n";
				cin>>sayi;
				cout<<"Hangi sayidan once eklemek istersiniz = \n";
				cin>>sayi2;
				arayaEkle(sayi,sayi2);
				break;
			case 'A':
				cout<<"Aranan ifadenin nosunu giriniz \n";
				cin>>bilgi;
				ki =ara(bilgi); //ara fonksiyonuna id no gönder ki ye koy
				if(ki==NULL)
				cout<<"Aranan bulunamadi \n";
				else
				yazEkrana(ki);
				break;
			case 'S': //silme iþlemi secildi 
				cout<<"Silinecek elemanin id no giriniz = \n";
				cin>>bilgi;
				tmp = sil(bilgi); //fonksiyondan gelen bilgiyi gecici deðiþkene ata
				if (tmp ==-1)
				{
					cout<<"Eleman silindi \n ";
				}
				else
				{
					cout<<"Silinmek istenen veri listede yok \n";
				}
				break;
			default:
				cout<<"Hatali secim tekrar yapiniz";
				break;
		}
	}while(secim!='Q');
	cout<<"Cikis secildi iyi gunler \n";
}

void yazEkrana(BAGLISTE *yazilacak)
{
	cout<<"\n Bilgi: \n "<<yazilacak->bilgi<<"Mesaj = \n"<<yazilacak->mesaj;
	
}
void arayaEkle(int sayi,int sayi2)
{
	BAGLISTE *p;
	p =new BAGLISTE;
	p->bilgi=sayi;
	if(ilk==NULL)  //ilk  eleman boþ deðilse 
	{
		ilk =p;
		ilk->on=NULL;
		ilk->arka=NULL;
		cout<<"Araya eklenecek sayi ilk oldu";
	}
	else
	{
		BAGLISTE *temp =ilk ; //ilk elemaný ilk tempte tuutuk;
		while(temp->arka!=NULL) //sonuna kadar dondur 
		{
			if(temp->bilgi==sayi2)
			{ //gecici degiskenle istenen sayi arasýna koymak icin uzlastýk mý 
				BAGLISTE *temp2 = temp->on;
				BAGLISTE *temp3 = temp ;
				temp2->arka = p;
				p->on = temp2;
				p->arka = temp3;
				cout<<"Araya ekleme basarili";
				cout<<"Mesaji giriniz \n";
				cin>>p->mesaj;
			}
			temp= temp->arka;
		}//son eleman bosa cýkmasýn onunda arasýna ekleme yapýlsýn diye yazdýk 
			if(temp->bilgi==sayi2)
			{ //gecici degiskenle istenen sayi arasýna koymak icin uzlastýk mý 
				BAGLISTE *temp2 = temp->on;
				BAGLISTE *temp3 = temp ;
				temp2->arka = p;
				p->on = temp2;
				p->arka = temp3;
				cout<<"Araya ekleme basarili";
				cout<<"Mesaji giriniz \n";
				cin>>p->mesaj;
			}
	}
}
int terscevir()
{
	BAGLISTE *p;
	p =new BAGLISTE;
	p = son;
	if(p==NULL)
	{
		return 1;
	}
	while(p!=NULL)
	{
		yazEkrana(p);
		p= p->on;
	}
	return 0 ;
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

int sil(int silinecek)
{
	BAGLISTE *p; //yeni liste oluþturuldu 
	p = new BAGLISTE; 
	p = ilk ;
	while(p!=NULL)
	{
		if(silinecek==p->bilgi)
		break;
		p = p->arka;
	}
	if(p!=NULL){
		if(p->on==NULL && p->arka == NULL)
		{
			//p nin gösterdiði ilk deðer ve sonraki deðer boþ deðilse 
			ilk = NULL ;son = NULL;
		}
		else if (p->on==NULL && p->arka!=NULL){
			ilk = p->arka;
			ilk->on =NULL;
		}
		else if(p->on!=NULL && p->arka==NULL)
		{
			son = p->on;
			son->arka =NULL;
		}
		else //aradaki eleman için
		{
			BAGLISTE *onceki,*sonraki;
			onceki = p->on;
			sonraki = p->arka;
			onceki->arka = sonraki ;
			sonraki->on=onceki;
		}
		delete (p);
		return -1;
	}
	else
	return 0;
	
}

int ekle (BAGLISTE *ki)
{
	if(ilk!=NULL)  //ilk  eleman boþ deðilse 
	{
		son->arka = ki;
		ki->on = son;
		son = ki;
		son->arka = NULL;  //son arkayý boþa alýyoruz
	}
	
	else{
		ilk = ki;
		son = ilk; //son hem ilk olur hem de sonuncu eleman 
		ilk->on = NULL;
		ilk->arka = NULL;
	}
}

BAGLISTE *ara(int aranan)
{
	BAGLISTE *p; //yeni bir liste tanýmla 
	p = new BAGLISTE; //bellekte yer ayir 
	p = ilk; 
	while(p!=NULL){ //boþ deðilse liste 
		if(p->bilgi==aranan)
		return p; //aranan id no esitse p döndür 
		p = p->arka;  //aranýný bulmak için listede gez
	}
	return NULL ;//bulunamadýysa boþ döndür 
}

BAGLISTE *okuKlavye(){
	BAGLISTE *okunan; //hafýzada okunan için yer açýcaz
	okunan = new BAGLISTE; //BAGLISTE verisinin içerisinde bulunan veri türleri kadar yer açtýk 
	if(okunan==NULL)
	return NULL;
	cout<<"Bilgi giriniz "<<endl;
	cin>>okunan->bilgi; //id no bilgisi giricez 
	cout<<"Mesaj giriniz: \n";
	cin>>okunan->mesaj;
	okunan->on=NULL; //ilk elemanýn öndeki gösterdiði deðer boþ olucak 
	okunan->arka=NULL; //son gösterilen deðerde boþ olucak 
	return okunan;
}

