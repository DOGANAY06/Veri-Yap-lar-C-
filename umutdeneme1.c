#include <stdio.h>
#include<string.h>
#include <stdlib.h> //malloc fonksiyonu için
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
	Urunbilgi *urun; //urunbilgisinin iþaret ettiði ürün 

}urunler;
int main(void)
{
	urunler *urunum;
	urunum=(urunler*)malloc(sizeof(urunler)*adet); //kola olan ürünümüze urunler kadar hafýzada yer açtýk
	urunum->urun=(Urunbilgi*)malloc(sizeof(Urunbilgi)*adet); //urunumuze urun bilgisi kadar hafýza yer tanýmladýk
	urunler->urun->kategori="Icecek";
	printf("Urunumuzun kategorisi %s",Urunbilgi->kategori);
	return 0;
}
