#include <iostream>

using namespace std;

typedef struct Dugum{
	int oncelik;
	int data;
	struct Dugum *sonraki;
}ONCELIKLIKUYRUK;

ONCELIKLIKUYRUK *ilk = NULL; //dugumlerimiz

void ekle(int goncelik,int deger),listele(),al(),bosalt();

int main()
{
	char secim;
	int sayi;
	int goncelik;
	do{
		cout<<"Ekle = E \n Listele = L \n Al=A \n  Bosalt =B \n Cikis =Q  basiniz \n";
		cin>>secim;
		switch(secim)
		{
			case 'E':
				cout<<"Eklemek istediginiz elemani giriniz \n";
				cin>>sayi;
				cout<<"Eklemek istediginiz degerin onceligini giriniz \n";
				cin>>goncelik;
				ekle(goncelik,sayi);
				break;
			case 'A':
				al();
				break;
			case 'Q':
				cout<<"Cikis islemi secildi \n";
				break;
			case 'L':
				listele();
				break;
			case 'B':
				bosalt();
				break;
			default:
				cout<<"HaTALÝ SECÝM";
				break;
		}
	}while(secim!='Q');
	cout<<"Cikis yapildi iyi gunler dilerim \n";
}

void bosalt()
{
	ONCELIKLIKUYRUK *p; //gecici elemanimiz sira bozulmasin diye actik 
	if(ilk==NULL)
	{
		cout<<"Kuyruk bos \n";
	}
	else
	{
		while(ilk!=NULL)
		{
		  p=ilk;
		  ilk = ilk->sonraki;
		  delete p;	
		}
	}
	cout<<"Silme islemi tamamlandi";
}

void al()
{
	ONCELIKLIKUYRUK *p; //gecici elemanimiz sira bozulmasin diye actik 
	if(ilk==NULL)
	{
		cout<<"Kuyruk bos \n";
	}
	else
	{
		p=ilk;
		cout<<"Alinan degerin oncelik && verisi \n"<<p->oncelik<<"\t"<<p->data;
		ilk = ilk->sonraki; 
		delete p;
	}
}

void listele()
{
	ONCELIKLIKUYRUK *p = new ONCELIKLIKUYRUK;
	if(ilk==NULL)
	{
		cout<<"Kuyruk bos \n ";
	}
	else
	{
		p= ilk; //ilk elemaný p ye atadýk 
		cout<<"Kuyuk elemanlari : \n Oncelik sirasi ve bilgisi \n";
		while(p!=NULL)
		{
			cout<<p->oncelik<<" \t "<<p->data<<"\n"; //elemanlar karismasin diye p den yazdirdik 
			p=p->sonraki; //p yi artýr diðer degere gec
		}
	}
	cout<<endl;
}

void ekle(int goncelik,int deger)
{
	ONCELIKLIKUYRUK *temp,*p; //2 dugumm olusturduk 
	temp = new ONCELIKLIKUYRUK;
	temp->data=deger; //geleni tutuyoruz 
	temp->oncelik=goncelik; //gelenin onceligini tutuyoruz
	if(ilk==NULL || goncelik>ilk->oncelik)
	{
		temp->sonraki = ilk; //temp degerinin sonraki gosterdýgý deger kullanýlan ýlk deger olsun
		ilk = temp; //simdiki gelen tempde ilk deger olsun
	}
	else
	{
		p=ilk; //ilk gosterilen degeri p ye koyduk
		while(p->sonraki!=NULL && p->sonraki->oncelik >= goncelik)
		{ //p nin sonraki deger varsa bos degilse ve p nin sonraki degerinin onceligi gelen oncelikten buyuk ya da esitse
			p = p->sonraki; //p nin sonraki degeri p nin degeri oldu 
		}
		temp->sonraki = p->sonraki; //p sonraki degeri temp sonraki oldu
		p->sonraki = temp; //p nin gosterdigi deger temp yani 2 3 -> 2 5 i gibi 
		
	}
	
}


