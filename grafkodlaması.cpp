#include <iostream>
#include <string.h>
#define notVisited 1
#define visiting 2
#define visited 3

using namespace std;


struct node{
	char label[15]; //�ehirlerin ismini tutucaz 
	int counter;
	int state;	//durum tutucaz ziyaret edilme ya da edilmeme
	struct node *komsular[100]; //komsu d���mleri dizi �eklinde tutucak
	struct node *next; //s�radaki d���m i�in farkl� liste	
};

struct node *start =NULL;
struct node *last =NULL;
struct node *temp ;
struct node *onemli;
void sehirekle(char sehir[15])
{
	struct node *current = new node;
	strcpy(current->label,sehir);
	current->counter = 0;
	current->state = notVisited; //ziyaret edilmemi�
	current->state = NULL;
	
	if(start ==NULL) //ilk elemansa 
	{
		start = current;
		last = current;
	}
	else 
	{
		last->next =current; //son eleman�n sonundaki g�sterilen yere ekle 
		last = current; //sona eleman ekle 
	}
}

void harftendugum(char harf[15])
{ //gezinme i�lemi yap�caz 
	temp = start;
	while(strcmp(temp->label,harf) != 0) //son elemana geldik mi
	{
		temp = temp->next;
	}
	onemli = temp;
}

void komsuekle(char src[15],char dest[15]) //kaynak ve hedef d���m
{
	struct node *source;
	harftendugum(src);
	source = onemli; 
	struct node *destination;
	harftendugum(dest);
	destination = onemli;
	source->komsular[source->counter] = destination;
	source->counter++;
	destination->komsular[destination->counter] =source;
	destination->counter++; //��nk� bir tane kom�u olmayacak bir ��r� komsusu olabilir bu yap�n�n 
}


void sehirYazdir()
{
	temp = start;
	while(temp->next !=NULL){
		cout<<temp->label;
		temp = temp->next;
	}
	cout<<temp->label<<endl ; //son sat�r� yazd�rmas� i�in 
}
void komsuYazdir(char hedef[15])
{
	harftendugum(hedef);
	
	for(int i =0;i<onemli->counter;i++)
	{
		cout<<onemli->komsular[i]->label; //komsuyu yazd�rmak i�in 
	}
}

int main()
{
	int secim;
	char sehirharf[15];
	char sehirharfi[15];
	while(1 == 1)
	{
		cout<<"\n 1-> Sehir Ekle ---";
		cout<<"\n 2-> Sehir Yazdir ---";
		cout<<"\n 3-> Komsu  ekle ---";
		cout<<"\n 4-> Komsu  yazdir---";
		cout<<"\n Secim yapin ---";
		cin>>secim;
		
		switch(secim)
		{
			case 1:
				cout<<"\n Sehrinizini harfini giriniz ...";
				cin>>sehirharf;
				sehirekle(sehirharf);
				break;
			case 2:
				sehirYazdir();
				break;
			case 3:
				cout<<"Hangi sehri komsu eklemek istiyorsunuz = ";
				cin>>sehirharf;
				cout<<"Kac tane komsu eklemek istiyorsunuz = ";
				cin>>secim;
				sehirYazdir();
				for(int i =0;i<secim;i++)
				{
					cout<<"\n Lutfen komsuyu giriniz"<<i+1;
					cin>>sehirharfi;
					komsuekle(sehirharf,sehirharfi);
				}
				break;
			case 4:
				cout<<"\n Hangi sehrin komsularini gormek istiyorsunuz = ";
				cin>>sehirharf;
				komsuYazdir(sehirharf);
				break;
			default:
				cout<<"Hatal� tuslama yapildi \n";
		}
	}
	return 0;
}



