#include <iostream>
#include<string>
using namespace std;

typedef struct araclar{
	string plaka;
	string aractip;
	int fiyat;
	struct araclar *once;
	struct araclar *sonra;
}BAGLISTE;
BAGLISTE *ilk =NULL,*son =NULL;

void ekle(string plaka,string aractip,int fiyat);

void cikar(string plaka);

void yazdir();

void adet();

void ucretTopla();
int main()
{
	int fiyat;
	char secim;
	string plaka,aractip;
	do
	{
		cout<<"Otopark uygulamasina hosgeldiniz \n";
		cout<<"Otoparka arac ekleme icin =E \n Arac cikarma icin =C \n Otoparkta bulunan araclari yazdirmak icin =Y\n";
		cout<<"Araclarin toplami icin =T \n Otoparkta bulunan araclarin ucretleri toplami icin =F \n Cikis icin =Q \n";
		cin>>secim;
		switch(secim)
		{
			case 'E':
				cout<<"Aracin plakasini giriniz = \n";
				cin>>plaka;
				cout<<"Arac tipini giriniz = \n";
				cin>>aractip;
				cout<<"Arac tipine gore fiyati = \n";
				cin>>fiyat;
				ekle(plaka,aractip,fiyat);
				break;
			case 'C':
				cout<<"Otoparktan cikartilacak aracin plakasi giriniz \n";
				cin>>plaka;
				cikar(plaka);
				break;
			case 'Y':
				yazdir();
				break;
			case 'T':
				adet();
				break;
			case 'F':
				ucretTopla();
				break;
			case 'Q':
				cout<<"Otopark uygulamasi durduruldu \n";
				break;
			default:
				cout<<"Hatali secim \n" ;
			}
		}while(secim!='Q');
		cout<<"Cikis yapildi \n ";
	
}

void yazdir()
{
	if(ilk==NULL)
	{
		cout<<"Otoparkta arac yoktur \n";
	}
	else
	{
		BAGLISTE *temp =ilk;
		while(temp->sonra!=NULL)
		{ 
		//sona kadar yazicak 
			cout<<temp->plaka<<" "<<temp->aractip<<" "<<temp->fiyat<<endl;
			temp = temp->sonra;
		}
		cout<<temp->plaka<<" "<<temp->aractip<<" "<<temp->fiyat<<endl;
	}
}

void adet()
{
	int adet =0;
	if(ilk==NULL)
	{
		cout<<"Otoparkta arac yoktur \n";
	}
	else
	{
		BAGLISTE *temp =ilk;
		while(temp->sonra!=NULL)
		{ 
		//sona kadar yazicak 
			adet++;
			temp = temp->sonra;
		}
		adet++;
		cout<<"Otoparkataki arac sayi : "<<adet<<endl;	
	}
	
}
void ucretTopla()
{
	int toplam =0;
	if(ilk==NULL)
	{
		cout<<"Otoparkta arac yoktur \n";
	}
	else
	{
		BAGLISTE *temp =ilk;
		while(temp->sonra!=NULL)
		{ 
		//sona kadar yazicak 
			toplam +=temp->fiyat;
			temp = temp->sonra;
		}
		toplam += temp->fiyat;
		cout<<"Otoparkataki araclarin toplam ucreti : "<<toplam<<endl;	
	}
	
}


void cikar(string plaka)
{
	if(ilk ==NULL)
	{
		cout<<"Otopark bostur "<<endl;
		
	}
	else
	{
		if(ilk->sonra==NULL && ilk->plaka==plaka)
		{ //tek dugumse ve aranan plaka ise 
		    delete ilk;
			ilk =NULL;
			cout<<plaka<<"  plakalý arac Otoparkta kalan son arac  cikartildi ";
			//otoparktaki arac ilk aracsa
		}
		else if (ilk->sonra != NULL && ilk->plaka==plaka)
		{ //ilk elemandan sonra da eleman varsa ve ilk eleman  silinecekse 
		    BAGLISTE *temp = ilk->sonra; 
			delete ilk;
			ilk =temp; //2. eleman ilk eleman oldu
			ilk->once= NULL;	
		}
		else
		{
			BAGLISTE *temp = ilk;
			while(temp->sonra!=NULL) //ilk eleman deðilse son elemana kadar gel 
			{
				if(temp->plaka ==plaka)
				{
				    BAGLISTE *temp2 = temp->once;
					BAGLISTE *temp3 = temp->sonra;
					delete temp;
					temp2->sonra=temp3;
					temp3->once=temp2;
					cout<<plaka<<"  plakalý arac otoparktan cikartildi \n";
					break;
				}
				temp = temp->sonra;
			}
			if(temp->plaka ==plaka) //listedeki son arac icin bu iþlemi yaptýk 
				{
				    BAGLISTE *temp2 = temp->once;
					delete temp;
					temp2->sonra=NULL; //so arac oldugu için bos yaptýk
					cout<<plaka<<"  plakalý arac otoparktan cikartildi \n";
				}
		}
	}
	
}
void ekle(string plaka,string aractip,int fiyat)
{
	BAGLISTE *arac =new BAGLISTE;
	arac->plaka = plaka;
	arac->aractip =aractip;
	arac->fiyat =fiyat;
	if (ilk ==NULL) //ici bos 
	{
		ilk = arac;
		ilk->sonra=NULL;
		ilk->once= NULL;
		cout<<plaka<<" plakalý arac otoparka alindi \n";
	}
	else
	{
		arac->sonra =ilk;
		ilk->once =arac; //gelen arac ilk basa konulacak 
		ilk =arac; //ilk arac oldu 
		ilk->once = NULL;
		cout<<plaka<<" plakalý arac otoparka alindi \n";
	}
		
}
