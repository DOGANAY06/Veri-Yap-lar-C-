#include <iostream>

#define SIZE 4
using namespace std;
struct stack
{
	int data[SIZE];
	int top =-1; //indis deðerini tutar;
};
stack stk;

void ekle(int key);

void cikar(); //diziden veri cikarir 
void reset();
void yazdir();
int main()
{
	cout<<"Stackin toplam kapasitesi "<<sizeof(stk)<<" byte  \n";
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
			cikar();
			break;
		case 'L':
			yazdir();
			break;
		case 'B':
			reset();
			break;
		case 'C':
			cout<<"Cikis yapiliyor \n";
			exit(0);
		default:
		    cout<<"Yanlis secim yapildi \n";	
		}
	}
}


void ekle(int key) //stack e ekleme yapar
{
	if(stk.top== SIZE -1)
	{
		cout<<"Stack doludur "<<endl;
	}
	else
	{
		stk.top++;
		stk.data[stk.top] = key; //elemaný koyduk
		cout<<"Stacke eleman konuldu"<<endl;
	}
}
void cikar() //diziden veri cikarir 
{
	if(stk.top == -1)
	{
		cout<<"Stack bos "<<endl;
	}
	else
	{
		cout<<stk.data[stk.top]<<"Degeri stack den cikartildi "<<endl;
		stk.top--; //cikarma islemi yapti en ustten
	}
	
}
void reset()
{
	stk.top=-1; //bos kotaya esitledik
	cout<<"Stack resetlendi"<<endl;
}
void yazdir()
{
	if(stk.top==-1)
	{
		cout<<"Stack bos"<<endl;
	}
	else
	{
		int i;
		for(i =stk.top;i>-1;i--) //elemanlarý teker teker yazdirdi
		{
			cout<<stk.data[i]<<endl;
		}
	}
}
