#include <iostream>
#include<windows.h>
#include<string.h>
using namespace std;
struct Urunbilgi
{
	string UrunAdi;
	string kategori;
	
};
struct urunler
{
	int fiyat;
	int adet;
	struct Urunbilgi urun;

};
int main(void)
{
	urunler kola;
	urunler* adres =&kola;
	
	return 0;
}
