#include <iostream>
#include<stdlib.h>
using namespace std;

typedef struct topluluk {
	int bilgi;
	struct topluluk *arka;
}BAGLISTE;


int boyut=10;
// HASH DÝZÝSÝ
BAGLISTE *HASHDIZI[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}; 
BAGLISTE *ara(int), *sil(int);
BAGLISTE *okuKlavye();
int hash(int val);//void hash_kur();
void yazEkrana(BAGLISTE *yazilicak);
void ekle(BAGLISTE *ki);
void listele();

int main()
{

BAGLISTE *eklenecek, *ki;
int bilgi, sonuc;
char secim;
while(1){

	// Ekrana Menü çýkarýlýyor
	cout<<endl<<"Ekleme"<<endl<<"Listeleme"<<endl<<"Arama"<<endl<<"Silme"<<endl<<"Cikis"<<endl<<"Seciminiz ?"<<endl;
	cin>>secim;
	switch(secim)
	{
	
	case 'E':
	{
		eklenecek=okuKlavye(); //ekleme secildi
		if (eklenecek!=NULL) ekle(eklenecek);
		else cout<<endl<<"Ekleme icin bellek dolu ! "<<endl;
		break;
	}
	case 'L':// listeleme seçildi
	{
		listele();
		//if (sonuc==1) cout<<endl<<"Bos Liste ! "<<endl;
		break;
	}
	case 'A': // Arama secildi
	{
		cout<<endl<<"Aranan: ";
		scanf("%d",&bilgi);
		ki=ara(bilgi);
		if (ki==NULL) cout<<endl<<"Aranan Bulunamadi ! "<<endl;
		else yazEkrana(ki);
		break;
	}
		case 'S': // Silme secildi
	{
		cout<<endl<<"Silinecek: ";
		scanf("%d",&bilgi);
		ki=sil(bilgi);
		if (ki!=NULL) cout<<endl<<"Silindi ! "<<endl;
		else cout<<"Silinmek istenen veri listede yok ! "<<endl;
		break;
	}
	case 'C':// Çýkýþ seçildi
	{
		cout<<"HOSCAKAL :) "<<endl;
		exit(0);
		
	}
	default:cout<<"Yanlýs Secim !! "<<endl;
}
}

system("pause");
return 0;
}

// fonksiyonlar
void yazEkrana(BAGLISTE *yazilacak){
	printf(" %d ",yazilacak->bilgi);
}

void ekle(BAGLISTE *ki){
	
	int indis=hash(ki->bilgi); //gelen bilgiyi hashe gönderiyoruz modunu alýyor 10 a göre
    BAGLISTE *p = HASHDIZI[indis]; //HASHDÝZÝsinin indis degeri kaçýncý düðüm olduðunu veriyor
    if (p == NULL) {
        HASHDIZI[indis] = ki; //GELEN DEGERÝ hashdizisine ekliyoruz
        return;
    } 
    else
    {
    	BAGLISTE *ilk = HASHDIZI[indis];  //BAGLISTEye gelen HASHDÝZÝSÝ indis ekliyoruz
    	ki->arka=ilk;     //ilk deger 2 deger oldu
    	HASHDIZI[indis]=ki; //HASH dizisinin belirlenen moduna eklendi 
    	return;
	}
	// ARKAYA EKLEME
    //while(p->arka != NULL) {
    //    p = p->arka; 
    //}
    //p->arka = ki;
}


void listele(){
	BAGLISTE *p;
	p=new BAGLISTE;
for (int i=0;i<boyut;i++)
{
	p=HASHDIZI[i];if(p!=NULL) cout<<endl; //aslýnda dügümü deðilde hash dizinin ilk indisinde bulunaný yazdýrýr.
	while(p!=NULL){
	yazEkrana(p);cout<<"-->";
	p=p->arka;}
}
}


BAGLISTE *ara(int aranan)
{
	BAGLISTE *p;
	p = new BAGLISTE;
	int indis=hash(aranan); //aranan degeri hash e gönderiyoruz modunu alýyor bu bizim indisimiz 
	p = HASHDIZI[indis];  //indis degerimizi dügüme atýyoruz
	while(p!=NULL){ //dügüm boþ olana kadar döngü çalýþýyor
		if(p->bilgi==aranan) return p; //aranan düðümün elemanlarýndan birine esitse bitiryor
		p=p->arka;
	}
	return NULL; 
	delete(p);
}

BAGLISTE *sil(int silinecek)
{
	BAGLISTE *p, *bironceki;
	p = new BAGLISTE;
	bironceki = new BAGLISTE;
	int indis=hash(silinecek);
	p = HASHDIZI[indis];
	bironceki=NULL;
	
	while(p!=NULL){
		if(silinecek==p->bilgi) break;
		bironceki=p;
		p=p->arka;
	}
	
	if (p!=NULL){
		if(bironceki==NULL){
			if (p->arka==NULL)
			HASHDIZI[indis]=NULL;
			else
			HASHDIZI[indis]=p->arka;
		}
		else{
			bironceki->arka=p->arka;
		}
		return p;
	}
	else
	return NULL;
}


BAGLISTE *okuKlavye(){ //elemani dügüme ekliyoruz
	BAGLISTE *okunan;
	okunan=new BAGLISTE;
	if (okunan==NULL)
	return NULL;
	cout<<"Bilgi Giriniz"<<endl;
	scanf("%d",&(okunan->bilgi));
	okunan->arka=NULL;
	return okunan;
	
}
int hash(int val){
	int ind=val%10;
	return ind;
}
