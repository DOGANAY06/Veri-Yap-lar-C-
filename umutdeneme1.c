#include <stdio.h>
#include<string.h>
#include <stdlib.h> //malloc fonksiyonu i�in
#define N 30
#define adet 1
typedef struct Urunbilgi
{
	char UrunAdi[N];
	char kategori[N];
	
}Urunbilgi;
typedef struct urunler
{
	int fiyat;
	int adet;
	Urunbilgi *urun; //urunbilgisinin i�aret etti�i �r�n 

}urunler;
int main(void)
{
	urunler *urunum;
	urunum=(urunler*)malloc(sizeof(urunler)*adet); //kola olan �r�n�m�ze urunler kadar haf�zada yer a�t�k
	urunum->urun=(Urunbilgi*)malloc(sizeof(Urunbilgi)*adet); //urunumuze urun bilgisi kadar haf�za yer tan�mlad�k
	urunler->urun->kategori="Icecek";
	printf("Urunumuzun kategorisi %s",Urunbilgi->kategori);
	return 0;
}
