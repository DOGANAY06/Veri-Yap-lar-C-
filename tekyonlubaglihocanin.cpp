
#include <iostream>
#include<stdlib.h>
using namespace std;

// listedeki veri yapD1sD1nD1n tanD1mlanmasD1
typedef struct topluluk
{

int bilgi;
   
char mesaj[100];
   
struct topluluk *arka;


} BAGLISTE;

// Listenin ilk ve son elemanlarD1nD1n adreslerini tutan iEaretC'iler
BAGLISTE * ilk = NULL, *son = NULL;

BAGLISTE * ara (int), *sil (int), *okuKlavye ();

void yazEkrana (BAGLISTE * yazilicak);
int ekle (BAGLISTE * ki);
int listele ();

int main ()
{
	   
BAGLISTE * eklenecek, *ki;
	   
int bilgi, sonuc;
	   
char secim;
	   
while (1)
{
	   
// Ekrana MenC< C'D1karD1lD1yor
	cout << endl << "Ekleme" << endl << "Listeleme" << endl << "Arama"
	<< endl;
	cout << "Silme" << endl << "Cikis" << endl << "Seciminiz ?" <<endl; 
cin >> secim; 
switch (secim) 
{
	case 'E':
	eklenecek = okuKlavye ();	//ekleme secildi
	if (eklenecek != NULL) ekle (eklenecek); 
	else
	cout << endl << "Ekleme icin bellek dolu ! " << endl; 
	break; 
	case 'L':			// listeleme seC'ildi
	sonuc = listele ();
	if (sonuc == 1) cout << endl << "Bos Liste ! " << endl; break; 
	case 'A':			// Arama secildi
	cout << endl << "Aranan: "; scanf ("%d", &bilgi);
	ki = ara (bilgi);
	if (ki == NULL) cout << endl << "Aranan Bulunamadi ! " << endl; 
	else
	yazEkrana (ki); break; 
	case 'S':			// Silme secildi
	cout << endl << "Silinecek: "; scanf ("%d", &bilgi);
	ki = sil (bilgi);
	if (ki == NULL) cout << endl << "Silindi ! " << endl; 
	else
	cout << "Silinmek istenen veri listede yok ! " << endl; break; 
	case 'C':			// CD1kD1E seC'ild
	cout << "HOSCAKAL :) " << endl; 
	exit (0); 
	default:
	   cout << "YanlD1s Secim !! " << endl; 
}
	   
}
	   
system ("pause"); 
return 0; 
}

	   
void yazEkrana (BAGLISTE * yazilacak)
	   {
	   
printf ("bilgi: %d, mesaj:%s\n", yazilacak->bilgi,
		    yazilacak->mesaj); 
} 
int ekle (BAGLISTE * ki)
	   {
	   
if (ilk != NULL) 
	   {
	   son->arka = ki; 
son = ki; 
son->arka = NULL;}
	   
	   else
	   {
	   
ilk = ki; 
son = ilk; 
ilk->arka = NULL; 
}
	   
return 0; 
}

	   
int listele ()
	   {
	   
BAGLISTE * p; 
p = ilk; 
if (p == NULL) return -1;
	   
while (p != NULL)
	   {
	   
yazEkrana (p); 
p = p->arka; 
}
	   
return 0; 
}

	   
BAGLISTE * ara (int aranan) 
{

BAGLISTE * p; p = ilk; 
while (p != NULL)
	   
{
if (p->bilgi == aranan) return p; 
p = p->arka;
}

return NULL; 
}

	   
BAGLISTE * sil (int silinecek) 
{	   

BAGLISTE * p, *bironceki; p = ilk; 
bironceki = NULL;
	   
while (p != NULL)
{
		
if (silinecek == p->bilgi) break; 
bironceki = p;
p = p->arka;


}
	   
if (p != NULL)
	   {
	   
if (bironceki == NULL)
	   {
	   
if (ilk == son)
	   {
	   
ilk == NULL; son == NULL; 
}
	   
	   else
	   ilk = ilk->arka; 
}
	   
	   else
	   {
	   bironceki->arka = p->arka;
	   
if (bironceki->arka == NULL) son = bironceki;}
	   
free (p); return p;}
	   
	   else
	   return NULL; 
}

	   
BAGLISTE * okuKlavye ()
{	   
BAGLISTE * okunan; 
okunan = new BAGLISTE; 
if (okunan == NULL) 
	return NULL; 
	cout << "Bilgi Giriniz" << endl;
	scanf ("%d", &(okunan->bilgi)); 
	cout << "Mesaj Giriniz" << endl;
	scanf ("%s", &(okunan->mesaj)); 

return okunan; 
}

