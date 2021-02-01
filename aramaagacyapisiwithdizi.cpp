#include <iostream>
#include<stdlib.h>
using namespace std;

int ara(char A[],int boyut,char aranan);

int main()
{
	char aranan;
	char A[8]={'p','g','r','b','h','q','u','a'};
	cout<<"Aranani giriniz \n";
	cin>>aranan;
	ara(A,8,aranan);
}

int ara(char A[],int boyut,char aranan)
{
	int indis=0;
	int dugum=0;
	do{
		if(A[indis]==aranan){
		    cout<<indis<<endl;
			return indis;  //bulundugu indis doner 
			break;
		}
		else
		{
			if(A[indis]<aranan)
			{
				indis = 2*dugum+1; //sol indis degeri hesaplanıyor;
				cout<<"\n sol "<<indis;
			}
			else
			{
				indis = 2*dugum+2; //sag indis degerini verir
				cout<<"\n sag "<<indis;
			}
			indis++;
			break;
		}
	}while(indis<=7);
	return -1; //bulunamazsa aranan 
}
