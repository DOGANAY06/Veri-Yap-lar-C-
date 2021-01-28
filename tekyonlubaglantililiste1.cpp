#include <iostream>
#include <stdlib.h>

using namespace std;
typedef struct grup{
    int bilgi;
    char mesaj[100];
    struct grup *arka;
}BLISTE;

BLISTE *ilk = NULL ,*son=NULL;

BLISTE *girdial(); //kullanicidan listeye eleman alicaz
BLISTE *sil(int silinecek);
BLISTE *ara(int aranan);

int terscevir();
void yazekrana(BLISTE *);
int ekle(BLISTE *ki);
int listele();

int main()
{
    BLISTE *eklenecek,*ki;
    int bilgi,sonuc;
    char secim;

    while(1)
    {
        cout<<"Ekleme=E\nListeleme=L\nArama=A\nSilme=S\nCikis=C tuslarina basiniz \n Ters cevirme=T \n ";
        cin>>secim;
        switch(secim){
        case 'E':
            eklenecek = girdial();
            if(eklenecek!=NULL)
                ekle(eklenecek); //kayit ekleme fonksiyonuna gidicez
            else
                cout<<"Ekleme icin bellek dolu"<<endl;
            break;
        case 'L':
            sonuc = listele();
            if(sonuc==-1)
                cout<<"Bos liste"<<endl;
            break;
        case 'A':
            cout<<"Aramak istediiginz degeri giriniz"<<endl;
            cin>>bilgi;
            ki = ara(bilgi);
            if(ki==NULL)
                cout<<"Aranan bulunamadi \n";
            else
                yazekrana(ki);
            break;
        case 'S':
            cout<<"Sılmek istediginiz degerin bilgisini giriniz"<<endl;
            cin>>bilgi;
            ki = sil(bilgi);
            if (ki!=NULL)
                cout<<"Bılgı sılındı \n";
            else
                cout<<"Silinmek istenen yok \n ";
            break;
        case 'C':
            cout<<"Cikis islemi secildi iyi gunler"<<endl;
            break;
        case 'T':
            sonuc = terscevir();
            if(sonuc==-1)
                cout<<"Liste bos"<<endl;

            break;
        default:
            cout<<"Hatali secim"<<endl;
        }
    }
}

int ekle(BLISTE *ki) //kayit ekleme fonksiyonu
{
    if(ilk!=NULL) //ilk değer boş değilse
    {
        son->arka=ki; //gelen değeri son arkaya ekleriz
        son = ki; //sona ekleriz
        son->arka =NULL; //sonrada son arka değeri boşaltırız
    }
    else //gelen değeri ilk değere ekleriz
    {
        ilk =ki;
        son =ilk;
        ilk->arka=NULL;
    }
    return 0;
}
int listele()
{
    BLISTE *p;
    p = ilk; //listenin baþlangýç adresi p ye alýnýyor

    if (p==NULL)
        return -1;  //boþ liste
    while (p)
    {
        yazekrana(p);
        p=p->arka;
    }
    return 0;
}
void yazekrana(BLISTE *yazilacak)
{
     cout<<"bilgi= "<<yazilacak->bilgi<<"mesaj = "<<yazilacak->mesaj<<endl;
}
BLISTE *girdial()
{
    BLISTE *okunan;
    okunan =new BLISTE;
    if(okunan==NULL) //bos yer verilmedi mi kontrol
        return NULL;
    cout<<"Bilgi giriniz\n";
    cin >>okunan->bilgi;
    cout<<"Mesaj giriniz \n";
    cin >>okunan->mesaj;
    return okunan; //bilgini var olduðu adres gonderilir.
}
BLISTE *ara(int aranan)
{
    BLISTE *p;
    p = ilk;
    while(p)
    {
        if (p->bilgi==aranan) //bilgi aranan mi
            return p;
        p=p->arka; //hayir ise sonraki elemana geç
     }
     return NULL;
}
BLISTE *sil(int silinecek)
{
    BLISTE *p, *bironceki;

    p=ilk;
    bironceki = NULL;

    while(p) //silinecek olan araniyor aradki değeri bulur ve siler
     {
        if(silinecek==p->bilgi)
            break;
        bironceki = p;
        p= p->arka;
    }

    if (p!=NULL)
    {
        if(bironceki==NULL){ //silinecek olan ilk dugum mu
            if(ilk==son){ //listede yalnızca 1 dugum varsa
                ilk=NULL;
                son=NULL;
            }
            else
                ilk =ilk->arka;
        }
        else {
            bironceki->arka=p->arka;
            if(bironceki->arka==NULL)
                son=bironceki; //silinen son dugum
        }
        delete p;
        return p;
    }
    else
        return NULL;
}




