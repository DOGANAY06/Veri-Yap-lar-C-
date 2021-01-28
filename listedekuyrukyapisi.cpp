#include <iostream>

using namespace std;

typedef struct Dugum{
	int data;
	struct Dugum *sonraki;
}KUYRUKLISTE;

KUYRUKLISTE *ilk = NULL,*son=NULL; //dugumlerimiz

void ekle(int deger),listele(),al(),bosalt();

int main()
{
	char secim;
	int sayi;
	do{
		cout<<"Ekle = E \n Listele = L \n Al=A \n  Bosalt =B \n Cikis =Q  basiniz \n";
		cin>>secim;
		switch(secim)
		{
			case 'E':
				cout<<"Eklemek istediginiz elemani giriniz \n";
				cin>>sayi;
				ekle(sayi);
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
	if(ilk==NULL)
	{
		cout<<"Liste bos \n";
	}
	else
	{
		while(ilk!=NULL)
		{
			KUYRUKLISTE *sil ;
			sil =ilk;
			ilk= ilk->sonraki;
			delete(sil);
		}
	}
}

void listele()
{
	KUYRUKLISTE *p = new KUYRUKLISTE;
	if(ilk==NULL)
	{
		cout<<"Kuyruk bos \n ";
	}
	else
	{
		p= ilk; //ilk elemaný p ye atadýk 
		cout<<"Kuyuk elemanlari : \n";
		while(p!=NULL)
		{
			cout<<p->data<<" \n "; //elemanlar karismasin diye p den yazdirdik 
			p=p->sonraki;
		}
	}
	cout<<endl;
}

void al()
{
	if(ilk==NULL)
	{
		cout<<"Kuyruk bos \n";
	}
	else
	{
		cout<<"Alinan deger = "<<ilk->data<<endl;
		KUYRUKLISTE *temp = new KUYRUKLISTE;
		temp->data=ilk->data;
		ilk =ilk->sonraki;
		delete temp; 
	}
}

void ekle(int deger)
{
	KUYRUKLISTE *p =new KUYRUKLISTE;
	p->data=deger;
	if(ilk==NULL) //ilk eleman bossa
	{
		ilk = p ;
		son = ilk; //son eleman olmadýgý icin ilk eleman son elemanda oldu 
		ilk->sonraki =NULL;
	}
	else
	{
		son->sonraki=p; //ilk eleman degilse son elemanin sonraki dugumu yenidugum olsun
		son=p; //bu gelen elemani tekrardan yenidugum yaptim
		son->sonraki=NULL; //onun sonddaki gösterdigi degeri boþ yaptim 
	
	}
	cout<<"\n Eleman eklendi \n";
}
