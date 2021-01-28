#include <iostream>

using namespace std;

typedef struct dugum{
	int bilgi;
	struct dugum *sonraki;
}BAGLISTE;
BAGLISTE *ust =NULL;

void ekle(int deger);
void listele();
void al();
void bosalt();

	
int main()
{
	int sayi,sayi2;
	char secim;
	do{
		cout<<"Ekleme = E \n"<<"Listeleme = L \n"<<"Al =A \n"<<"Listeyi bosalt = B \n "<<"Cikis = Q \n"<<"Secim yapiniz \n";
		cin>>secim;
		switch(secim)
		{
			case 'E':
				cout<<"Yigina gireceginiz elemani yaziniz \n";
				cin>>sayi;
				ekle(sayi);
				break;
			case 'L':
				listele();
				break;
			case 'A':
				al();
				break;
			case 'B': //silme iþlemi secildi
			    bosalt();
				cout<<"Yigin bosaltildi: "<<endl; 
				break;
			default:
				cout<<"Hatali secim tekrar yapiniz";
				break;
		}
	}while(secim!='Q');
	cout<<"Cikis secildi iyi gunler \n";
}

void ekle(int deger)
{
	BAGLISTE *yenidugum = new BAGLISTE; //baglýste olusturduk ekleme yapmak icin
	yenidugum->bilgi = deger;	
	yenidugum->sonraki=ust; //boþ olaný atadýk 
	ust = yenidugum;
}
void al()
{
	if(ust==NULL) //gosterilen eleman bossa
	{
		cout<<"Yigin bos"<<endl;
	}
	else
	{
		cout<<"En usteki eleman = "<<ust->bilgi<<endl;
		ust=ust->sonraki; //ust bos kalaccagý için ustten bir onceki degeri uste koyduk  
		
	}
}

void listele()
{
	BAGLISTE *p;
	if(ust==NULL)
	{
		cout<<"Yigin bos";
	}
	else
	{
		p=ust;
		cout<<"Yigin elemanlari  =  \n";
		while(p!=NULL){
			cout<<p->bilgi<<" ";
			p = p->sonraki;
		}
	}
	cout<<endl;
}

void bosalt()
{
	ust->sonraki = NULL; //ustu bos yaptik 
	ust = NULL; //ustun gosterdigi degeri 
}





